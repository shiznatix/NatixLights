#include "NeoPatterns.h"

NeoPatterns::NeoPatterns(uint16_t pixels, uint8_t pin, uint8_t type, uint8_t colorOrder) :
	Adafruit_DotStar(pixels, pin, type, colorOrder) {
}

void NeoPatterns::reverse() {
	if (mDirection == FORWARD) {
		mDirection = REVERSE;
		mIndex = mTotalSteps - 1;
	} else {
		mDirection = FORWARD;
		mIndex = 0;
	}
}

void NeoPatterns::rainbowCycle(uint8_t interval, direction dir) {
	// don't re-init if we are doing it already, force off() call
	if (RAINBOW_CYCLE == mCurrentPattern) {
		return;
	}

	mCurrentPattern = RAINBOW_CYCLE;
	mInterval = interval;
	mTotalSteps = 255;
	mIndex = 0;
	mDirection = dir;
}

void NeoPatterns::theaterChase(uint32_t color1, uint32_t color2, uint8_t interval, direction dir) {
	// don't re-init if we are doing it already, force off() call
	if (THEATER_CHASE == mCurrentPattern) {
		return;
	}

	mCurrentPattern = THEATER_CHASE;
	mInterval = interval;
	mTotalSteps = numPixels();
	mColor1 = color1;
	mColor2 = color2;
	mIndex = 0;
	mDirection = dir;
}

void NeoPatterns::colorWipe(uint32_t color, uint8_t interval, direction dir) {
	// don't re-init if we are doing it already, force off() call
	if (COLOR_WIPE == mCurrentPattern) {
		return;
	}

	mCurrentPattern = COLOR_WIPE;
	mInterval = interval;
	mTotalSteps = numPixels();
	mColor1 = color;
	mIndex = 0;
	mDirection = dir;
}

void NeoPatterns::scanner(uint32_t color1, uint8_t interval) {
	// don't re-init if we are doing it already, force off() call
	if (SCANNER == mCurrentPattern) {
		return;
	}

	mCurrentPattern = SCANNER;
	mInterval = interval;
	mTotalSteps = (numPixels() - 1) * 2;
	mColor1 = color1;
	mIndex = 0;
}

void NeoPatterns::fade(uint32_t color1, uint32_t color2, uint16_t steps, uint8_t interval, direction dir) {
	// don't re-init if we are doing it already, force off() call
	if (FADE == mCurrentPattern) {
		return;
	}

	mCurrentPattern = FADE;
	mInterval = interval;
	mTotalSteps = steps;
	mColor1 = color1;
	mColor2 = color2;
	mIndex = 0;
	mDirection = dir;
}

void NeoPatterns::blink(uint32_t color1, uint32_t color2, uint8_t interval) {
	// don't re-init if we are doing it already, force off() call
	if (BLINK == mCurrentPattern) {
		return;
	}

	mCurrentPattern = BLINK;
	mInterval = interval;
	mTotalSteps = 2;
	mColor1 = color1;
	mColor2 = color2;
	mIndex = 0;
}

void NeoPatterns::flash(uint32_t color1, uint32_t color2, uint8_t steps, uint32_t interval, direction dir) {
	// don't re-init if we are doing it already, force off() call
	if (FLASH == mCurrentPattern && color1 == mColor1 && color2 == mColor2) {
		return;
	}

	mCurrentPattern = FLASH;
	mInterval = interval;
	mTotalSteps = steps;
	mColor1 = color1;
	mColor2 = color2;
	mIndex = 0;
}

void NeoPatterns::stopPattern() {
	mCurrentPattern = NONE;
	mInterval = 0;
	mTotalSteps = 0;
	mIndex = 0;
}

void NeoPatterns::off() {
	_colorSet(Color(0, 0, 0));

	stopPattern();
}

void NeoPatterns::loop() {
	unsigned long currentTime = millis();

	if ((currentTime - mLastUpdate) > mInterval) {
		mLastUpdate = currentTime;

		switch(mCurrentPattern) {
			case RAINBOW_CYCLE:
				_rainbowCycleUpdate();
				break;
			case THEATER_CHASE:
				_theaterChaseUpdate();
				break;
			case COLOR_WIPE:
				_colorWipeUpdate();
				break;
			case SCANNER:
				_scannerUpdate();
				break;
			case FADE:
				_fadeUpdate();
				break;
			case BLINK:
				_updateBlink();
				break;
			case FLASH:
				_updateFlash();
				break;
		}
	}
}

