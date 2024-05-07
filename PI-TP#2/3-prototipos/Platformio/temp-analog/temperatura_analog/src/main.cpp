#include <Arduino.h>

int pinAnalog = 1;           //es la direccion del pin que voy a usar para leer el NTC
double tempNTC = 0;             //aqui se guarda el voltaje que arroja el NTC tomado por analogRead()
double temp_celcius = 0;      //aqui se guarda el valor a imprimir luego de hacer la conversion
int lect_bruto = 0;




void t_centigrados ()            //funcion para convertir el valor del NTC a grados centigrados
    {
      const float BETA = 3950; // should match the Beta Coefficient of the thermistor
      lect_bruto = analogRead(pinAnalog);
      tempNTC = lect_bruto * (3.3/8191);
      Serial.print("La lectura de ADC es: ");
      Serial.println(lect_bruto, 3);
      Serial.print("El voltaje de entrada suministrado por el sensor es: ");
      Serial.println(tempNTC);
      double Rntc = 10000.0 * tempNTC / (3.3 - tempNTC);
      temp_celcius = (1 / (1/298.15+((log(Rntc/10000.0))/BETA)))-273.15;
    }


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Este programa toma el valor de temperatura analogico arrojado por \n");
  Serial.println("el sensor NTC cada 1 segundo, convierte el valor a grados celcius y luego\n");
  Serial.println("imprime el resultado en la consola\n");

  pinMode(1, INPUT);
}

void loop() {
  while (true)
    {
      t_centigrados();
      Serial.print("La temperatura es: ");
      Serial.print(temp_celcius, 5);
      Serial.print(" Grados centigrados\n");
      delay(1000);
    }
  
}
