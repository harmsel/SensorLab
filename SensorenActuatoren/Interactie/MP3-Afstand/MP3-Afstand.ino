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

// Installeer elapsedMillis.h van Paul Stoffregen via "Tools > Manage Libraies" 
#include <elapsedMillis.h> //verwijzing naar de library (extra code voor de teller)
elapsedMillis verstrekenTijd; // deze code maakt een teller aan met de naam "verstrekenTijd"

#include <NewPing.h>  // Zoek de library "NewPing" (van Tim Eckel) en installeer deze

#define PIN 6             // Sluit de Sensor aan op D6
#define MAX_DISTANCE 200  // Maximale meetafstand, wil je minder ver meten? Maak dan deze max_distance kleiner om je respons tijd van je sensor te verhogen
NewPing sonar(PIN, PIN, MAX_DISTANCE);  // Pin komt twee keer voor, want de eerste is voor de trigger de tweede voor de echo

int spelendNummer = 99; //globale variabele zodat je kunt bijhouden wel nummer als laatste gespeelt

void setup() {
  Serial.begin(9600); //DO: Zet je serial monitor op 9600
  SoftSerial.begin(9600); //Nodig om de MP3 speler aan te sturen
  Mp3Player.init(SoftSerial); //Nodig om de MP3 speler aan te sturen
}

void loop() {
  long afstand = sonar.ping_cm();
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

// functie die afspeelt, maar niet de hele tijd start
void speelMP3(int nummer) {
  if (nummer != spelendNummer) {
    Mp3Player.playSongMP3(nummer); //Speel het geluid af (/MP3/0001.wav  of ./MP3/0001.MP3)
    spelendNummer = nummer;
  }
}
