#include <Arduino.h>

#define pulsador 36
#define led 18

bool puls_press =0; 

void setup() {

  Serial.begin(115200);

  pinMode(led, OUTPUT);
  pinMode(pulsador, INPUT_PULLUP);

}

void loop() {
  puls_press = digitalRead(pulsador);
  if (puls_press == LOW){
    digitalWrite(led, HIGH);

    Serial.println("encendido"); 
      
    delay(500);
  }else{
    digitalWrite(led, LOW);

    Serial.println("apagado");
    
    delay(500);
  }

}