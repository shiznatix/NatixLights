#include "Debug.h"
#include "Radio.h"
#include "Lights.h"
#include "Health.h"

const boolean DEBUG = false;

Radio radio;
Lights lights(5, 12);
Health health(A5);

void setup() {
	Debug::setup(DEBUG);

	lights.setup();
	radio.setup();
	health.setup();
}

void loop() {
	uint32_t startTime = millis();

	// get a message, maybe
	char received = radio.receive();
	bool isValidAnimation = lights.isValidAnimation(received);
	bool isLowBattery = health.isLowBattery();
	char healthMessage = (isLowBattery ? health.BATTERY_LOW : health.BATTERY_NORMAL);

	lights.loop();
	health.setIndicator(isLowBattery);
	radio.sendHealthMessage(healthMessage);

	if (isValidAnimation) {
		lights.setupIfNewAnimation(received);
		radio.resetReceiveTimer();
	} else if (radio.isReceiveTimeout()) {
		lights.setupIfNewAnimation(lights.ANIM_CAUTION);
	}

	Debug::print("Loop time: ");
	Debug::println((millis() - startTime));

	delay((DEBUG ? 200 : 1));

	// lights.setupIfNewAnimation(lights.ANIM_CAUTION);
	// lights.setupIfNewAnimation(lights.ANIM_STOP);
	// lights.setupIfNewAnimation(lights.ANIM_HAPPY);
	// lights.loop();
}
