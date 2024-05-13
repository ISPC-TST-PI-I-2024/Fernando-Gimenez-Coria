#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADRR 0x27
#define CANT_CAR 20
#define CANT_LIN 4


LiquidCrystal_I2C lcd(LCD_ADRR, CANT_CAR, CANT_LIN);

#define In_sensor 2  // Pin digital donde se conecta el sensor
#define tipo_sensor DHT11  // Tipo de sensor DHT11


DHT dht(In_sensor, tipo_sensor);

void setup() {
  Serial.begin(9600);  
  dht.begin();  // funcion para inicializar el sensor, pertenece a la libreria DHT.h
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(0, 0); // Posicionar el cursor en la primera fila y columna
  lcd.print("Humedad: ");
  lcd.setCursor(1, 0); // Posicionar el cursor en la segunda fila y columna
  lcd.print("Temperatura: ");
}

void loop() {
  float h = dht.readHumidity();  // Leemos la humedad
  float t = dht.readTemperature();  // Leemos la temperatura

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Error obteniendo los datos");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println(" %");

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

    
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor(1, 0);
  lcd.print("Temperatura: ");
  lcd.print(t);
  lcd.print(" *C");

  delay(2000);  // Esperamos 2 segundos antes de leer nuevamente
}