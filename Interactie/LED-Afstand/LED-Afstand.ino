#include <NewPing.h>  // Zoek de library "NewPing" (van Tim Eckel) en installeer deze

#define PIN 6             // Sluit de Sensor aan op D6
#define MAX_DISTANCE 200  // Maximale meetafstand, wil je minder ver meten? Maak dan deze max_distance kleiner om je respons tijd van je sensor te verhogen
NewPing sonar(PIN, PIN, MAX_DISTANCE);  // Pin komt twee keer voor, want de eerste is voor de trigger de tweede voor de echo

#include <Adafruit_NeoPixel.h>// installeer "Adafruit_NeoPixel.h" via: Tools > Manage Libraies
#define PIN 4         // De ledstrip aansluiten op D4
#define NUMPIXELS 16 // het aantal ledjes in je strip, 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <elapsedMillis.h> /// installeer, als je dat nog niet gedaan had bij ToDo1,: "elapsedMillis.h" van Paul via: Tools > Manage Libraies
elapsedMillis timeElapsed;//maak een timer object aan met deze naam

int teller = 0;

void setup() {
  Serial.begin(9600);       // Code om je serial monitor te gebruiken
  pixels.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();             // Turn OFF all pixels ASAP
  pixels.setBrightness(10);  // Set helderheid naar 1/5 (max = 255)

}
void loop() {
  long afstand = sonar.ping_cm();
  Serial.println(afstand);

  /// --  code waardoor het niveau in groene leds is weergegeven
  int pixNr = (afstand / 2);
  pixels.clear();  // Set all pixel colors to 'off'
  pixels.setPixelColor(pixNr, pixels.Color(0, 150, 0));
  pixels.show();  // Stuur bovenstaande pixel update naar de strip

  // ---  Code die de positieve feedback start
  // We gaan er van uit dat de afstandsensor in de dop van de fles zit. Deze afstand meet de afstand tot het vloeistof oppervlakte
  // Als je een slok uit de fles neemt 'ziet' de sensor de bodem van de fles. Dan krijg je positieve feedback op je slok.
  // doe je de fles weer rechtop, dan meet de sensor niet meer de bodem van de fles
  // Als je de fles leeg hebt, blijft ook de feedback doorgaan

  if (afstand > 30 ) {// we gaan er van uit dat de fles 30cm diep is
   rainbowCycle(5, 1); // functie aanroep met waarden: (snelheid, herhalingen)
  } 
  delay(30);// om de serial monitor leesbaarder te maken
}


/// -------- Hieronder de functies die je in de loop kunt aanroepen
///-------------------------------------------------------------------

// mooie regenboog functie
void rainbowCycle(uint8_t wait, int herhalingen) {
  uint16_t i, j;
  for (j = 0; j < 256 * herhalingen; j++) { // 2 cycles of all colors on wheel
    for (i = 0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}


//Regenboog theater effect
void rainbowLoopt() {
  for (int j=0; j < 26; j++) {     // cycle all 26 colors 
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, Wheel( (i+j) % 255));   // elke 3e pixel aan
      }
      pixels.show();
      delay(20);
      for (uint16_t i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //elke 3e weer uit
      }
    }
  }
}

// Deze functie wordt door andere kleurenfuncties gebruikt.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
