// Deze code werkt Uitsluitend voor de Arduino UNO
// Sla .mp3 of .wav bestanden op in de MP3 folder op de SD kaart
// Noem de bestanden 0001, 0002 etc (dus bijv. 0001.mp3)
// Sluit de MP3 speler aan op D2
// Als het ledje knippert op de MP3 speler dan speelt het geluid af

// De library voor de teller (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include <elapsedMillis.h> //verwijzing naar de library (extra code voor de teller)
elapsedMillis timeElapsed; // maakt een teller aan met de naam "timeElapsed"

// De library voor de afstandsensor (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include "Ultrasonic.h" //verwijzing naar de library van de afstandsensor
Ultrasonic ultrasonic(6); //DO: Steek de ultrasoon sensor in D6 van je Arduino

// De library voor de MP3 Player (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include "KT403A_Player.h"
#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(2, 3); //DO: Steek de MP3 player in D2 van je Arduino
KT403A<SoftwareSerial> Mp3Player;

int spelendNummer = 99; //globale variabele zodat je kunt bijhouden wel nummer als laatste gespeelt

void setup() {
  Serial.begin(9600); //DO: Zet je serial monitor op 9600
  SoftSerial.begin(9600); //Nodig om de MP3 speler aan te sturen
  Mp3Player.init(SoftSerial); //Nodig om de MP3 speler aan te sturen
}

void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);
  Serial.println(spelendNummer);

  if (afstand < 5) { // kleine afstand
    speelMP3(1);// welk audio file
    Serial.println("Kleine Afstand interactie");
  } else if (afstand < 10) {
    speelMP3(2);
    Serial.println("Medium Afstand interactie");
  } else if (afstand < 20) {
    speelMP3(3);
    Serial.println("Grote Afstand interactie");
  }
  delay(30);
}

// functie die afspeelt
void speelMP3(int nummer) {
  if (nummer != spelendNummer) {
    Mp3Player.playSongMP3(nummer); //Speel het geluid af (/MP3/0001.wav  of ./MP3/0001.MP3)
    spelendNummer = nummer;
  }
}
