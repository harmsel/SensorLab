#include "config.h"

// =================  SETUP =================== //
void setup() {
  Serial.begin(9600);

  /****** LEDS ledjes met Fastled lib***/
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );

  LEDsWifi();

}

// =================  LOOP =================== //
void loop() {
  delay(8000); //seconden tussen de loops

  Serial.println(teller1);
  //  start om de zoveel tijd het ophalen van de de wind
  if (firstRun || teller1 > 1000000) { //1.000.000 millis = 15 minuten
    teller1 = 0;
    firstRun = false;

    LEDsUpdate();
    WifiEnDataOphaal();
  }

  /******* Led Helderheid *******/
  unsigned int helderheid = map(analogRead(A0), 1, 600, 3, 150);
  FastLED.setBrightness(helderheid); FastLED.show();
}
