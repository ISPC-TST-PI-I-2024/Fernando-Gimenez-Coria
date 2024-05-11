#include <Arduino.h>

#define led_1 18
#define led_2 5
#define led_3 17

void setup() {

  Serial.begin(115200);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  
}

void loop() {
  digitalWrite(led_1, HIGH);
  delay(500);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(500);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(500);
  digitalWrite(led_3, LOW);
}