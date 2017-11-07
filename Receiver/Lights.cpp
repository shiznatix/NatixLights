#include "Lights.h"

Lights::Lights(int dataPin, int clockPin) :
	mNeoPatterns(PIXEL_COUNT, dataPin, clockPin, DOTSTAR_BRG) {
}

void Lights::setup() {
	// Setup LEDs
	mNeoPatterns.begin();
	mNeoPatterns.show();
}

bool Lights::isValidAnimation(const char animation) {
	switch (animation) {
		case ANIM_CUSTOM:
		case ANIM_CAUTION:
		case ANIM_LEFT_TURN:
		case ANIM_RIGHT_TURN:
		case ANIM_STOP:
		case ANIM_HAPPY:
		case ANIM_STOP_LEFT_TURN:
		case ANIM_STOP_RIGHT_TURN:
			return true;
		default:
			return false;
	}
}

void Lights::setupIfNewAnimation(const char animation) {
	bool isValid = isValidAnimation(animation);
	
	if (isValid && animation != mCurrentAnimation) {
		mCurrentAnimation = animation;
		reset();
	}
}

void Lights::setupBatteryIndicator(int wholeDigit, int decimalHundreds, int decimalTens) {
	setupIfNewAnimation(Lights::ANIM_CUSTOM);

	int pixel = 0;
	
	for (; pixel < wholeDigit; pixel++) {
		setPixelColor(pixel, getColor(r));
	}
	for (int i = 0; i < decimalHundreds; i++) {
		setPixelColor(pixel, getColor(g));
		pixel++;
	}
	for (int i = 0; i < decimalTens; i++) {
		setPixelColor(pixel, getColor(b));
		pixel++;
	}
	for (; pixel < PIXEL_COUNT; pixel++) {
		setPixelColor(pixel, getColor(_));
	}
}

void Lights::setPixelColor(int pixel, uint32_t color) {
	mNeoPatterns.setPixelColor(pixel, color);
}

void Lights::blank() {
	for (int i = 0; i < PIXEL_COUNT; i++) {
		mNeoPatterns.setPixelColor(i, getColor(_));
	}

	mNeoPatterns.show();
}

uint32_t Lights::getColor(const char &colorChar) {
	switch (colorChar) {
		case _:
			return mNeoPatterns.Color(0, 0, 0);
		case r:
			return mNeoPatterns.Color(0, MAX_COLOR * 2, 0);
		case o:
			return mNeoPatterns.Color((MAX_COLOR / 2), MAX_COLOR, 0);
		case y:
			return mNeoPatterns.Color((MAX_COLOR / 1.5), MAX_COLOR, 0);
		case g:
			return mNeoPatterns.Color(MAX_COLOR, 0, 0);
		case b:
			return mNeoPatterns.Color(0, 0, MAX_COLOR);
		case p:
			return mNeoPatterns.Color(0, (MAX_COLOR / 2), (MAX_COLOR / 2));
		case w:
			return mNeoPatterns.Color(MAX_COLOR, MAX_COLOR, MAX_COLOR);
	}
}

void Lights::reset() {
	unsigned long currentTime = millis();

	mIsBlinking = false;
	mCurrentAnimFrame = 0;
	mBlinkTimer = currentTime;
	mFrameTimer = currentTime;
}

void Lights::loop() {
	unsigned long currentTime = millis();

	// writing to the pixels requies a lot of processing and power so we don't want to do it too often
	// also, if we write to the pixels every loop, we don't receive any messages from the radio, that is
	// why we must write out seldomly
	unsigned long timeSincePixelRefresh = currentTime - mRefreshPixelsTimer;

	if (PIXEL_REFERSH_DELAY < timeSincePixelRefresh) {
		_updateIsBlinking(currentTime);
		_updateCurrentAnimFrame(currentTime);
		
		// reset our timer
		mRefreshPixelsTimer = currentTime;
		
		switch (mCurrentAnimation) {
			case ANIM_CUSTOM:
				mNeoPatterns.show();
				break;
			case ANIM_CAUTION:
				_image(IMAGE_CAUTION[mCurrentAnimFrame]);
				break;
			case ANIM_LEFT_TURN:
				_blinkImage(IMAGE_LEFT_TURN);
				break;
			case ANIM_RIGHT_TURN:
				_blinkImage(IMAGE_RIGHT_TURN);
				break;
			case ANIM_STOP:
				_image(IMAGE_STOP);
				break;
			case ANIM_HAPPY:
				_image(IMAGE_HAPPY);
				break;
			case ANIM_STOP_LEFT_TURN:
				_blinkImage(IMAGE_STOP_LEFT_TURN);
				break;
			case ANIM_STOP_RIGHT_TURN:
				_blinkImage(IMAGE_STOP_RIGHT_TURN);
				break;
		}
	}
}

// private methods
void Lights::_updateIsBlinking(unsigned long &currentTime) {
	unsigned long timeSinceBlink = currentTime - mBlinkTimer;

	if (BLINK_DELAY < timeSinceBlink) {
		mIsBlinking = !mIsBlinking;

		// reset our timer
		mBlinkTimer = currentTime;
	}
}

void Lights::_updateCurrentAnimFrame(unsigned long &currentTime) {
	unsigned long timeSinceFrameChange = currentTime - mFrameTimer;

	if (FRAME_DELAY < timeSinceFrameChange) {
		mCurrentAnimFrame++;

		// reset to 0 position if we have reached the end of our frames
		if (mCurrentAnimFrame >= ANIM_FRAMES) {
			mCurrentAnimFrame = 0;
		}

		// reset our timer
		mFrameTimer = currentTime;
	}
}

void Lights::_image(const char image[PIXEL_COUNT]) {
	for (int i = 0; i < PIXEL_COUNT; i++) {
		mNeoPatterns.setPixelColor(i, getColor(image[i]));
	}

	mNeoPatterns.show();
}

void Lights::_blinkImage(const char image[PIXEL_COUNT]) {
	if (!mIsBlinking) {
		_image(image);
	}
	else {
		blank();
	}
}
