// Deze code werkt voor de Arduino UNO
// Sluit de MP3 speler aan op D3
// Als het ledje knippert op de MP3 speler dan speelt het geluid af

#include "KT403A_Player.h"
#include <SoftwareSerial.h>
#include <elapsedMillis.h>


SoftwareSerial SoftSerial(2, 3);
KT403A<SoftwareSerial> Mp3Player;
elapsedMillis timer1;

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  Mp3Player.init(SoftSerial);
}

void loop() {
  if (timer1 == 2000) {
    Serial.println("Start geluid");
    Mp3Player.playSongMP3(1); //Speel het 2e geluid af (/MP3/0002.wav  of ./MP3/0002.MP3)
    timer1 = 0;// zet de timer weer op 0
  }
  delay (1);//loop elke miliseconde, dat is snel genoeg
}
