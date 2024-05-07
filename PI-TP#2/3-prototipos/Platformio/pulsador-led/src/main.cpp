#include <Arduino.h>

#define LED 4
#define PULSADOR 16
bool ENCENDER_LED;
void setup() {
    pinMode(LED, OUTPUT);
    pinMode(PULSADOR, INPUT_PULLUP);
    digitalWrite(LED, HIGH);
    
}

void loop() {
  while (true){
      
      ENCENDER_LED = digitalRead(PULSADOR);
      if (ENCENDER_LED == LOW)
      {
        digitalWrite(LED, LOW);
        delay(1000);
      }
      else 
      digitalWrite(LED, HIGH);
    }
}
