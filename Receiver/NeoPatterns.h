#ifndef NeoPatterns_h
#define NeoPatterns_h

#include <Adafruit_DotStar.h>
#include "Arduino.h"

#include "Debug.h"

enum pattern {
	NONE, RAINBOW_CYCLE, THEATER_CHASE,
	COLOR_WIPE, SCANNER, FADE, BLINK, FLASH
};

enum direction {
	FORWARD, REVERSE
};

class NeoPatterns : public Adafruit_DotStar {
	public:
		NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, uint8_t colorOrder);

		void loop();
		void reverse();
		void rainbowCycle(uint8_t interval, direction dir);
		void theaterChase(uint32_t color1, uint32_t color2, uint8_t interval, direction dir);
		void colorWipe(uint32_t color, uint8_t interval, direction dir);
		void scanner(uint32_t color1, uint8_t interval);
		void fade(uint32_t color1, uint32_t color2, uint16_t steps, uint8_t interval, direction dir);
		void blink(uint32_t color1, uint32_t color2, uint8_t interval);
		void flash(uint32_t color1, uint32_t color2, uint8_t steps, uint32_t interval, direction dir);
		void stopPattern();
		void off();
	private:
		pattern mCurrentPattern; // which pattern is running
		direction mDirection; // direction to run the pattern

		unsigned long mInterval; // milliseconds between updates
		unsigned long mLastUpdate; // last update of position

		uint32_t mColor1, mColor2; // What colors are in use
		uint16_t mTotalSteps; // total number of steps in the pattern
		uint16_t mIndex; // current step within the pattern

		bool _increment();
		void _rainbowCycleUpdate();
		void _theaterChaseUpdate();
		void _colorWipeUpdate();
		void _scannerUpdate();
		void _fadeUpdate();
		void _updateBlink();
		void _updateFlash();

		uint32_t _dimColor(uint32_t color);
		void _colorSet(uint32_t color);
		uint8_t _red(uint32_t color);
		uint8_t _green(uint32_t color);
		uint8_t _blue(uint32_t color);
		uint32_t _getRainbowColor(byte pos);
};

#endif