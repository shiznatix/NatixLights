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
	Debug::setup(DEBUG, Debug::INFO);

	radio.setup();
	statusLights.setup();

	// setup battery
	pinMode(BATTERY_PIN, INPUT);
}

void loop() {
	uint32_t startTime = millis();

	char switchStatus = switches.getStatus();
	char received = radio.receive();

	if (radio.send(switchStatus)) {
		radio.resetConnectionTimeout();
	}

	if (radio.isConnectionTimeout()) {
		statusLights.setReceiverStatus(StatusLights::RECEIVER_NO_CONNECTION);
	} else if (statusLights.isValidReceiverStatus(received)) {
		statusLights.setReceiverStatus(received);
	}
	
	statusLights.setSwitchStatus(switchStatus);
	statusLights.setSelfLowBattery(isLowBattery());
	statusLights.loop();

	Debug::print("loop time: ");
	Debug::println((millis() - startTime));

	delay((DEBUG ? 20 : 1));
}

bool isLowBattery() {
	// convert to voltage
	float myBattery = analogRead(BATTERY_PIN) * 2 * 3.3 / 1024;
	return (myBattery <= BATTERY_LOW_VOLTAGE);
}