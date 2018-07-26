#include "Debug.h"
#include "Radio.h"
#include "Lights.h"
#include "Health.h"

const boolean DEBUG = false;
const int DEBUG_LEVEL = Debug::INFO;
const boolean BATTERY_LEVEL_MODE = false;

Radio radio;
Lights lights(5, 12);
Health health(A5, A2);

void setup() {
	Debug::setup(DEBUG, DEBUG_LEVEL);

	lights.setup();
	radio.setup();
	health.setup();

	// lights.setBrightness(100);
	lights.setBrightness(50);
}

void loop() {
	uint32_t startTime = millis();

	if (BATTERY_LEVEL_MODE) {
		batteryLevelMode();
	} else {
		receiverMode();
	}

	Debug::print("Loop time: ");
	Debug::println((millis() - startTime));

	delay((DEBUG ? 200 : 1));
}

void receiverMode() {
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

	// lights.setupIfNewAnimation(lights.ANIM_CAUTION);
	// lights.setupIfNewAnimation(lights.ANIM_STOP);
	// lights.setupIfNewAnimation(lights.ANIM_HAPPY);
	// lights.setupIfNewAnimation(lights.ANIM_LEFT_TURN);
	// lights.setupIfNewAnimation(lights.ANIM_RIGHT_TURN);
	// lights.loop();
}

void batteryLevelMode() {
	// If we are measuring the voltage from pin 9 on the Feather
	// float voltage = health.getBatteryVoltage();

	// int wholeDigit = (int)voltage;
	// int decimal = voltage * 1000;
	// char decimalString[16];
	// itoa(decimal, decimalString, 10);
	// int decimalHundreds = decimalString[1] - '0';
	// int decimalTens = decimalString[2] - '0';

	// lights.setupBatteryIndicator(wholeDigit, decimalHundreds, decimalTens);
	// lights.loop();

	lights.setupIfNewAnimation(Lights::ANIM_CUSTOM);

	if (health.isLowBattery()) {
		lights.setPixelColor(0, lights.getColor(r));
	} else {
		lights.setPixelColor(0, lights.getColor(g));
	}

	lights.loop();
}
