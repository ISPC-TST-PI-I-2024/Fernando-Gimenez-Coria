#include <Arduino.h>


#define led 18



void setup() {

  Serial.begin(115200);

  pinMode(led, OUTPUT);
  }

void loop() {
  digitalWrite(led, HIGH);
}