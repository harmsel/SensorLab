// CHECK DE VERSIE VAN JE SENSOR
// Deze code werkt uitsluitend voor de 1.5 accelemeter
// Kijk op de achterkant van de sensor of het een 1.5g of een 16g betreft
// De code voor de 16g staat ook op deze Github


#include "MMA7660.h"
MMA7660 accelemeter;

void setup() {
  Serial.begin(9600);
  accelemeter.init();

}
void loop() {
  int8_t x; int8_t y; int8_t z;
  accelemeter.getXYZ(&x, &y, &z);

  Serial.print("x = ");  Serial.println(x);


  delay(20);
}
