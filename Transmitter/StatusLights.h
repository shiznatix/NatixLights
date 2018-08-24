#ifndef StatusLights_h
#define StatusLights_h

#include "NeoPatterns.h"
#include "Switches.h"
#include "Debug.h"

class StatusLights {
	public:
		static char constexpr RECEIVER_NO_CONNECTION = '0';
		static char constexpr RECEIVER_BATTERY_NORMAL = '1';
		static char constexpr RECEIVER_BATTERY_LOW = '2';

		StatusLights(int dataPin, int pixelCount);
		void setup();
		void setSwitchStatus(char switchStatus);
		void setSelfLowBattery(bool selfLowBattery);
		void setReceiverStatus(char receiverStatus);
		bool isValidReceiverStatus(char receiverStatus);
		void loop();

	private:
		const byte MAX_COLOR = 100;
		uint32_t COLOR_RED;
		uint32_t COLOR_GREEN;
		uint32_t COLOR_BLUE;
		uint32_t COLOR_PURPLE;
		uint32_t COLOR_YELLOW;
		uint32_t COLOR_WHITE;
		uint32_t COLOR_OFF;

		NeoPatterns mNeoPixels;
		char mReceiverStatus = RECEIVER_NO_CONNECTION;
		bool mSelfLowBattery = false;
		char mSwitchStatus = Switches::STATUS_CAUTION;
		uint32_t mColors[2];

		void _setColors();
};

#endif
