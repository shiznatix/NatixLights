#ifndef Switches_h
#define Switches_h

#include "Debug.h"

class Switches {
	public:
		static constexpr char STATUS_CAUTION = '1';
		static constexpr char STATUS_LEFT_TURN = '2';
		static constexpr char STATUS_RIGHT_TURN = '3';
		static constexpr char STATUS_STOP = '4';
		static constexpr char STATUS_BUTTON = '5';
		static constexpr char STATUS_STOP_LEFT_TURN = '6';
		static constexpr char STATUS_STOP_RIGHT_TURN = '7';

		const int SIGNAL_THRESHOLD = 255;
		
		Switches(int leftTurnPin, int rightTurnPin, int leftStopPin, int rightStopPin, int buttonPin);
		char getStatus();

	private:
		int mLeftTurnPin;
		int mRightTurnPin;
		int mLeftStopPin;
		int mRightStopPin;
		int mButtonPin;
};

#endif
