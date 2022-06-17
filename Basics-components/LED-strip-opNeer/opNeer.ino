
/// maak varibele aan
int getal = 10;
#include <Adafruit_NeoPixel.h>
#define PIN        6 // als stekker op D6 zit
#define NUMPIXELS 13 // aantal ledjes 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // pauze tussen aan/uitgaan ledjes

void setup() {
  Serial.begin(9600); //altijd neem deze altijd op in je  code voor debuggen
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {


  if (getal > 100) {
    getal = getal - 1;

    pixels.setPixelColor(getal, pixels.Color(0, 150, 150)); //i is de pixel (start bij 0)
    pixels.show();//stuur bovenstaande commando naar de pixels

    
    Serial.println(getal);
  } else {
    
    getal = getal + 1;
    Serial.println(getal);

    pixels.setPixelColor(getal, pixels.Color(0, 0, 0));
    pixels.show();
    delay(DELAYVAL);
    
  }

}
