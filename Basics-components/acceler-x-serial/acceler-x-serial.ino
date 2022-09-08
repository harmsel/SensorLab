// installeer de library "ADXL345.h" via Sketch -> Include Library -> Manage library
#include <Wire.h> // sluit de accelerometer aan op I2C
#include <ADXL345.h>
ADXL345 adxl;

void setup() {
  Serial.begin(9600);
  adxl.powerOn();

}

void loop() {
  int x, y, z;
  adxl.readXYZ(&x, &y, &z);  //lees the accelerometer waardes en sla ze op in variabelen
  Serial.print("x: ");  Serial.println(x); //stuur de waarde van x naar de serial monitor
  delay(40);//vertragen zodat de serial monitor leesbaarder is
}
