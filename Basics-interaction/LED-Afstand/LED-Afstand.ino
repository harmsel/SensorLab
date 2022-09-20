#include "Ultrasonic.h" // Deze heb je al geinstalleerd (zo niet, zoek op "Grove ultrasonic ranger" by Seeed Studio)
Ultrasonic ultrasonic(D6); //De ultrasoon sensor aan D6

#include <Adafruit_NeoPixel.h>// installeer "Adafruit_NeoPixel.h" via: Tools > Manage Libraies
#define PIN 4         // De ledstrip aansluiten op D4
#define NUMPIXELS 60 // het aantal ledjes in je strip, 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <elapsedMillis.h> /// installeer, als je dat nog niet gedaan had bij ToDo1,: "elapsedMillis.h" van Paul via: Tools > Manage Libraies
elapsedMillis timeElapsed;//maak een timer object aan met deze naam

int teller = 0;

void setup() {
  Serial.begin(9600);       // Code om je serial monitor te gebruiken
  pixels.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
    pixels.clear();  // Zet alle pixels uit
  pixels.show();             // Turn OFF all pixels ASAP
  pixels.setBrightness(50);  // Set helderheid  (max = 255)

 
}
void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);

  if (afstand < 5 ) {// we gaan er van uit dat de fles 30cm diep is
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.setPixelColor(40, pixels.Color(0, 150, 0));
    pixels.show();  // Stuur bovenstaande pixel update naar de strip
    
  } else if (afstand < 10 ) {
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.setPixelColor(5, pixels.Color(0, 150, 0));
    pixels.show();  // Stuur bovenstaande pixel update naar de strip
    
  }  else if (afstand < 15 ) {
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.show();  // Stuur bovenstaande pixel update naar de strip
  }  else {
    pixels.clear();  // Set all pixel colors to 'off'
        pixels.show();  // Stuur bovenstaande pixel update naar de strip
  }



  delay(30);// om de serial monitor leesbaarder te maken
}
