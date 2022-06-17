#include <Wire.h>
#define Addr 0x53

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(Addr);
  Wire.write(0x2C);
  Wire.write(0x0A);
  Wire.endTransmission();

  delay(300);
}

void loop()
{
  unsigned int data[6];
  for (int i = 0; i < 6; i++)
  {
    // I2C code 
    Wire.beginTransmission(Addr);
    Wire.write((50 + i));
    Wire.endTransmission();
    Wire.requestFrom(Addr, 1);
    if (Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }

  // Convert the data to 10-bit
  int xAccl = (((data[1] & 0x03) * 256) + data[0]);
  if (xAccl > 511) {
    xAccl -= 1024;
  }

  if  (xAccl > 45 || xAccl < 20) {

    Serial.println("Triggerrrrrr");
  }

  Serial.print("X-Axis is : "); Serial.println(xAccl);

  delay(300);
}
