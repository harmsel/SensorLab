// CHECK DE VERSIE VAN JE SENSOR op deze pagina: https://github.com/harmsel/Ubicomp-code
// Deze code werkt uitsluitend voor de 1.5 accelemeter

#include "MMA7660.h"
MMA7660 accelemeter;

void setup() {
  Serial.begin(9600);
  accelemeter.init();

}
void loop() {
  int8_t x, y, z;
  accelemeter.getXYZ(&x, &y, &z);
  Serial.print("x = ");  Serial.println(x);
  delay(20);
}
