// De library voor de Afstandssensor (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include "Ultrasonic.h"
Ultrasonic ultrasonic(3);

// De library voor de Ledstrip (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include <Adafruit_NeoPixel.h>
#define PIN 4         // Sluit de ledstrip aan op D4
#define NUMPIXELS 16 // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600); // Code om je serial monitor te gebruiken
  pixels.begin();//NOdig voor de Ledstrip
}
void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);
  int pixNr = (afstand /2);
  pixels.clear();  // Set all pixel colors to 'off'
  pixels.setPixelColor(pixNr, pixels.Color(0, 150, 0));
  pixels.show();  // Send the updated pixel colors to the hardware.

  delay(30);
}