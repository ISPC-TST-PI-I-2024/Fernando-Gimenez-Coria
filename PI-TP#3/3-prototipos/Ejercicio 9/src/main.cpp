#include <Arduino.h>

#define btn1 34
#define T_debounce 1000

bool touch_actual = 0;
bool touch_ant = 0;
int leds[] =  {18, 5, 17, 16, 4, 0, 2, 15};   //array con la direccion de puerto de cada LED 
bool secuencia[] = {1, 1, 0, 0, 1, 1, 0, 0};  //secuencia a desplazar
bool sec_temporal[8];                         //array auxiliar para guardar el desplazamiento

void mover_secuencia(){
   
    sec_temporal[0] = secuencia[7];           //asigno el ultimo valor de secuencia al primero de temporal

      for (byte i = 0; i < 7; i++){           //asigno el valor actual de secuencia al siguiente valor de temporal 
        sec_temporal[i+1] = secuencia[i];
        Serial.print(sec_temporal[i]);        //imprimo el array temporal para verificar el desplazamiento
      } 
      Serial.println();
      for (byte i = 0; i < 8; i++)            //escribo las salidas del controlador segun los valor de temporal
        digitalWrite(leds[i], sec_temporal[i]);
      
      for (byte i = 0; i < 8; i++)            //asigno a secuencia los valores de temporal
        secuencia[i] = sec_temporal[i];
      
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
  for (byte i = 0; i < 8; i++){
  pinMode(leds[i], OUTPUT);
  for (byte i = 0; i < 6; i++)
    digitalWrite(leds[i], secuencia[i]);
  }

}

void loop() {  
  
  touch_actual = digitalRead(btn1);

  if (debounce(touch_actual) && !touch_actual){
      mover_secuencia();
      delay(500);              
    }
  
}
