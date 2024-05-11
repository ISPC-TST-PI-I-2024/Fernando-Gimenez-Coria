#include <Arduino.h>

#define puls 36
#define led 18

bool touch =0; 

void setup() {

  Serial.begin(115200);

  pinMode(led, OUTPUT);
  pinMode(puls, INPUT_PULLUP);

}

void loop() {
  touch = digitalRead(puls);
  if (touch == LOW){
    digitalWrite(led, HIGH);
    Serial.println("prendido");    
    delay(500);
  }else{
    digitalWrite(led, LOW);
    Serial.println("apagado");
    delay(500);
  }

}