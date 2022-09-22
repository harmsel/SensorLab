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
  Serial.print("afstand: ");
  Serial.println(afstand);

  // -- code voor het uitlezen van de accelerometer
  int8_t x, y, z;
  accelemeter.getXYZ(&x, &y, &z);
  Serial.print("x = ");
  Serial.println(x);  // geef de waarde van x weer in de serial monitor, handig voor testen en debuggen

  /// --  code zodat de LED regenboog feedback gaat geven als de fles leeg (afstand meer dan 30 cm) is
  if (afstand > 30) {  // we gaan er van uit dat de fles 30cm diep is
    Serial.println("De fles is leeg");
    rainbowCycle(5, 1);  // functie aanroep met waarden: (snelheid, herhalingen)
  } else {
    colorWipe(pixels.Color(0, 0, 0), 50);  // Red
  }

  // - code waardoor de LED regenboog feedback gaat geven als hij rechtop (x tussen -2 en 2) staat
  if (x < 2 && x > -2) {  // mijn fles staat redelijk recht als x tussen -2 en 2 zit, zijn jouw waarden anders als de fles recht staat, pas de waardes gerust aan
    Serial.println("De fles staat recht");
  }

  delay(30);  //wacht even elke Loop, om de serial monitor leesbaarder te maken
}




/// -------- Hieronder de functies die je  kunt aanroepen -- //
///--------------------------------------------------------- //

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


// Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for (long firstPixelHue = 0; firstPixelHue < 1 * 65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    pixels.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    pixels.show();  // Update strip with new contents
    delay(wait);    // Pause for a moment
  }
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < pixels.numPixels(); i++) {  // For each pixel in strip...
    pixels.setPixelColor(i, color);               //  Set pixel's color (in RAM)
    pixels.show();                                //  Update strip to match
    delay(wait);                                  //  Pause for a moment
  }
}
