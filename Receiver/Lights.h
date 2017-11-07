#ifndef Lights_h
#define Lights_h

#include "NeoPatterns.h"
#include "Animations.h"

class Lights {
	public:
		// setup our animation types
		static constexpr char ANIM_NONE = '-1';
		static constexpr char ANIM_CUSTOM = '0';
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
		void setupBatteryIndicator(int wholeDigit, int decimalHundreds, int decimalTens);
		void setPixelColor(int pixel, uint32_t color);
		void blank();
		uint32_t getColor(const char &colorChar);
		void reset();
		void loop();

	private:
		const int MAX_COLOR = 70;
		const unsigned int PIXEL_REFERSH_DELAY = 150;// milliseconds, maximum value must be the lowest blink/frame delay value
		const unsigned int BLINK_DELAY = 500;// milliseconds
		const unsigned int FRAME_DELAY = 150;// milliseconds

		char mCurrentAnimation = ANIM_CAUTION;
		boolean mIsBlinking = false;
		byte mCurrentAnimFrame = 0;
		NeoPatterns mNeoPatterns;

		// timers
		unsigned long mRefreshPixelsTimer = 0;
		unsigned long mBlinkTimer = 0;
		unsigned long mFrameTimer = 0;

		void _updateIsBlinking(unsigned long &currentTime);
		void _updateCurrentAnimFrame(unsigned long &currentTime);
		void _image(const char image[PIXEL_COUNT]);
		void _blinkImage(const char image[PIXEL_COUNT]);
};

#endif
