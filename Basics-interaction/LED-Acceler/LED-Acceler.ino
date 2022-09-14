// installeer de library "ADXL345.h" (van Seeed Studio) via "Tools > Manage libraries"
#include <Wire.h>     // Sluit de accelerometer aan op I2C
#include <ADXL345.h>  // Neemt de library op in deze sketch
ADXL345 adxl;         // Maakt een object van de library aan met de naam "adxl". 


#include <Adafruit_NeoPixel.h>  //Deze library had je al eerder geinstalleerd, dus nogmaals installeren is niet nodig 
#define PIN 4                   // Sluit de ledstrip aan op D4
#define NUMPIXELS 16            // Dit zijn het aantal pixels in je ledstrip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); //noodzakelijk voor het weergeven van debug tekst in de Serial Monitor
  adxl.powerOn();     // Zet de I2C poort open voor je Accelerometer
  pixels.begin();     // noodzakelijk voor de aangesloten ledstrip
}

void loop() {
  int x, y, z;
  adxl.readXYZ(&x, &y, &z);  // Leest the accelerometer waardes, sla ze op in variabelen

  Serial.print("x: ");  Serial.println(x); // Geef alleen de waarde van x weer in de Serial Monitor

  int pixNr = (x / 10) + 5;
  pixels.clear();   // Set all pixel colors to 'off'
  pixels.setPixelColor(pixNr, pixels.Color(0, 150, 0)); // de nummers zijn de R, G, B waarden
  pixels.show();    // Stuur bovenstaande waarden voor pixels naar de Ledstrip
  delay(20);        //voor betere leesbaarheid van de serial monitor
}
