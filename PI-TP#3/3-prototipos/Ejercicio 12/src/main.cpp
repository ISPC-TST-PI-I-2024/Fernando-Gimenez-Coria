#include <Arduino.h>

#define btn1 34
#define led1 18
#define led2 5
#define led3 17
#define led4 16
#define led5 4
#define led6 0
#define led7 2
#define led8 15
#define T_debounce 500

int cuenta = 0;

void mostrar_cuenta(){

  Serial.println("se muestra cuenta en leds");

  if(cuenta > 5)
    digitalWrite(led1, HIGH);
  if(cuenta > 10)
    digitalWrite(led2, HIGH);
  if(cuenta > 15)
    digitalWrite(led3, HIGH);
  if(cuenta > 20)
    digitalWrite(led4, HIGH);
  if(cuenta > 25)
    digitalWrite(led5, HIGH);
  if(cuenta > 30)
    digitalWrite(led6, HIGH);
  if(cuenta > 35)
    digitalWrite(led7, HIGH);
  if(cuenta > 40)
    digitalWrite(led8, HIGH);
  if(cuenta > 45){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    cuenta = 0;
  }
    
} 

bool debounce (bool touch_actual){      //funcion debounce, devuelve true si el el pulsador continua en el mismo 
  bool last_t = touch_actual;           //despues de un retardo determinado por T_debounce
  
  delayMicroseconds(T_debounce);
  
  touch_actual = digitalRead(btn1);

  if(touch_actual == last_t)
    return true;
  else 
    return false;
  }

void setup() {

  Serial.begin(115200);
  pinMode(btn1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

}

void loop(){

bool pulso = debounce(digitalRead(btn1)) & digitalRead(btn1);

if (pulso == 0)
  cuenta++;
Serial.println(cuenta);
mostrar_cuenta();
delay(100);

}