bool NeoPatterns::_increment() {
	if (mDirection == FORWARD) {
		mIndex++;
	 
		if (mIndex >= mTotalSteps) {
			mIndex = 0;
			return true;
		}
	} else {
		--mIndex;
		
		if (mIndex <= 0) {
			mIndex = mTotalSteps - 1;
			return true;
		}
	}

	return false;
}

void NeoPatterns::_rainbowCycleUpdate() {
	for (int i = 0; i < numPixels(); i++) {
		setPixelColor(i, _getRainbowColor(((i * 256 / numPixels()) + mIndex) & 255));
	}

	show();
	_increment();
}

void NeoPatterns::_theaterChaseUpdate() {
	for (int i = 0; i < numPixels(); i++) {
		if ((i + mIndex) % 3 == 0) {
			setPixelColor(i, mColor1);
		} else {
			setPixelColor(i, mColor2);
		}
	}

	show();
	_increment();
}

void NeoPatterns::_colorWipeUpdate() {
	setPixelColor(mIndex, mColor1);

	show();
	_increment();
}

void NeoPatterns::_scannerUpdate() {
	for (int i = 0; i < numPixels(); i++) {
		if (i == mIndex) {
			setPixelColor(i, mColor1);
		} else if (i == mTotalSteps - mIndex) {
			setPixelColor(i, mColor1);
		} else {
			setPixelColor(i, _dimColor(getPixelColor(i)));
		}
	}

	show();
	_increment();
}

void NeoPatterns::_fadeUpdate() {
	// Calculate linear interpolation between mColor1 and mColor2
	// Optimise order of operations to minimize truncation error
	uint8_t red = ((_red(mColor1) * (mTotalSteps - mIndex)) + (_red(mColor2) * mIndex)) / mTotalSteps;
	uint8_t green = ((_green(mColor1) * (mTotalSteps - mIndex)) + (_green(mColor2) * mIndex)) / mTotalSteps;
	uint8_t blue = ((_blue(mColor1) * (mTotalSteps - mIndex)) + (_blue(mColor2) * mIndex)) / mTotalSteps;

	_colorSet(Color(red, green, blue));
	show();

	// go the other direction when complete
	if (_increment()) {
		reverse();
		_increment(); // increment or we will repeat the last call
	}
}

void NeoPatterns::_updateBlink() {
	for (int i = 0; i < numPixels(); i++) {
		uint32_t color = (mIndex % 2 ? Color(0, 0, 0) : (i % 2 ? mColor2 : mColor1));
		setPixelColor(i, color);
	}

	show();
	_increment();
}

void NeoPatterns::_updateFlash() {
	for (int i = 0; i < numPixels(); i++) {
		uint32_t color = ((1 == mIndex || 3 == mIndex) ? (i % 2 ? mColor2 : mColor1) : Color(0, 0, 0));
		setPixelColor(i, color);
	}

	show();
	_increment();
}

uint32_t NeoPatterns::_dimColor(uint32_t color) {
	// Shift R, G and B components one bit to the right
	uint32_t dimColor = Color(_red(color) >> 1, _green(color) >> 1, _blue(color) >> 1);
	return dimColor;
}

void NeoPatterns::_colorSet(uint32_t color) {
	for (int i = 0; i < numPixels(); i++) {
		setPixelColor(i, color);
	}

	show();
}

// Returns the Red component of a 32-bit color
uint8_t NeoPatterns::_red(uint32_t color) {
	return (color >> 16) & 0xFF;
}

// Returns the Green component of a 32-bit color
uint8_t NeoPatterns::_green(uint32_t color) {
	return (color >> 8) & 0xFF;
}

// Returns the Blue component of a 32-bit color
uint8_t NeoPatterns::_blue(uint32_t color) {
	return color & 0xFF;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t NeoPatterns::_getRainbowColor(byte pos) {
	pos = 255 - pos;

	if (pos < 85) {
		return Color(255 - pos * 3, 0, pos * 3);
	} else if (pos < 170) {
		pos -= 85;

		return Color(0, pos * 3, 255 - pos * 3);
	} else {
		pos -= 170;

		return Color(pos * 3, 255 - pos * 3, 0);
	}
}
