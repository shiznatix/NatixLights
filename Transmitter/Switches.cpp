#include "Switches.h"

Switches::Switches(int leftTurnPin, int rightTurnPin, int leftStopPin, int rightStopPin, int buttonPin) {
	mLeftTurnPin = leftTurnPin;
	mRightTurnPin = rightTurnPin;
	mLeftStopPin = leftStopPin;
	mRightStopPin = rightStopPin;
	mButtonPin = buttonPin;
}

char Switches::getStatus() {
	int leftTurnSignal = analogRead(mLeftTurnPin);
	int rightTurnSignal = analogRead(mRightTurnPin);
	int leftStopSignal = analogRead(mLeftStopPin);
	int rightStopSignal = analogRead(mRightStopPin);
	int buttonSignal = analogRead(mButtonPin);

	Debug::print("leftTurnSignal: ");
	Debug::print(leftTurnSignal);
	Debug::print(" - rightTurnSignal: ");
	Debug::print(rightTurnSignal);
	Debug::print(" - leftStopSignal: ");
	Debug::print(leftStopSignal);
	Debug::print(" - rightStopSignal: ");
	Debug::print(rightStopSignal);
	Debug::print(" - buttonSignal: ");
	Debug::println(buttonSignal);

	if (leftStopSignal < SIGNAL_THRESHOLD || rightStopSignal < SIGNAL_THRESHOLD) {
		if (leftTurnSignal > SIGNAL_THRESHOLD) {
			return STATUS_STOP_LEFT_TURN;
		} else if (rightTurnSignal > SIGNAL_THRESHOLD) {
			return STATUS_STOP_RIGHT_TURN;
		}

		return STATUS_STOP;
	} else if (leftTurnSignal > SIGNAL_THRESHOLD) {
		return STATUS_LEFT_TURN;
	} else if (rightTurnSignal > SIGNAL_THRESHOLD) {
		return STATUS_RIGHT_TURN;
	} else if (buttonSignal > SIGNAL_THRESHOLD) {
		return STATUS_BUTTON;
	}

	return STATUS_CAUTION;
}