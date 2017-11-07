#ifndef Health_h
#define Health_h

#include "Arduino.h"

class Health {
	public:
		// radio send
		static const char BATTERY_NORMAL = '1';
		static const char BATTERY_LOW = '2';

		Health(int ledPin, int batteryPin);
		void setup();
		bool isLowBattery();
		void setIndicator(bool isLowBattery);

	private:
		// timers
		const unsigned int LOW_BATTERY_BLINK_DELAY = 1000;// milliseconds
		unsigned long mLowBatteryTimer = 0;

		int mLedPin;
		int mBatteryPin;
};

#endif
