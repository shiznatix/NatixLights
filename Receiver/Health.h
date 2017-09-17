#ifndef Health_h
#define Health_h

#include "Arduino.h"

class Health {
	public:
		// radio send
		static const char BATTERY_NORMAL = '1';
		static const char BATTERY_LOW = '2';

		Health(int ledPin);
		void setup();
		bool isLowBattery();
		void setIndicator(bool isLowBattery);

	private:
		// battery
		const int BATTERY_PIN = 9;
		const float BATTERY_LOW_VOLTAGE = 3.4;

		// timers
		const unsigned int LOW_BATTERY_BLINK_DELAY = 1000;// milliseconds
		unsigned long mLowBatteryTimer = 0;

		int mLedPin;
};

#endif
