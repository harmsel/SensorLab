// installeer de library "ADXL345.h" via Sketch -> Include Library -> Manage library
// Prik de ledstrip in D7
// sluit de accelerometer aan op I2C

#include <Wire.h>
#include <ADXL345.h>
ADXL345 adxl;


#include <Adafruit_NeoPixel.h>
#define PIN 7         // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16  // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  adxl.powerOn();
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  int x, y, z;
  adxl.readXYZ(&x, &y, &z);  //read the accelerometer values and store them in variables  x,y,z

  Serial.print("x: ");
  Serial.println(x);

  int pixNr = (x / 10) + 5;
  pixels.clear();  // Set all pixel colors to 'off'
  pixels.setPixelColor(pixNr, pixels.Color(0, 150, 0));
  pixels.show();  // Send the updated pixel colors to the hardware.
  delay(20);
}