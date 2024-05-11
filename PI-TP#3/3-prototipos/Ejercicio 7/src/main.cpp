#include <Arduino.h>

#define btn1 34
#define btn2 39
#define led1 18
#define led2 5

int T_debounce = 100;
bool touch_1_actual = 0;
bool touch_2_actual = 0; 

bool debounce (bool t_actual, int btn){      //funcion debounce, devuelve true si el el pulsador continua en el mismo 
  bool last_t = t_actual;           //despues de un retardo determinado por T_debounce
  
  delayMicroseconds(T_debounce);
  
  t_actual = digitalRead(btn);

  if(t_actual == last_t)
    return true;
  else 
    return false;
}

void setup() {

  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn1, INPUT);

}

void loop() {
  touch_1_actual = digitalRead(btn1);

  if (debounce(touch_1_actual, btn1) == true){
    if (touch_1_actual == false)
      digitalWrite(led1, HIGH);
    else
      digitalWrite(led1, LOW);
  }
  touch_2_actual = digitalRead(btn2);

  if (debounce(touch_2_actual, btn2) == true){
    if (touch_2_actual == false)
      digitalWrite(led2, HIGH);
    else
      digitalWrite(led2, LOW);
  }

}


