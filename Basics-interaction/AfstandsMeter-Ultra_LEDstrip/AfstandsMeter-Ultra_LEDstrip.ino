#include "Ultrasonic.h"

#include <Adafruit_NeoPixel.h>
#define PIN 7         // de pin waar je de ledstrip wilt aansluiten
#define NUMPIXELS 16 // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Ultrasonic ultrasonic(3);
void setup() {
  Serial.begin(9600);
  pixels.begin();
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