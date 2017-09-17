#ifndef Lights_h
#define Lights_h

#include <Adafruit_DotStar.h>
#include "Animations.h"

class Lights {
	public:
		// setup our animation types
		static constexpr char ANIM_NONE = '0';
		static constexpr char ANIM_CAUTION = '1';
		static constexpr char ANIM_LEFT_TURN = '2';
		static constexpr char ANIM_RIGHT_TURN = '3';
		static constexpr char ANIM_STOP = '4';
		static constexpr char ANIM_HAPPY = '5';
		static constexpr char ANIM_STOP_LEFT_TURN = '6';
		static constexpr char ANIM_STOP_RIGHT_TURN = '7';

		Lights(int dataPin, int clockPin);
		void setup();
		bool isValidAnimation(const char animation);
		void setupIfNewAnimation(const char animation);
		void reset();
		void loop();

	private:
		const int MAX_COLOR = 10;
		const unsigned int PIXEL_REFERSH_DELAY = 200;// milliseconds, maximum value must be the lowest blink/frame delay value
		const unsigned int BLINK_DELAY = 500;// milliseconds
		const unsigned int FRAME_DELAY = 200;// milliseconds

		char mCurrentAnimation = ANIM_CAUTION;
		boolean mIsBlinking = false;
		byte mCurrentAnimFrame = 0;
		Adafruit_DotStar mLedStrip;

		// timers
		unsigned long mRefreshPixelsTimer = 0;
		unsigned long mBlinkTimer = 0;
		unsigned long mFrameTimer = 0;

		void _updateIsBlinking(unsigned long &currentTime);
		void _updateCurrentAnimFrame(unsigned long &currentTime);
		uint32_t _getColor(const char &colorChar);
		void _image(const char image[PIXEL_COUNT]);
		void _blinkImage(const char image[PIXEL_COUNT]);
		void _blank();
};

#endif
