#include <Arduino.h>

//En este programa, mediante los switches sw1.1 a sw1.4 vamos a ciclar tres secuencias de leds distintas
//segun indiquen sw1.1 y sw1.2 (en la posicion 00 se apagan todos los led) 
//sw1.3 indicara el sentido de la secuencia 
//sw1.4 indicara la velocidad (rapido y lento )
//Secuencias representadas como matrices

int sw1[4] = {13, 12, 14, 27};
bool conf_sw[4];
int leds[] =  {18, 5, 17, 16, 4, 0, 2, 15};   //array con la direccion de puerto de cada LED 
int sec_sel = 0; 
int sec_dir = 0; 
int sec_vel = 0; 


bool sec_1[8][8] = {{1, 1, 0, 0, 1, 1, 0, 0},    //secuencia 1
                    {0, 1, 1, 0, 0, 1, 1, 0},    //
                    {0, 0, 1, 1, 0, 0, 1, 1},    //
                    {1, 0, 0, 1, 1, 0, 0, 1},    //
                    {1, 1, 0, 0, 1, 1, 0, 0},    //
                    {1, 1, 0, 0, 1, 1, 0, 0},    //
                    {0, 1, 1, 0, 0, 1, 1, 0},    //
                    {0, 0, 1, 1, 0, 0, 1, 1},    //
                    };                           //

//-------------------------------------------------------------------------------------                    

bool sec_2[8][8] = {{1, 0, 1, 0, 1, 0, 1, 0},    // secuencia 2
                    {0, 1, 0, 1, 0, 1, 0, 1},    //
                    {1, 0, 1, 0, 1, 0, 1, 0},    //
                    {0, 1, 0, 1, 0, 1, 0, 1},    //
                    {1, 0, 1, 0, 1, 0, 1, 0},    //
                    {0, 1, 0, 1, 0, 1, 0, 1},    //
                    {1, 0, 1, 0, 1, 0, 1, 0},    //
                    {0, 1, 0, 1, 0, 1, 0, 1},    //
                    };

//------------------------------------------------------------------------------------

bool sec_3[8][8] = {{0, 0, 0, 1, 1, 0, 0, 0},    // secuencia 3
                    {0, 0, 1, 1, 1, 1, 0, 0},    //
                    {0, 1, 1, 0, 0, 1, 1, 0},    //
                    {1, 1, 0, 0, 0, 0, 1, 1},    //
                    {1, 0, 0, 0, 0, 0, 0, 1},    //
                    {1, 1, 0, 0, 0, 0, 1, 1},    //
                    {0, 1, 1, 0, 0, 1, 1, 0},    //
                    {0, 0, 1, 1, 1, 1, 0, 0},    //
                    };

//------------------------------------------------------------------------------------                    



void mover_secuencia(bool secuencia[8][8], int vel, int dir){
   
    if (dir == 1){
      for (byte i = 0; i < 8; i++){
        for (byte j = 0; j < 8; j++){
          digitalWrite(leds[j], secuencia[i][j]);
        }
      delay(500 * (1 + vel));
      }
    }
      
}



void setup() {

  Serial.begin(115200);
  
  for (byte i = 0; i < 8; i++)
    pinMode(leds[i], OUTPUT);

  for (byte i = 0; i < 8; i++)
    digitalWrite(leds[i], LOW);

  for (byte i = 0; i < 4; i++)
    pinMode(sw1[i], INPUT_PULLUP);

}

void loop() {  
  
  for (byte i = 0; i < 4; i++)
    conf_sw[i] = digitalRead(sw1[i]);

  sec_sel = conf_sw[0] * 1 + conf_sw[1] * 2;
  sec_dir = conf_sw[2];
  sec_vel = conf_sw[3];

  switch (sec_sel)
  {
  case 0:
    for (byte i = 0; i < 8; i++)
    digitalWrite(leds[i], LOW);
    break;

  case 1:
    mover_secuencia(sec_1, sec_vel, sec_dir);
    break;

  case 2:
    mover_secuencia(sec_2, sec_vel, sec_dir);
    break;

  case 3:
    mover_secuencia(sec_3, sec_vel, sec_dir);
    break;  
  default:
    break;
  }
  
}
