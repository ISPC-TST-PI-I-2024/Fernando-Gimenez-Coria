#include <Arduino.h>

int L1 = 0;
int L2 = 1;
int L3 = 2;
int L4 = 3;


void encender_rojos ()
  {digitalWrite(L1, LOW);
   digitalWrite(L2, HIGH);
   digitalWrite(L3, LOW);
   digitalWrite(L4, HIGH);
   }

   void encender_verdes ()
  {digitalWrite(L1, HIGH);
   digitalWrite(L2, LOW);
   digitalWrite(L3, HIGH);
   digitalWrite(L4, LOW);
   }

void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  Serial.begin(115200);
  Serial.println("Alternando entre rojos y verdes");

}

void loop() {
  encender_verdes();
  delay(1000);
  encender_rojos();
  delay(1000);
}
