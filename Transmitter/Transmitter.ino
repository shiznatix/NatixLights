#include <SPI.h>
#include <RH_RF69.h>
#include <RHReliableDatagram.h>
#include "Globals.h"

const boolean DEBUG = true;

void setup() {
  Serial.begin(9600);

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
  int leftTurnSignal = analogRead(LEFT_TURN_PIN);
  int rightTurnSignal = analogRead(RIGHT_TURN_PIN);
  int happySignal = analogRead(HAPPY_PIN);
  int stopOneSignal = analogRead(STOP_ONE_PIN);
  int stopTwoSignal = analogRead(STOP_TWO_PIN);

  if (DEBUG) {
    Serial.print("leftTurnSignal: ");
    Serial.print(leftTurnSignal);
    Serial.print(" - rightTurnSignal: ");
    Serial.print(rightTurnSignal);
    Serial.print(" - happySignal: ");
    Serial.print(happySignal);
    Serial.print(" - stopOneSignal: ");
    Serial.println(stopOneSignal);
    Serial.print(" - stopTwoSignal: ");
    Serial.println(stopTwoSignal);
  }
  
  // if (stopOneSignal < SIGNAL_THRESHOLD || stopTwoSignal < SIGNAL_THRESHOLD) {
  //   if (leftTurnSignal > SIGNAL_THRESHOLD) {
  //     sendMessage(ANIM_TYPE_STOP_LEFT_TURN);
  //   } else if (rightTurnSignal > SIGNAL_THRESHOLD) {
  //     sendMessage(ANIM_TYPE_STOP_RIGHT_TURN);
  //   } else {
  //     sendMessage(ANIM_TYPE_STOP);
  //   }
  // } else if (leftTurnSignal > SIGNAL_THRESHOLD) {
  //   sendMessage(ANIM_TYPE_LEFT_TURN);
  // } else if (rightTurnSignal > SIGNAL_THRESHOLD) {
  //   sendMessage(ANIM_TYPE_RIGHT_TURN);
  // } else
  if (happySignal > SIGNAL_THRESHOLD) {
    radioSend(ANIM_TYPE_HAPPY);
  } else {
    //radioSend(ANIM_TYPE_CAUTION);
    radioSend(ANIM_TYPE_STOP);
  }
  
  delay((DEBUG ? 100 : 10));
}

void radioSend(char animType) {
  String message = RADIO_SIGNAL_PREFIX + animType;
  
  if (DEBUG) {
    Serial.print("Sending: ");
    Serial.println(message);
  }

  char buffer[RH_RF69_MAX_MESSAGE_LEN];
  char bufferlength = sizeof(buffer);
  message.toCharArray(buffer, bufferlength);

  if (mRf69Manager.sendtoWait((uint8_t *)buffer, bufferlength, DEST_ADDRESS)) {
    if (DEBUG) {
      Serial.println("Message sent");
    }
  } else {
    Serial.println("Message sending failed (no ack)");
  }
}
