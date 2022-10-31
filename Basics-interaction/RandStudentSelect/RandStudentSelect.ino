// laat de studenten er een voor een op drukken
// 3 studenten krijgen feedback
// het is mogelijk dat er minder dan 3 studenten geselecteerd worden (want de kans bestaat dat randnr1,2, of 3 gelijk zijn...)

#include <elapsedMillis.h>  //installeer de lapsedMillis.h library (van Peter Freerick)
elapsedMillis verstrekenTijd1;

#include <Adafruit_NeoPixel.h>
//Installeer de 'Adafruit_NeoPixel.h' library via je Arduino interface

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

const int buttonPin = 6;         // DE LED/KNOP  op D5
const int ledPin = 5;            // DE LED/KNOP komt op D5
const int trilPin = 2;           // TRILMOTOR op D2
const int aantalLeerlingen = 6;  //is je klas veel groter, pas gerust aan

// Varretjes
int doeEenKeer = 0;
int randnr1;
int randnr2;
int randnr3;
int teller;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trilPin, OUTPUT);
  Serial.begin(9600);


  randomSeed(analogRead(0));  //nodig voor de randomizerrr
  randnr1 = random(aantalLeerlingen);
  randnr2 = random(aantalLeerlingen);
  randnr3 = random(aantalLeerlingen);

  Serial.print("Winnende nummers: ");
  Serial.print(randnr1);
  Serial.print(", ");
  Serial.print(randnr2);
  Serial.print(", ");
  Serial.println(randnr3);
  delay(1000);  //even tijd om de winnende nummers te kunnen lezen in je Serial Monitor

  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();  // Zet alle pixels uit
  pixels.show();

  SoftSerial.begin(9600);
  Mp3Player.init(SoftSerial);
}

void loop() {

  // lees de status van het knopje
  int reading = digitalRead(buttonPin);
  // Serial.print("state van de knop: "); Serial.println(reading);

  if (reading == LOW) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    if (reading == LOW) {  //twee keer meten of de knop nog dezelfde state heeft, voor de debounce
      Serial.print("Teller staat op: ");
      //Wacht 1 seconde
      delay(1000);
      digitalWrite(ledPin, LOW);
      teller++;
      Serial.println(teller);

      /// kijk of de teller staat op een getal uit de random lijst
      if (teller == randnr1 || teller == randnr2 || teller == randnr3) {
        //// ---- Als deze student geselecteerd is, doe onderstaande:

        Serial.println("------------------ We hebben een winnaar");
        digitalWrite(trilPin, HIGH);
        
        if (firsttime) {
          Serial.println("Als het ledje op de MP3 speler knippert dan speelt het geluid af");
          Mp3Player.playSongMP3(1);  //Speel het 1e geluid af (MP3/0001.wav  of MP3/0001.MP3)
          firsttime = false;           
        }
        for (int i = 0; i < NUMPIXELS; i++) {                // voor elke led
          pixels.setPixelColor(i, pixels.Color(0, 100, 0));  //255 is de max waarde
          pixels.show();                                     // stuur de bovenstaande kleur naar de betreffende led
          delay(DELAYVAL);                                   // pauze tussen het veranderen van de ledjes
          Serial.println("welke led staat aan: ");
          Serial.println(i);  //Geeft in de Serial monitor weer welke led aanstaat
        }
        delay(200);

        for (int x = 0; x < 30; x++) {
          delay(100);
          digitalWrite(ledPin, HIGH);

          delay(100);

          digitalWrite(ledPin, LOW);
        }
        for (int i = NUMPIXELS; i > 0; i--) {                // voor elke led
          pixels.setPixelColor(i, pixels.Color(100, 0, 0));  //255 is de max waarde
          pixels.show();                                     // stuur de bovenstaande kleur naar de betreffende led
          delay(DELAYVAL);                                   // pauze tussen het veranderen van de ledjes
          Serial.println("welke led staat aan: ");
          Serial.println(i);  //Geeft in de Serial monitor weer welke led aanstaat
        }
        pixels.clear();  // Zet alle pixels uit
        pixels.show();
        digitalWrite(trilPin, LOW);  //trillen uit
      }
    } else {
    
    }
    delay(100);
      firsttime = true;
  }
  delay(1);
}