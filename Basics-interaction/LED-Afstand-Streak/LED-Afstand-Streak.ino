#include "Ultrasonic.h"    // Deze heb je al geinstalleerd (zo niet, zoek op "Grove ultrasonic ranger" by Seeed Studio)
Ultrasonic ultrasonic(6);  // De ultrasoon sensor aan D6

#include <elapsedMillis.h>  // Deze heb je al geinstalleerd (zo niet zoek naar: "elapsedMillis.h" van Paul)
elapsedMillis timer;        // maak een timer object aan met deze naam

#include <FastLED.h> // installeer de library "FastLED.h" Daniel Garcia. Via Sketch -> Include Library -> Manage library: Fastled by Daniel Garcia

FASTLED_USING_NAMESPACE

#define DATA_PIN 4  //Ledstrip aan D4 (of port 4 for Micro)
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 16  //number of leds in the strip
CRGB leds[NUM_LEDS];

int colorChange = 8;  //Default = 8. Delay of speed of changing color, higher numer is slower
int colorCycle = 20;  //Default = 20, higher number is slower
uint8_t gHue = 0;     // rotating "base color" used by many of the patterns

int teller = 0;
bool slokjeToggle = 0;
int aantalSlokken = 0;

void setup() {
  delay(2000);  // 2 seconden wachten voor opstarten van de de ledstrip
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(50);//helderheid, max is 255
}


/// ------------  Hier start de LOOPY LOOPY LOOP ---------- ///

void loop() {
  //Voor het uitlezen van de afstandsensor
  long afstand = ultrasonic.MeasureInCentimeters();
  //Serial.println(afstand); //haal de '//' weg als je wilt debuggen



  // we gaan er van uit dat de afstandssensor op de fles zit en meet of de gebruiker de fles pakt (dus de hand komt dichtbij)
  // Bij het pakken van de fles (dus het nemen van een slok) we de gebruiker een positieve feedback (blauwe looplicht)
  // Als de gebruiker 5 slokken heeft genomen krijgt de gebruiker rainbowGlitter feedback, gedurende enkele seconden


  // Dit if statement kijkt of iemand de fles vast heeft gepakt en weer terug heeft gezet (losgelaten), het slaat het aantal slokken op in 'aantalSlokken'
  if (afstand < 11) {
    slokjeToggle = true;
  } else {
    if (slokjeToggle) {
      aantalSlokken++;
      slokjeToggle = false;  //De toggle is bedoelt om de overgang tussen vastpakken en terugzeggen te meten
    }
  }

// dit if statement zet de led effecten aan en uit bij het nemen van een slok en het terugzetten
  if (afstand < 11 && aantalSlokken != 5 && aantalSlokken != 10) {  
    sinelon(128);                            //Number is color: RED = 0, ORANGE = 32, YELLOW = 64, GREEN = 96, AQUA = 128, BLUE = 160, PURPLE = 192, PINK = 224
    Serial.println("Je neemt nu een slokje!");

  } else if (aantalSlokken != 5 && aantalSlokken != 10) {
    ledsUit();
    Serial.println("Je hebt de fles niet vast");
    timer = 0;  //Deze timer gaan we uitlezen als er 5 slokken zijn genomen
  }


// dit if statement zorgt er voor dat de gebruiker na 5 slokken rainbow glitter feedback krijgt, gedurende 3 seconden
  if (aantalSlokken == 5) {
    if (timer < 3000) {  //als de fles lang leeg is, geef dan regenboog glitter weer
      rainbowWithGlitter();
      Serial.println(" 5 slokken genomen, lekker bezig!");
    } else {
      ledsUit();
    }
  }

  Serial.println(aantalSlokken);  //Geeft het aantal slokken weer in de Serial Monitor

  // -- het lijstje leuke ledeffecten. Test ze gerust, maar niet tegelijkertijd ;-)
  // rainbowWithGlitter() ;
  // rainbow() ;
  // confetti();
  // juggle();
  // sinelon(128); //Number is color: RED = 0, ORANGE = 32, HUE_YELLOW = 64, HUE_GREEN = 96, HUE_AQUA = 128, HUE_BLUE = 160, HUE_PURPLE = 192, HUE_PINK = 224
  // bpm(162); //number is speed, in BPM

  delay(1);  //om de serial monitor minder hard te laten werken
}









/*------------------------------------------------------------------------------------
  ------------------ Hieronder de functies die je in de loop kunt aanroepen ---------- 
  ------------------ Als je dit niet goed begrijpt is dat geen probleem     ---------- */
  
void ledsUit() {
  FastLED.clear();  // clear all pixel data
  FastLED.show();
}
void rainbow() {
  FastLED.show();
  FastLED.delay(colorChange);
  EVERY_N_MILLISECONDS(colorCycle) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }

  // FastLED's built-in rainbow generator
  fill_rainbow(leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter() {
  FastLED.show();
  FastLED.delay(colorChange);
  EVERY_N_MILLISECONDS(colorCycle) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter(fract8 chanceOfGlitter) {
  if (random8() < chanceOfGlitter) {
    leds[random16(NUM_LEDS)] += CRGB::White;
  }
}

void confetti() {
  FastLED.show();
  FastLED.delay(colorChange);
  EVERY_N_MILLISECONDS(colorCycle) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }

  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy(leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV(gHue + random8(64), 200, 255);
}

void sinelon(uint8_t gHue) {
  FastLED.show();
  FastLED.delay(colorChange);

  fadeToBlackBy(leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS - 1);
  leds[pos] += CHSV(gHue, 255, 192);  //HUE_RED = 0, HUE_ORANGE = 32, HUE_YELLOW = 64, HUE_GREEN = 96, HUE_AQUA = 128, HUE_BLUE = 160, HUE_PURPLE = 192, HUE_PINK = 224
}

void bpm(uint8_t BeatsPerMinute) {
  FastLED.show();
  FastLED.delay(colorChange);
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)

  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
  for (int i = 0; i < NUM_LEDS; i++) {  //9948
    leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

void juggle() {
  FastLED.show();
  FastLED.delay(colorChange);
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy(leds, NUM_LEDS, 20);
  uint8_t dothue = 0;
  for (int i = 0; i < 8; i++) {
    leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}