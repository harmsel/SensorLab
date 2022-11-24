const int aantalLeerlingen = 12;  //pas gerust aan
const int buttonPin = 6;         // LED/KNOP op D5
const int ledPin = 5;            // LED/KNOP op D5
const int trilPin = 2;           // TRILMOTOR op D2








////---------- hier alle libs aanroepen ----

#include <elapsedMillis.h>  //installeer de lapsedMillis.h library (van Peter Freerick)
elapsedMillis verstrekenTijd1;

#include <Adafruit_NeoPixel.h>//Installeer de 'Adafruit_NeoPixel.h' library via je Arduino interface

#define PIN 4         // Steek de ledstrip in D4
#define NUMPIXELS 17  // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 50  // pauze tussen aan/uitgaan ledjes in miliseconden

#include "KT403A_Player.h"
#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(2, 3);  //Sluit de MP3 speler aan op D2
KT403A<SoftwareSerial> Mp3Player;

#include <elapsedMillis.h>  //Library van Paul Stoffregen
elapsedMillis timer1;       //Dit maakt een timer aan met de naam

int firsttime = true;

// Varretjes
int doeEenKeer = 0;
int randnr1 = 0;
int randnr2= 0;
int randnr3 = 0;
int teller;