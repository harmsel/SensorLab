// CHECK DE VERSIE VAN JE SENSOR. Dit is de 16g code.
// Deze code werkt uitsluitend voor de 16g accelemeter
// Kijk op de achterkant van de sensor of het een 16g of een 1.5g betreft


// installeer de library "ADXL345.h" via Sketch -> Include Library -> Manage library
#include <Wire.h> // sluit de accelemeter aan op I2C
#include <ADXL345.h>
ADXL345 accelemeter;

void setup() {
  Serial.begin(9600);
  accelemeter.powerOn();

}

void loop() {
  int x, y, z;
  accelemeter.readXYZ(&x, &y, &z);  //lees the accelerometer waardes en sla ze op in variabelen
  Serial.print("x: ");  Serial.println(x); //stuur de waarde van x naar de serial monitor
  delay(40);//vertragen zodat de serial monitor leesbaarder is
}
