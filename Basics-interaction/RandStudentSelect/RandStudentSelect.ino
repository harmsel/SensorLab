
#include "config.h"

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trilPin, OUTPUT);
  Serial.begin(9600);


  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();  // Zet alle pixels uit
  pixels.show();

  SoftSerial.begin(9600);
  Mp3Player.init(SoftSerial);
}

void loop() {

  if (randnr1 == randnr2 || randnr1 == randnr3 || randnr2 == randnr3) {
    randomSeed(analogRead(0));  //nodig voor de randomizerrr
    randnr1 = 1 + random(aantalLeerlingen);
    randnr2 = 1 + random(aantalLeerlingen);
    randnr3 = 1 + random(aantalLeerlingen);

    Serial.print("Winnende nummers: ");
    Serial.print(randnr1);
    Serial.print(", ");
    Serial.print(randnr2);
    Serial.print(", ");
    Serial.println(randnr3);
  }

  // lees de status van het knopje
  int reading = digitalRead(buttonPin);
  // Serial.print("state van de knop: "); Serial.println(reading);

  if (reading == LOW) {
    delay(100);
    if (reading == LOW) {  //twee keer meten of de knop nog dezelfde state heeft, voor de debounce
      digitalWrite(ledPin, HIGH);
      Serial.print("Teller staat op: ");
      //Wacht 1 seconde
      delay(1000);
      digitalWrite(ledPin, LOW);
      teller++;
      Serial.println(teller);

      /// kijk of de teller staat op een getal uit de random lijst
      if (teller == randnr1 || teller == randnr2 || teller == randnr3) {

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