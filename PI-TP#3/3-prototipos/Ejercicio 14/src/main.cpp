#include <Arduino.h>


#define led1 18
#define led2 5
#define led3 17 
#define led4 16
int leds[] =  {18, 5, 17, 16};    //array con la direccion de puerto de cada LED 
bool secuencia[] = {1, 1, 0, 0};  //secuencia a desplazar
bool sec_temporal[4];             //array auxiliar para guardar el desplazamiento
bool avanzar = 0;

hw_timer_t *My_timer = NULL;

void mover_secuencia(){
   
    sec_temporal[0] = secuencia[3];           //asigno el ultimo valor de secuencia al primero de temporal

      for (byte i = 0; i < 4; i++){           //asigno el valor actual de secuencia al siguiente valor de temporal 
        sec_temporal[i+1] = secuencia[i];
      } 
      
      for (byte i = 0; i < 4; i++)            //escribo las salidas del controlador segun los valor de temporal
        digitalWrite(leds[i], sec_temporal[i]);
      
      for (byte i = 0; i < 4; i++)            //asigno a secuencia los valores de temporal
        secuencia[i] = sec_temporal[i];
      
}

void IRAM_ATTR onTimer(){
avanzar = true;
}



void setup() {
Serial.begin(115200);
for (byte i = 0; i < 4; i++)           
  pinMode(leds[i], OUTPUT);
My_timer = timerBegin(0, 80, true);
timerAttachInterrupt(My_timer, &onTimer, true);
timerAlarmWrite(My_timer, 1000000, true);
timerAlarmEnable(My_timer);
}

void loop() {
if (avanzar == 1){
mover_secuencia();
avanzar = 0;
}

Serial.println("Uso de timer 0 de ESP 32 con preescalador dividiendo ");
Serial.println("la frecuencia del clock por 80, dando como resultado ");
Serial.println("que la secuencia de LEDs avance cada un segundo ");

}