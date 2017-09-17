#include "Lights.h"

Lights::Lights(int dataPin, int clockPin) :
	mLedStrip(PIXEL_COUNT, dataPin, clockPin, DOTSTAR_BRG) {
}

void Lights::setup() {
	// Setup LEDs
	mLedStrip.begin();
	mLedStrip.show();
}

bool Lights::isValidAnimation(const char animation) {
	switch (animation) {
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
			case ANIM_CAUTION:
				_image(IMAGE_CAUTION[mCurrentAnimFrame]);
				break;
			case ANIM_LEFT_TURN:
				// _blinkImage(IMAGE_LEFT_TURN);
				_image(IMAGE_LEFT_TURN);
				break;
			case ANIM_RIGHT_TURN:
				// _blinkImage(IMAGE_RIGHT_TURN);
				_image(IMAGE_RIGHT_TURN);
				break;
			case ANIM_STOP:
				_image(IMAGE_STOP);
				break;
			case ANIM_HAPPY:
				_image(IMAGE_HAPPY);
				break;
			case ANIM_STOP_LEFT_TURN:
				// _blinkImage(IMAGE_STOP_LEFT_TURN);
				_image(IMAGE_STOP_LEFT_TURN);
				break;
			case ANIM_STOP_RIGHT_TURN:
				// _blinkImage(IMAGE_STOP_RIGHT_TURN);
				_image(IMAGE_STOP_RIGHT_TURN);
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

uint32_t Lights::_getColor(const char &colorChar) {
	switch (colorChar) {
		case _:
			return mLedStrip.Color(0, 0, 0);
		case r:
			return mLedStrip.Color(0, MAX_COLOR * 2, 0);
		case o:
			//return mLedStrip.Color((MAX_COLOR / 3), MAX_COLOR, 0);
			return mLedStrip.Color((MAX_COLOR / 2), MAX_COLOR, 0);
		case y:
			return mLedStrip.Color((MAX_COLOR / 1.5), MAX_COLOR, 0);
		case g:
			return mLedStrip.Color(MAX_COLOR, 0, 0);
		case b:
			return mLedStrip.Color(0, 0, MAX_COLOR);
		case p:
			return mLedStrip.Color(0, (MAX_COLOR / 2), (MAX_COLOR / 2));
		case w:
			return mLedStrip.Color(MAX_COLOR, MAX_COLOR, MAX_COLOR);
	}
}

void Lights::_image(const char image[PIXEL_COUNT]) {
	for (int i = 0; i < PIXEL_COUNT; i++) {
		mLedStrip.setPixelColor(i, _getColor(image[i]));
	}

	mLedStrip.show();
}

void Lights::_blinkImage(const char image[PIXEL_COUNT]) {
	if (!mIsBlinking) {
		_image(image);
	}
	else {
		_blank();
	}
}

void Lights::_blank() {
	for (int i = 0; i < PIXEL_COUNT; i++) {
		mLedStrip.setPixelColor(i, _getColor(_));
	}

	mLedStrip.show();
}
