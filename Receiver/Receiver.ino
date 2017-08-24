#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <RH_RF69.h>
#include <RHReliableDatagram.h>
#include "Globals.h"

const boolean DEBUG = true;

void setup() {
  if (DEBUG) {
    Serial.begin(9600);
  }

  // Setup LEDs
  mDotStarStrip.begin();
  mDotStarStrip.show();
  pinMode(13, OUTPUT);

  // Setup radio
  pinMode(RFM69_RST, OUTPUT);
  digitalWrite(RFM69_RST, LOW);

  // manual reset
  digitalWrite(RFM69_RST, HIGH);
  delay(10);
  digitalWrite(RFM69_RST, LOW);
  delay(10);

  if (!mRf69Manager.init()) {
    // TODO Handle cannot init
  }
  
  if (!mRf69.setFrequency(RF69_FREQ)) {
    // TODO handle cannot set frequency
  }

  // TODO: find best power setting 14-20
  mRf69.setTxPower(20, true);

  mRf69.setEncryptionKey(RADIO_ENCRYPTION_KEY);
}

void loop() {
  mCurrentTime = millis();
  
  // writing to the neopixels requies a lot of processing and power so we don't want to do it too often
  // also, if we write to the neopixels every loop, we don't receive any messages from the radio, that is
  // why we must write out seldomly
  unsigned long timeSincePixelRefresh = mCurrentTime - mRefreshPixelsTimer;

  if (PIXEL_REFERSH_DELAY < timeSincePixelRefresh) {
    setIsBlinking();
    setCurrentAnimFrame();
    
    // reset our timer
    mRefreshPixelsTimer = mCurrentTime;
    
    switch (mCurrentAnimType) {
      case ANIM_TYPE_CAUTION:
        //showAnimation(ANIM_CAUTION, COLOR_RED);
        showColored(IMAGE_ESTONIA_CROSS);
        break;
      case ANIM_TYPE_LEFT_TURN:
        showColoredBlinking(IMAGE_LEFT_TURN);
        break;
      case ANIM_TYPE_RIGHT_TURN:
        showColoredBlinking(IMAGE_RIGHT_TURN);
        break;
      case ANIM_TYPE_STOP:
        //showColored(IMAGE_STOP);
        showColored(IMAGE_USA);
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

void showColored(const uint32_t coloredImage[DS_PIXEL_COUNT]) {
  for (int i = 0; i < DS_PIXEL_COUNT; i++) {
    mDotStarStrip.setPixelColor(i, coloredImage[i]);
  }

  mDotStarStrip.show();
}

void showColoredBlinking(const uint32_t coloredImage[DS_PIXEL_COUNT]) {
  if (!mIsBlinking) {
    showColored(coloredImage);
  }
  else {
    showBlank();
  }
}

void showAnimation(const byte animation[ANIM_FRAMES][DS_PIXEL_COUNT], uint32_t color) {
  for (int i = 0; i < DS_PIXEL_COUNT; i++) {
    mDotStarStrip.setPixelColor(i, (1 == animation[mCurrentAnimFrame][i] ? color : COLOR_OFF));
  }

  mDotStarStrip.show();
}

void showBlank() {
  for (int i = 0; i < DS_PIXEL_COUNT; i++) {
    mDotStarStrip.setPixelColor(i, COLOR_OFF);
  }

  mDotStarStrip.show();
}

void setIsBlinking() {
  unsigned long timeSinceBlink = mCurrentTime - mBlinkTimer;

  if (BLINK_DELAY < timeSinceBlink) {
    mIsBlinking = !mIsBlinking;

    // reset our timer
    mBlinkTimer = mCurrentTime;
  }
}

void setCurrentAnimFrame() {
  unsigned long timeSinceFrameChange = mCurrentTime - mFrameTimer;

  if (FRAME_DELAY < timeSinceFrameChange) {
    mCurrentAnimFrame++;

    // reset to 0 position if we have reached the end of our frames
    if (mCurrentAnimFrame >= ANIM_FRAMES) {
      mCurrentAnimFrame = 0;
    }

    // reset our timer
    mFrameTimer = mCurrentTime;
  }
}

void radioRead() {
  if (mRf69Manager.available()) {
    uint8_t messageFrom;
    
    if (mRf69Manager.recvfromAck(mReadBuffer, &mReadBufferlength, &messageFrom)) {
      mReadBuffer[mReadBufferlength] = 0; // zero out remaining string

      String received = String((char*)mReadBuffer);

      if (DEBUG) {
        Serial.print("Received: ");
        Serial.println(received);
      }

      // TODO CUTOFF BEGINNING OF READ MESSAGE AND EXTRACT THE SIGNAL VALUE
      if (received.startsWith(RADIO_SIGNAL_PREFIX)) {
        char animType = received.charAt((RADIO_SIGNAL_PREFIX.length()));
        boolean isNewType = (animType != mCurrentAnimType);

        if (DEBUG) {
          Serial.print("Animation type: ");
          Serial.println(animType);
        }

        //we must validate that this is an appropriate animation type
        switch (animType) {
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
        if (isNewType) {
          mIsBlinking = false;
          mCurrentAnimFrame = 0;
          mBlinkTimer = mCurrentTime;
          mFrameTimer = mCurrentTime;
        }

        // we received a message, reset our timer
        mRadioTimeoutTimer = mCurrentTime;
      }
    }
  }

  // make sure we haven't timed out yet.
  unsigned long timeSinceLastSignal = mCurrentTime - mRadioTimeoutTimer;

  if (RADIO_SIGNAL_TIMEOUT < timeSinceLastSignal) {
    if (DEBUG) {
      Serial.println("Radio timeout");
    }

    mRadioTimeoutTimer = mCurrentTime;
    mCurrentAnimType = ANIM_TYPE_CAUTION;
  }
}
