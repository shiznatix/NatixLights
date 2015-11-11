#include <VirtualWire.h>
#include "Globals.h"

const boolean DEBUG = false;

void setup() {
  if (DEBUG) {
    Serial.begin(9600);
  }
  
  pinMode(LEFT_TURN_PIN, INPUT);
  pinMode(RIGHT_TURN_PIN, INPUT);
  pinMode(HAPPY_PIN, INPUT);
  pinMode(STOP_PIN, INPUT);
  
  vw_set_tx_pin(RADIO_PIN);
  vw_setup(2000);//bits per sec
}

void loop() {
  int leftTurnSignal = analogRead(LEFT_TURN_PIN);
  int rightTurnSignal = analogRead(RIGHT_TURN_PIN);
  int happySignal = analogRead(HAPPY_PIN);
  int stopSignal = analogRead(STOP_PIN);
  
  if (DEBUG) {
    Serial.print("leftTurnSignal: ");
    Serial.print(leftTurnSignal);
    Serial.print(" - rightTurnSignal: ");
    Serial.print(rightTurnSignal);
    Serial.print(" - happySignal: ");
    Serial.print(happySignal);
    Serial.print(" - stopSignal: ");
    Serial.println(stopSignal);
  }
  
  if (stopSignal < SIGNAL_THRESHOLD) {
    if (leftTurnSignal > SIGNAL_THRESHOLD) {
      sendMessage(ANIM_TYPE_STOP_LEFT_TURN);
    }
    else if (rightTurnSignal > SIGNAL_THRESHOLD) {
      sendMessage(ANIM_TYPE_STOP_RIGHT_TURN);
    }
    else {
      sendMessage(ANIM_TYPE_STOP);
    }
  }
  else if (leftTurnSignal > SIGNAL_THRESHOLD) {
    sendMessage(ANIM_TYPE_LEFT_TURN);
  }
  else if (rightTurnSignal > SIGNAL_THRESHOLD) {
    sendMessage(ANIM_TYPE_RIGHT_TURN);
  }
  else if (happySignal > SIGNAL_THRESHOLD) {
    sendMessage(ANIM_TYPE_HAPPY);
  }
  else {
    sendMessage(ANIM_TYPE_CAUTION);
  }
  
  delay((DEBUG ? 100 : 10));
}

void sendMessage(const char *message) {
  char toSend[(MESSAGE_LENGTH + 1)];
  sprintf(toSend, "%s%s", MESSAGE_PREFIX, message);
  
  if (DEBUG) {
    Serial.print("Sending: ");
    Serial.println(toSend);
  }
  
  vw_send((uint8_t *)toSend, strlen(toSend));
  vw_wait_tx();//wait until the whole message is gone
}
