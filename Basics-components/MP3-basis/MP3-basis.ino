/* Deze code werkt Uitsluitend voor de Arduino UNO
Geluiden opslaan op de micro SD kaart in de MP3 speler:
1. Gebruik .mp3 of .wav bestanden 
2. Noem de bestanden 0001.mp3, 0002.mp3 etc
3. zet de bestanden in een map met de naam 'MP3'

Library installeren voor de MP3 speler:
1. Download de files (zip) van https://github.com/Seeed-Studio/Seeed_Serial_MP3_Player 
2. Unzip en plaats 'Seeed_Serial_MP3_Player-master' in de library map. (Bij mij: /Users/harm/Documents/Arduino/libraries)
*/

#include "KT403A_Player.h" 
#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(2, 3);//Sluit de MP3 speler aan op D2
KT403A<SoftwareSerial> Mp3Player;

#include <elapsedMillis.h> //Library van Paul Stoffregen
elapsedMillis timer1;//Dit maakt een timer aan met de naam

void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);
  Mp3Player.init(SoftSerial);
}

void loop() {
  if (timer1 == 4000) {
    Serial.println("Als het ledje op de MP3 speler knippert dan speelt het geluid af");
    Mp3Player.playSongMP3(1); //Speel het 1e geluid af (MP3/0001.wav  of MP3/0001.MP3)
    timer1 = 0;// zet de timer weer op 0
  }
  delay (1);//loop elke miliseconde, dat is snel genoeg
}
