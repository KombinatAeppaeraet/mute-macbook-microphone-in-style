#include "DigiKeyboard.h"

#define ledPin 1
#define inputPin 0

void setup() {
    pinMode(inputPin,INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {
  DigiKeyboard.delay(5);
  // switch LED ON
  digitalWrite(ledPin, HIGH); 
  if(!digitalRead(inputPin)) {
    // send Mute key if switch closed
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT, MOD_CMD_LEFT); 
    // switch LED OFF
    digitalWrite(ledPin, LOW); 
    // wait for switch to open
    while(!digitalRead(inputPin)) { 
      DigiKeyboard.delay(100); 
      }
    // send unmute Key
    DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, MOD_CMD_LEFT);
  }
}
