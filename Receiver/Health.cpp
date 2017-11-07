#include "Health.h"

Health::Health(int ledPin, int batteryPin) {
	mLedPin = ledPin;
	mBatteryPin = batteryPin;
}

void Health::setup() {
	// setup battery
	pinMode(mBatteryPin, INPUT);

	// Setup health indicator
	pinMode(mLedPin, OUTPUT);
	analogWrite(mLedPin, 255);
}

bool Health::isLowBattery() {
	int battery = analogRead(mBatteryPin);

	return (battery < 500);
}

void Health::setIndicator(bool isLowBattery) {
	if (isLowBattery) {
		unsigned long currentTime = millis();
		unsigned long timeSinceLowBatteryRefresh = currentTime - mLowBatteryTimer;

		if (LOW_BATTERY_BLINK_DELAY < timeSinceLowBatteryRefresh) {
			bool isOn = digitalRead(mLedPin);

			analogWrite(mLedPin, (isOn ? 0 : 255));

			// reset our timer
			mLowBatteryTimer = currentTime;
		}
	} else {
		analogWrite(mLedPin, 255);
	}
}
