#include <Arduino.h>

const int BUFFER_SIZE = 8;
char buf[BUFFER_SIZE];
int leds[] =  {18, 5, 17, 16, 4, 0, 2, 15};

void setup() {
  Serial.begin(115200); 
  for (byte i = 0; i < 8; i++){
  pinMode(leds[i], OUTPUT);}

}

void loop() {
  // check if data is available
  if (Serial.available() > 0) {    //pregunto si hay datos en el puerto serie
    
    int orden = Serial.readBytes(buf, BUFFER_SIZE); //leo los datos 

    Serial.print("La orden es: ");
    for(int i = 0; i < orden; i++){
      Serial.print(buf[i]);
      Serial.println();
      
      if(buf[i] == '1')
      digitalWrite(leds[i], HIGH);
      else
      digitalWrite(leds[i], LOW);
      
    }

  }
}