#include "Health.h"

Health::Health(int ledPin) {
	mLedPin = ledPin;
}

void Health::setup() {
	// setup battery
	pinMode(BATTERY_PIN, INPUT);

	// Setup health indicator
	pinMode(mLedPin, OUTPUT);
	analogWrite(mLedPin, 255);
}

bool Health::isLowBattery() {
	// convert to voltage
	float batteryVoltage = analogRead(BATTERY_PIN) * 2 * 3.3 / 1024;
	
	return (batteryVoltage <= BATTERY_LOW_VOLTAGE);
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
