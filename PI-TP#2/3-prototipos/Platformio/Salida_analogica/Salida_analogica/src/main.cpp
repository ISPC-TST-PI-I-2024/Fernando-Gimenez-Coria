#include <Arduino.h>

int L1 = 0;
int pote = 1;
long lect_pote = 0;

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(pote, INPUT);

  Serial.begin(115200);
  Serial.println("Variacion de intensidad por PWM");
}

void loop() {
  lect_pote = analogRead(pote)/32;
  Serial.println(lect_pote);
  analogWrite(L1, lect_pote);
  
}
