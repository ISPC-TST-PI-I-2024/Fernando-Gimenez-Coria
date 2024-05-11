#include <Arduino.h>

#define COMB 35
#define btn1 34
#define btn2 39
#define btn3 36
#define led1 18
#define led2 5


int cuenta_btn1 = 0;
int cuenta_btn2 = 0;
int confirmacion = 0;

void setup() {
  Serial.begin(115200);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int i = 0;
  while (i <= 5000)
  {
  i++;    
  int estado_btn1 = digitalRead(btn1);
  int estado_btn2 = digitalRead(btn2);
  int estado_btn3 = digitalRead(btn3);

  // Verificar si se ha pulsado algún botón
  if (estado_btn1 == LOW) {
    cuenta_btn1++;
    Serial.print(cuenta_btn1); // Incrementar contador de btn1
    delay(200); 
  } else if (estado_btn2 == LOW) {
    cuenta_btn2++;
    Serial.print(cuenta_btn2); // Incrementar contador de btn2
    delay(200);
  } else if (estado_btn3 == LOW) {
    confirmacion = 1;
    Serial.print("confirmar!"); 
    delay(200);
  }
  }

  // Si se han registrado todas las pulsaciones necesarias
  if (cuenta_btn1 > 0 && cuenta_btn2 > 0 && confirmacion == 1) {
    // Construir la combinación basada en la cantidad de veces que se ha pulsado cada botón
    int combination = cuenta_btn1 * 10 + cuenta_btn2;

    // Verificar si la combinación ingresada coincide con la combinación esperada
    if (combination == COMB) { 
      digitalWrite(led1, HIGH); // Combinación correcta, encender led1
    } else {
      digitalWrite(led2, HIGH); // Combinación incorrecta, encender led2
    }

    
    delay(2000); 
    cuenta_btn1 = 0;
    cuenta_btn2 = 0;
    confirmacion = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}

