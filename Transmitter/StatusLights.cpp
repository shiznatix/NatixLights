#include "StatusLights.h"
#include "Switches.h"

StatusLights::StatusLights(int dataPin, int pixelCount) :
	mNeoPixels(pixelCount, dataPin, NEO_GRB + NEO_KHZ800) {

	COLOR_RED = mNeoPixels.Color(MAX_COLOR, 0, 0);
	COLOR_GREEN = mNeoPixels.Color(0, MAX_COLOR, 0);
	COLOR_BLUE = mNeoPixels.Color(0, 0, MAX_COLOR);
	COLOR_PURPLE = mNeoPixels.Color(MAX_COLOR, 0, MAX_COLOR);
	COLOR_YELLOW = mNeoPixels.Color(MAX_COLOR, MAX_COLOR, 0);
	COLOR_WHITE = mNeoPixels.Color(MAX_COLOR, MAX_COLOR, MAX_COLOR);
	COLOR_OFF = mNeoPixels.Color(0, 0, 0);

	mColors[0] = COLOR_OFF;
	mColors[1] = COLOR_OFF;
}

void StatusLights::setup() {
	mNeoPixels.begin();
	mNeoPixels.off();
	mNeoPixels.show();
}

void StatusLights::setSwitchStatus(char switchStatus) {
	mSwitchStatus = switchStatus;

	_setColors();
}

void StatusLights::setSelfLowBattery(bool selfLowBattery) {
	mSelfLowBattery = selfLowBattery;
}

void StatusLights::setReceiverStatus(char receiverStatus) {
	mReceiverStatus = receiverStatus;
}

bool StatusLights::isValidReceiverStatus(char receiverStatus) {
	switch (receiverStatus) {
		case RECEIVER_BATTERY_NORMAL:
		case RECEIVER_BATTERY_LOW:
			return true;
	}

	return false;
}

void StatusLights::loop() {
	bool receiverLowBattery = (RECEIVER_BATTERY_LOW == mReceiverStatus);
	bool receiverNoResponse = (RECEIVER_NO_STATUS == mReceiverStatus);

	if (mSelfLowBattery && receiverLowBattery) {
		mNeoPixels.blink(mColors[0], mColors[1], 1000);
	} else if (mSelfLowBattery && receiverNoResponse) {
		mNeoPixels.fade(COLOR_RED, COLOR_YELLOW, 70, 10, FORWARD);
	} else if (receiverNoResponse) {
		mNeoPixels.rainbowCycle(10, FORWARD);
	} else if (receiverLowBattery) {
		mNeoPixels.flash(mColors[0], mColors[1], 10, 100, FORWARD);
	} else if (mSelfLowBattery) {
		mNeoPixels.flash(mColors[0], mColors[1], 5, 1000, FORWARD);
	} else {
		mNeoPixels.stopPattern();
		mNeoPixels.setPixelColor(0, mColors[0]);
		mNeoPixels.setPixelColor(1, mColors[1]);
		mNeoPixels.show();
	}

	mNeoPixels.loop();
}

void StatusLights::_setColors() {
	switch (mSwitchStatus) {
		case Switches::STATUS_LEFT_TURN:
			mColors[0] = COLOR_BLUE;
			mColors[1] = COLOR_OFF;
			break;
		case Switches::STATUS_STOP_LEFT_TURN:
			mColors[0] = COLOR_RED;
			mColors[1] = COLOR_OFF;
			break;
		case Switches::STATUS_RIGHT_TURN:
			mColors[0] = COLOR_OFF;
			mColors[1] = COLOR_BLUE;
			break;
		case Switches::STATUS_STOP_RIGHT_TURN:
			mColors[0] = COLOR_OFF;
			mColors[1] = COLOR_RED;
			break;
		case Switches::STATUS_STOP:
			mColors[0] = COLOR_RED;
			mColors[1] = COLOR_RED;
			break;
		case Switches::STATUS_BUTTON:
			mColors[0] = COLOR_YELLOW;
			mColors[1] = COLOR_YELLOW;
			break;
		default:
			mColors[0] = COLOR_GREEN;
			mColors[1] = COLOR_GREEN;
			break;
	}
}
