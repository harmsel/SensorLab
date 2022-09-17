// CHECK EERST DE VERSIE VAN JE Accelerometer SENSOR via deze pagina: https://github.com/harmsel/Ubicomp-code
// Deze code werkt uitsluitend voor de 1.5g accelemeter (er is uiteraard ook een code voor de 16g sensor beschikbaar)
#include "MMA7660.h"  // installeer "MMA7660.h via: Tools > Manage Libraies
MMA7660 accelemeter;  // Sluit de Accelerometer aan op een van de I2C connectoren op je UNO (maakt niet uit welke)

#include "Ultrasonic.h"    // Deze heb je al geinstalleerd (zo niet, zoek op "Grove ultrasonic ranger" by Seeed Studio)
Ultrasonic ultrasonic(6);  //De ultrasoon sensor aan D6

// -- deze library en instellingen zijn nodig voor je ledstrip
#include <Adafruit_NeoPixel.h>  // installeer "Adafruit_NeoPixel.h" via: Tools > Manage Libraies
#define PIN 4                   // De ledstrip aansluiten op D4
#define NUMPIXELS 16            // het aantal ledjes in je strip,
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <elapsedMillis.h>  // installeer, als je dat nog niet gedaan had bij ToDo1,: "elapsedMillis.h" van Paul via: Tools > Manage Libraies
elapsedMillis timeElapsed;  //maak een timer object aan met deze naam

int teller = 0;

void setup() {
  Serial.begin(9600);        // Code om je serial monitor te gebruiken
  pixels.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();             // Turn OFF all pixels ASAP
  pixels.setBrightness(50);  // Set helderheid  (max = 255)

  accelemeter.init();
}
void loop() {

  // Code voor de afstandsensor
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);

  // -- code voor de accelerometer
  int8_t x, y, z;
  accelemeter.getXYZ(&x, &y, &z);
  Serial.print("x = ");
  Serial.println(x);  // geef de waarde van x weer in de serial monitor, handig voor testen en debuggen


  /// --  code zodat de LED regenboog feedback gaat geven als de fles leeg (afstand meer dan 30 cm) is
  if (afstand > 30) {  // we gaan er van uit dat de fles 30cm diep is
    Serial.println("de fles is leeg");
    rainbowCycle(5, 1);  // functie aanroep met waarden: (snelheid, herhalingen)
  }

  // - code waardoor de LED regenboog feedback gaat geven als hij rechtop (x tussen -2 en 2) staat
  if (x < 2 && x > -2) {  // we gaan er van uit dat de fles 30cm diep is
    rainbowLoopt();       // functie aanroep met waarden: (snelheid, herhalingen)
    Serial.println("de fles staat recht");
  }
  delay(30);  // om de serial monitor leesbaarder te maken
}



/// -------- Hieronder de functies die je in de loop kunt aanroepen
///-------------------------------------------------------------------

// mooie regenboog functie
void rainbowCycle(uint8_t wait, int herhalingen) {
  uint16_t i, j;
  for (j = 0; j < 256 * herhalingen; j++) {  // 2 cycles of all colors on wheel
    for (i = 0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}


//Regenboog theater effect
void rainbowLoopt() {
  for (int j = 0; j < 26; j++) {  // cycle all 26 colors
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, Wheel((i + j) % 255));  // elke 3e pixel aan
      }
      pixels.show();
      delay(20);
      for (uint16_t i = 0; i < pixels.numPixels(); i = i + 3) {
        pixels.setPixelColor(i + q, 0);  //elke 3e weer uit
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