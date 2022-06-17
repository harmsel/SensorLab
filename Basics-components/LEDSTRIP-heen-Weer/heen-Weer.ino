#include <Adafruit_NeoPixel.h>

// STRIPPIE 111
#define PIN1 6         // als stekker op D6 zit
#define NUMPIXELS1 13  // aantal ledjes
Adafruit_NeoPixel pixels1(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
#define DELAYVAL1 500  // pauze tussen aan/uitgaan ledjes

/// STRIP 2

#define PIN2 8         // als stekker op D8 zit
#define NUMPIXELS2 13  // aantal ledjes
Adafruit_NeoPixel pixels2(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
#define DELAYVAL2 500  // pauze tussen aan/uitgaan ledjes



void setup() {
  Serial.begin(9600);  //altijd neem deze altijd op in je  code voor debuggen
  pixels.begin();      // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {


  // ----- optellen voor aanzetten van de ledjes ----
  for (int i = 0; i < NUMPIXELS1; i++) {
    pixels1.setPixelColor(i, pixels1.Color(0, 150, 150));  //i is de pixel (start bij 0)
    pixels1.show();                                        //stuur bovenstaande commando naar de pixels
    delay(DELAYVAL1);                                      // ff wachten...
    Serial.println(i);                                     // voor debuggen
  }

  // --- aftellen en uitzetten van de ledjes -----
  for (int i = NUMPIXELS; i >= 0; i--) {
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
    pixels2.show();
    delay(DELAYVAL);
    Serial.println(i);  // voor debuggen
  }
}