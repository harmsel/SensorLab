/* 
Download de library van https://docs.google.com/presentation/d/12U8IadAiUQjNEx98aDD0fd1mtR0EnsNKZbsV4iVlLh4/edit?usp=drive_link


Sla de mp3 bestanden op de SD card op zodat ze beginnen met 001 t/m 010
// dus bv. 001_goedgedaan.mp3 , 002_mooiweer.mp3 en 003.mp3

/--------basis operaties operations---------------/
mp3.play(); // zet de player op play
mp3.pause(); // zet de player op pauze
mp3.stopPlay();  
mp3.nextSong();
mp3.previousSong();
mp3.volumeUp();
mp3.volumeDown();
mp3.singleCycle();//speelt het huidige nummer in repeat

************************************************** **************************************************/

#include <SoftwareSerial.h>
#include "RedMP3.h"

#define MP3_RX 4  //Sluit de stekker aan op D3. 
//Zijn de stekkertjes los van de MP3 board? Dan sluit je die zo aan: Rood op VCC, Zwart op GND, Wit op RX, Geel op TX

#define MP3_TX 3
MP3 mp3(MP3_RX, MP3_TX);

void setup() {
}

void loop() {
  mp3.playWithVolume(1, 5);  //nummer van de file , volume (1 tot 30)
  delay(1500);
}
