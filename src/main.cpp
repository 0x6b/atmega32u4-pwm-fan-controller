#include "Arduino.h"

const int pwmOut = 5;

void setup() {
  pinMode(pwmOut, OUTPUT);
}

void loop() {
  analogWrite(pwmOut, 8); // 0-255
  delay(1000);
}
