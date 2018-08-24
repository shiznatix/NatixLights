#include "Radio.h"

Radio::Radio() :
	mRf69(RFM69_CS, RFM69_INT),
	mRf69Manager(mRf69, MY_ADDRESS) {
}

bool Radio::setup() {
	pinMode(RFM69_RST, OUTPUT);
	digitalWrite(RFM69_RST, LOW);

	// manual reset
	digitalWrite(RFM69_RST, HIGH);
	delay(10);
	digitalWrite(RFM69_RST, LOW);
	delay(10);

	if (!mRf69Manager.init()) {
		return false;
	}
	
	if (!mRf69.setFrequency(RF69_FREQ)) {
		return false;
	}

	mRf69.setTxPower(POWER, true);

	mRf69Manager.setRetries(RETRY_COUNT);
	mRf69Manager.setTimeout(SEND_TIMEOUT);

	mRf69.setEncryptionKey(ENCRYPTION_KEY);

	return true;
}

bool Radio::send(char status) {
	bool sendSuccess = false;

	if (SEND_DELAY < (millis() - mSendTimer)) {
		char sendBuffer[RH_RF69_MAX_MESSAGE_LEN];
		unsigned int signalPrefixLength = SIGNAL_PREFIX.length();
		
		SIGNAL_PREFIX.toCharArray(sendBuffer, (signalPrefixLength + 1));
		sendBuffer[signalPrefixLength] = status;
		sendBuffer[signalPrefixLength + 1] = '\0';

		// don't build all the strings if we don't need to
		if (Debug::IS_DEBUG) {
			Debug::print("Time: ");
			Debug::print(millis());
			Debug::print(" Prefix: '");
			Debug::print(SIGNAL_PREFIX);
			Debug::print("' Status: '");
			Debug::print(status);
			Debug::print("' Sending: '");
			Debug::print(sendBuffer);
			Debug::println("'");
		}

		uint8_t sendBufferLength = sizeof(sendBuffer);

		if (mRf69Manager.sendtoWait((uint8_t *)sendBuffer, sendBufferLength, DEST_ADDRESS)) {
			sendSuccess = true;
		}

		Debug::println((sendSuccess ? "Message sent" : "Message sending failed (no ack)"), Debug::INFO);

		// reset our timer regardless of success
		mSendTimer = millis();
	}

	return sendSuccess;
}

char Radio::receive() {
	uint8_t messageFrom;
	uint8_t readBufferlength = sizeof(mReadBuffer);

	if (mRf69Manager.recvfromAck(mReadBuffer, &readBufferlength, &messageFrom)) {
		mReadBuffer[readBufferlength] = 0; // zero out remaining string

		Debug::print("Received: '");
		Debug::print((char*)mReadBuffer);
		Debug::println("'");

		String received = String((char*)mReadBuffer);

		if (received.startsWith(SIGNAL_PREFIX)) {
			char receiverBattery = received.charAt(SIGNAL_PREFIX.length());

			return receiverBattery;
		}
	}

	return '\0';
}

void Radio::resetConnectionTimeout() {
	Debug::println("resetConnectionTimeout", Debug::INFO);
	mConnectionTimeoutTimer = millis();
	mConnectionTimedOut = false;
}

bool Radio::isConnectionTimeout() {
	unsigned long currentTime = millis();

	// make sure we haven't timed out yet.
	unsigned long timeSinceLastSignal = currentTime - mConnectionTimeoutTimer;
	
	if (CONNECTION_TIMEOUT < timeSinceLastSignal) {
		Debug::println("Radio timeout", Debug::INFO);

		mConnectionTimeoutTimer = millis();
		mConnectionTimedOut = true;
	}

	return mConnectionTimedOut;
}