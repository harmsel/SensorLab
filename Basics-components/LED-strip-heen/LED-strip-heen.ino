#include <Adafruit_NeoPixel.h>
//Installeer de 'Adafruit_NeoPixel.h' library via je Arduino interface

#define PIN        4 // Steek de ledstrip in D4
#define NUMPIXELS 13 // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100 // pauze tussen aan/uitgaan ledjes in miliseconden

void setup() {
  Serial.begin(9600); //neem deze altijd op in je  code voor debuggen
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) { // voor elke led
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();   // stuur de bovenstaande kleur naar de betreffende led
    delay(DELAYVAL); // pauze tussen het veranderen van de ledjes
    Serial.println("welke led staat aan: "); Serial.println(i); //Geeft in de Serial monitor weer welke led aanstaat

  }
  pixels.clear(); // Zet alle pixels uit
}
