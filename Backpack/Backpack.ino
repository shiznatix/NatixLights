#include <Adafruit_NeoPixel.h>
#include <VirtualWire.h>
#include "Globals.h"

const boolean DEBUG = false;

void setup() {
  if (DEBUG) {
    Serial.begin(9600);
  }
  
  pinMode(POWER_PIN, OUTPUT);
  
  mNeoPixelStrip.begin();
  mNeoPixelStrip.show(); // Initialize all pixels to 'off'
  
  vw_set_rx_pin(RADIO_PIN);
  vw_setup(2000);
  vw_rx_start();
  
  digitalWrite(POWER_PIN, HIGH);
}

void loop() {
  mCurrentTime = millis();
  
  //writing to the neopixels requies a lot of processing and power so we don't want to do it too often
  //also, if we write to the neopixels every loop, we don't receive any messages from the radio, that is
  //why we must write out seldomly
  unsigned long timeSincePixelRefresh = mCurrentTime - mRefreshPixelsTimer;

  if (PIXEL_REFERSH_DELAY < timeSincePixelRefresh) {
    setIsBlinking();
    setCurrentAnimFrame();
    
    //reset our timer
    mRefreshPixelsTimer = mCurrentTime;
    
    switch (mCurrentAnimType) {
      case ANIM_TYPE_CAUTION:
        showAnimation(ANIM_CAUTION, COLOR_RED);
        break;
      case ANIM_TYPE_LEFT_TURN:
        showColoredBlinking(IMAGE_LEFT_TURN);
        break;
      case ANIM_TYPE_RIGHT_TURN:
        showColoredBlinking(IMAGE_RIGHT_TURN);
        break;
      case ANIM_TYPE_STOP:
        showColored(IMAGE_STOP);
        break;
      case ANIM_TYPE_HAPPY:
        showColored(IMAGE_HAPPY);
        break;
      case ANIM_TYPE_STOP_LEFT_TURN:
        showColoredBlinking(IMAGE_STOP_LEFT_TURN);
        break;
      case ANIM_TYPE_STOP_RIGHT_TURN:
        showColoredBlinking(IMAGE_STOP_RIGHT_TURN);
        break;
    }
  }
  
  radioRead();
}

void showColored(const uint32_t coloredImage[NEOPIXEL_COUNT]) {
  for (int i = 0; i < NEOPIXEL_COUNT; i++) {
    mNeoPixelStrip.setPixelColor(i, coloredImage[i]);
  }

  mNeoPixelStrip.show();
}

void showColoredBlinking(const uint32_t coloredImage[NEOPIXEL_COUNT]) {
  if (!mIsBlinking) {
    showColored(coloredImage);
  }
  else {
    blankNeopixels();
  }
}

void showAnimation(const byte animation[ANIM_FRAMES][NEOPIXEL_COUNT], uint32_t color) {
  for (int i = 0; i < NEOPIXEL_COUNT; i++) {
    mNeoPixelStrip.setPixelColor(i, (1 == animation[mCurrentAnimFrame][i] ? color : COLOR_OFF));
  }

  mNeoPixelStrip.show();
}

void blankNeopixels() {
  for (int i = 0; i < NEOPIXEL_COUNT; i++) {
    mNeoPixelStrip.setPixelColor(i, COLOR_OFF);
  }

  mNeoPixelStrip.show();
}

void setIsBlinking() {
  unsigned long timeSinceBlink = mCurrentTime - mBlinkTimer;

  if (BLINK_DELAY < timeSinceBlink) {
    mIsBlinking = !mIsBlinking;

    //reset our timer
    mBlinkTimer = mCurrentTime;
  }
}

void setCurrentAnimFrame() {
  unsigned long timeSinceFrameChange = mCurrentTime - mFrameTimer;

  if (FRAME_DELAY < timeSinceFrameChange) {
    mCurrentAnimFrame++;

    //reset to 0 position if we have reached the end of our frames
    if (mCurrentAnimFrame >= ANIM_FRAMES) {
      mCurrentAnimFrame = 0;
    }

    //reset our timer
    mFrameTimer = mCurrentTime;
  }
}

void radioRead() {
  byte buf[VW_MAX_MESSAGE_LEN];
  byte buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) {
    boolean receivedSignal = true;
    
    for (int i = 0; i < RADIO_PREFIX_LENGTH; i++) {
      char ref = buf[i];
      
      if (ref != RADIO_SIGNAL_PREFIX[i]) {
        receivedSignal = false;
        break;
      }
    }
    
    if (receivedSignal) {
      int signal = buf[RADIO_PREFIX_LENGTH] - '0';
      boolean newSignal = (signal != mCurrentAnimType);
      
      //we must validate that this is an appropriate signal type
      switch (signal) {
        case ANIM_TYPE_LEFT_TURN:
          mCurrentAnimType = ANIM_TYPE_LEFT_TURN;
          break;
        case ANIM_TYPE_RIGHT_TURN:
          mCurrentAnimType = ANIM_TYPE_RIGHT_TURN;
          break;
        case ANIM_TYPE_STOP:
          mCurrentAnimType = ANIM_TYPE_STOP;
          break;
        case ANIM_TYPE_HAPPY:
          mCurrentAnimType = ANIM_TYPE_HAPPY;
          break;
        case ANIM_TYPE_STOP_LEFT_TURN:
          mCurrentAnimType = ANIM_TYPE_STOP_LEFT_TURN;
          break;
        case ANIM_TYPE_STOP_RIGHT_TURN:
          mCurrentAnimType = ANIM_TYPE_STOP_RIGHT_TURN;
          break;
        default:
          mCurrentAnimType = ANIM_TYPE_CAUTION;
          break;
      }
      
      //if the signal has changed, blank our variables for displaying
      if (newSignal) {
        mIsBlinking = false;
        mCurrentAnimFrame = 0;
        mBlinkTimer = mCurrentTime;
        mFrameTimer = mCurrentTime;
      }
    }
    
    //we received a message, reset our timer
    mRadioTimeoutTimer = mCurrentTime;
  }
  else {
    //if no message was received, make sure we haven't timed out yet.
    unsigned long timeSinceLastSignal = mCurrentTime - mRadioTimeoutTimer;
  
    if (RADIO_SIGNAL_TIMEOUT < timeSinceLastSignal) {
      mCurrentAnimType = ANIM_TYPE_CAUTION;
    }
  }
}
