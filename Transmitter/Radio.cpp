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

bool Radio::send(char status) {
	if (SEND_DELAY < (millis() - mSendTimer)) {
		bool sendSuccess = false;
		char sendBuffer[RH_RF69_MAX_MESSAGE_LEN];
		SIGNAL_PREFIX.toCharArray(sendBuffer, (SIGNAL_PREFIX.length() + 1));
		sendBuffer[SIGNAL_PREFIX.length()] = status;

		Debug::print("Sending: ");
		Debug::println(sendBuffer);

		uint8_t sendBufferLength = sizeof(sendBuffer);

		if (mRf69Manager.sendtoWait((uint8_t *)sendBuffer, sendBufferLength, DEST_ADDRESS)) {
			sendSuccess = true;
		}

		Debug::println((sendSuccess ? "Message sent" : "Message sending failed (no ack)"));

		// reset our timer regardless of success
		mSendTimer = millis();

		return sendSuccess;
	}

	return true;
}

void Radio::resetReceiveTimeoutTimer() {
	mReceiveTimeoutTimer = millis();
}

bool Radio::isReceiveTimeout() {
	unsigned long currentTime = millis();

	// make sure we haven't timed out yet.
	unsigned long timeSinceLastSignal = currentTime - mReceiveTimeoutTimer;
	
	if (RECEIVE_TIMEOUT < timeSinceLastSignal) {
		Debug::println("Radio timeout");

		resetReceiveTimeoutTimer();
		return true;
	}

	return false;
}