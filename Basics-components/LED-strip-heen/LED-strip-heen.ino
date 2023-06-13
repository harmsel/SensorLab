#include <Adafruit_NeoPixel.h>
//Installeer de 'Adafruit_NeoPixel.h' library via je Arduino interface

#define PIN 4         // Steek de ledstrip in D4
#define NUMPIXELS 13  // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50  // pauze tussen aan/uitgaan ledjes in miliseconden

void setup() {
  Serial.begin(9600);  //neem deze altijd op in je  code voor debuggen
  pixels.begin();      // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();      // Zet alle pixels uit
}

void loop() {


  for (int i = 0; i < 3; i++) {
    pixels.setPixelColor(i, pixels.Color(100, 0, 0));  //255 is de max waarde
    Serial.println(i);
    pixels.show();
    delay(500);
  }


  for (int i = 2; i < 1; i--) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));  //255 is de max waarde
    Serial.println(i);
    pixels.show();
    delay(500);
  }
}

//   for (int i = 3; i < 6; i++) {                        // voor elke led
//     pixels.setPixelColor(i, pixels.Color(100, 0, 0));  //255 is de max waarde
//   }


//   pixels.show();    // stuur de bovenstaande kleur naar de betreffende led
//   delay(DELAYVAL);  // pauze tussen het veranderen van de ledjes
//   Serial.println("welke led staat aan: ");
//   Serial.println(i);  //Geeft in de Serial monitor weer welke led aanstaat
// }
// for (int i = NUMPIXELS; i > 0; i--) {                // voor elke led
//   pixels.setPixelColor(i, pixels.Color(100, 0, 0));  //255 is de max waarde
//   pixels.show();                                     // stuur de bovenstaande kleur naar de betreffende led
//   delay(DELAYVAL);                                   // pauze tussen het veranderen van de ledjes
//   Serial.println("welke led staat aan: ");
//   Serial.println(i);  //Geeft in de Serial monitor weer welke led aanstaat
// }
// }
