#include <Arduino.h>

int dip_sw[] = {13, 12, 14, 27, 26, 25, 33, 32};
int leds[] =  {18, 5, 17, 16, 4, 0, 2, 15};



void setup() {

  Serial.begin(115200);
  for (byte i = 0; i < 8; i++){
  pinMode(leds[i], OUTPUT);
  pinMode(dip_sw[i], INPUT_PULLUP);
  }

}

void loop() {
  for (byte i = 0; i < 8; i++){
    digitalWrite(leds[i], !digitalRead(dip_sw[i]));
  }

}