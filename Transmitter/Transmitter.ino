#include "Debug.h"
#include "Radio.h"
#include "Switches.h"
#include "StatusLights.h"

const boolean DEBUG = false;

// // battery
const int BATTERY_PIN = 9;
const float BATTERY_LOW_VOLTAGE = 3.4;

Radio radio;
Switches switches(A1, A3, A4, A5, A0);
StatusLights statusLights(10, 2);

void setup() {
	Debug::setup(DEBUG);

	radio.setup();
	statusLights.setup();

	// setup battery
	pinMode(BATTERY_PIN, INPUT);
}

void loop() {
	uint32_t startTime = millis();

	char switchStatus = switches.getStatus();
	char received = radio.receive();

	if (statusLights.isValidReceiverStatus(received)) {
		statusLights.setReceiverStatus(received);
		radio.resetReceiveTimeoutTimer();
	} else if (radio.isReceiveTimeout()) {
		statusLights.setReceiverStatus(StatusLights::RECEIVER_NO_STATUS);
	}
	
	statusLights.setSwitchStatus(switchStatus);
	statusLights.setSelfLowBattery(isLowBattery());
	statusLights.loop();

	radio.send(switchStatus);

	Debug::print("loop time: ");
	Debug::println((millis() - startTime));

	delay((DEBUG ? 200 : 1));
}

bool isLowBattery() {
	// convert to voltage
	float myBattery = analogRead(BATTERY_PIN) * 2 * 3.3 / 1024;
	return (myBattery <= BATTERY_LOW_VOLTAGE);
}