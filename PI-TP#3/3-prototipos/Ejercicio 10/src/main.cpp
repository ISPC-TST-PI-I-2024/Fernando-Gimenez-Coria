#include <Arduino.h>

#define led1 18

int dip_sw[] = {13, 12, 14};
int dsw[3];
int freq_led = 0;
int set_retardo = 0;

void calc_retardo(){
for (byte i = 0; i < 3; i++){
    dsw[i] = digitalRead(dip_sw[i]);
  }
freq_led = 4 * dsw[2] + 2 * dsw[1] + dsw[0];

switch (freq_led){
  case 0:
    set_retardo = 0;
  break;
  case 1:
    set_retardo = 200;
  break;
  case 2:
    set_retardo = 400;
  break;
  case 3:
    set_retardo = 600;
  break;
  case 4:
    set_retardo = 800;
  break;
  case 5:
    set_retardo = 1000;
  break;
  case 6:
    set_retardo = 1200;
  break;
  case 7:
    set_retardo = 1400;
  break;
  
}
}


void setup() {

  Serial.begin(115200);
  for (byte i = 0; i < 3; i++){
  pinMode(dip_sw[i], INPUT_PULLUP);
  }
  pinMode(led1, OUTPUT);
}

void loop() {
  freq_led = 0;
  calc_retardo();
  if (set_retardo == 0)
    digitalWrite(led1, LOW);

  else {
    digitalWrite(led1, HIGH);
    delay(set_retardo);
    digitalWrite(led1, LOW);
    delay(set_retardo);
  }
  Serial.println(set_retardo);

}