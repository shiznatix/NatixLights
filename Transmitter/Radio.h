#ifndef Radio_h
#define Radio_h

#include <SPI.h>
#include <RH_RF69.h>
#include <RHReliableDatagram.h>
#include "Debug.h"

class Radio {
	public:
		Radio();
		bool setup();
		char receive();
		bool send(char status);
		void resetReceiveTimeoutTimer();
		bool isReceiveTimeout();

	private:
		const int MY_ADDRESS = 2;
		const int DEST_ADDRESS = 1;
		const int RF69_FREQ = 433.0;
		const int RFM69_CS = 8;
		const int RFM69_INT = 3;
		const int RFM69_RST = 4;
		const int POWER = 20;
		const int RETRY_COUNT = 0;
		const int SEND_TIMEOUT = 100;

		const String SIGNAL_PREFIX = "Signal";

		uint8_t ENCRYPTION_KEY[16] = {
			194, 81, 70, 225, 190, 197, 123, 157, 90, 202, 52, 129, 125, 178, 97, 85
		};
		
		RH_RF69 mRf69;
		RHReliableDatagram mRf69Manager;

		uint8_t mReadBuffer[RH_RF69_MAX_MESSAGE_LEN];

		// timers
		const unsigned int SEND_DELAY = 500;// milliseconds
		const unsigned int RECEIVE_TIMEOUT = 3000;// milliseconds
		unsigned long mSendTimer = 0;
		unsigned long mReceiveTimeoutTimer = 0;
};

#endif
