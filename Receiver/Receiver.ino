// #include "Globals.h"
#include "Debug.h"
#include "Radio.h"
#include "Lights.h"
#include "Health.h"

const boolean DEBUG = true;

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
	// get a message, maybe
	// char received = radio.receive();
	// bool isValidAnimation = lights.isValidAnimation(received);
	// bool isLowBattery = health.isLowBattery();
	// char healthMessage = (isLowBattery ? health.BATTERY_LOW : health.BATTERY_NORMAL);

	// lights.loop();
	// health.setIndicator(isLowBattery);
	// radio.sendHealthMessage(healthMessage);

	// if (isValidAnimation) {
	// 	lights.setupIfNewAnimation(received);
	// 	radio.resetReceiveTimer();
	// } else if (radio.isReceiveTimeout()) {
	// 	lights.setupIfNewAnimation(lights.ANIM_CAUTION);
	// }

	// delay(200);

	// lights.setupIfNewAnimation(lights.ANIM_LEFT_TURN);
	// lights.loop();
	// delay(1000);
	// lights.setupIfNewAnimation(lights.ANIM_STOP_LEFT_TURN);
	// lights.loop();
	// delay(1000);
	// lights.setupIfNewAnimation(lights.ANIM_RIGHT_TURN);
	// lights.loop();
	// delay(1000);
	// lights.setupIfNewAnimation(lights.ANIM_STOP_RIGHT_TURN);
	// lights.loop();
	// delay(1000);
	// lights.setupIfNewAnimation(lights.ANIM_STOP);
	// lights.loop();
	// delay(1000);
	lights.setupIfNewAnimation(lights.ANIM_HAPPY);
	lights.loop();
	delay(1000);
}
