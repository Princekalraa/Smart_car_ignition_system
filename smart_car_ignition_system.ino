#include <Keypad.h>

const int ignitionPin = 2;
const int startButtonPin = 3;
const int stopButtonPin = 4;

bool ignitionState = false;

void setup() {
  pinMode(ignitionPin, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);
  pinMode(stopButtonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(startButtonPin) == LOW && !ignitionState) {
    ignitionOn();
  }
  
  if (digitalRead(stopButtonPin) == LOW && ignitionState) {
    ignitionOff();
  }
}

void ignitionOn() {
  digitalWrite(ignitionPin, HIGH);
  ignitionState = true;
}

void ignitionOff() {
  digitalWrite(ignitionPin, LOW);
  ignitionState = false;
}
