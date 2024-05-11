#include <Arduino.h>


#define led1 18
#define led2 5
#define led3 17 
#define led4 16


bool contar = 0;
bool est_led1 = 0;
bool est_led2 = 0;
bool est_led3 = 0;
bool est_led4 = 0;

hw_timer_t *My_timer = NULL;



void IRAM_ATTR onTimer(){
contar = true;
}



void setup() {
Serial.begin(115200);
  
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);

My_timer = timerBegin(0, 80, true);
timerAttachInterrupt(My_timer, &onTimer, true);
timerAlarmWrite(My_timer, 50000, true);
timerAlarmEnable(My_timer);
}

void loop() {
  int overflow = 0;
    if (contar == 1){
      if(overflow != 3){
        est_led1 = !est_led1;
        est_led2 = !est_led2;
        est_led3 = est_led3;
        est_led4 = est_led4;
        overflow++;
        }
      if(overflow == 3){
        est_led1 = !est_led1;
        est_led2 = !est_led2;
        est_led3 = !est_led3;
        est_led4 = !est_led4;
        overflow = 0;
        }
      }
      Serial.print(est_led1);
      Serial.print(est_led2);
      Serial.print(est_led3);
      Serial.print(est_led4);
      Serial.println();
      digitalWrite(led1, est_led1);
      digitalWrite(led2, est_led2);
      digitalWrite(led3, est_led3);
      digitalWrite(led4, est_led4);
}
  

