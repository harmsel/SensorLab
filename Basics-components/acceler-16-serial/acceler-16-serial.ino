// CHECK DE VERSIE VAN JE SENSOR op deze pagina: https://github.com/harmsel/Ubicomp-code
// Onderstaande code werkt UITSLUITEND met de 16g accelemeter


// installeer de library "ADXL345.h" via Sketch -> Include Library -> Manage library
// sluit de accelemeter aan op I2C
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
