// Code voor Ubicomp CMD Amsterdam. Door Harm van Vugt
//

// De library voor de teller (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include <elapsedMillis.h>     //verwijzing naar de library (extra code voor de teller)
elapsedMillis timer;  // maakt een timer deze gaat in milliseconden (1000 miliseconden = 1 seconde)
elapsedSeconds timerLED;  // timer voor het knipperen van de led van de winnaar

// De library voor de Ledstrip (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include <Adafruit_NeoPixel.h>
#define PIN 4         // Sluit de ledstrip aan op D4
#define NUMPIXELS 12 // aantal ledjes in je strip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int led1 = 5;         //Sluit een drukknop/LED aan op D5
int led2 = 7;         //Sluit een drukknop/LED aan op D7
int knop1 = 6;         //Sluit een drukknop/LED aan op D5
int knop2 = 8;         //Sluit een drukknop/LED aan op D7

bool gestart = false;
int randomNummer;
int score = 6; //bijhouiden van de score


// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(knop1, INPUT); //drukknop op D5
  pinMode(knop2, INPUT); //drukknop op D5
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pixels.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();            // Turn OFF all pixels ASAP
}

void loop() {

  int button1Gedrukt = !digitalRead(knop1);  //lees de knopwaarde in de variabele. (De ingedrukte knop in 0 dus met de ! keren we het om)
  int button2Gedrukt = !digitalRead(knop2);  //lees de knopwaarde in de variabele. (De ingedrukte knop in 0 dus met de ! keren we het om)

  if (!gestart && button1Gedrukt && button2Gedrukt) {
    gestart = true;
    randomNummer = random(700, 3000);
    Serial.print("randomNummer: ");    Serial.println(randomNummer);
    timer = 0;
    digitalWrite(led1, HIGH);  //LED gaat aan
    digitalWrite(led2, HIGH);  //LED gaat aan
  }
  if (timer > randomNummer) {
    digitalWrite(led1, LOW);  //LED gaat UIT
    digitalWrite(led2, LOW);  //LED gaat UIT

  }
  if (gestart && button1Gedrukt && (timer > randomNummer)) {
    Serial.print("KNOP 1 Wint-  reactesnelheid: ");
    Serial.println(timer - randomNummer);
    gestart = false;
    puntenBijhouden(-1);
    delay(400);


  } else if (gestart && button2Gedrukt && (timer > randomNummer)) {
    Serial.print("KNOP 22222 -- reactesnelheid: ");
    Serial.println(timer - randomNummer);
    gestart = false;
    puntenBijhouden(1);
    delay(400);//nodig voor debounce van de knop

  }
  delay(1);

}

//Functie voor het bijhouden van de punten
void puntenBijhouden(int winnaar) {
  score = score + winnaar;

  if (score == 0) {
    rondeWinnaar(0); // Rainbow-enhanced theaterChase variant
  } else if (score == 11) {
    rondeWinnaar(11); // Rainbow-enhanced theaterChase variant
  }

  pixels.clear();  // Set all pixel colors to 'off'
  pixels.setPixelColor(score, pixels.Color(0, 0, 100));
  pixels.show();  // Send the updated pixel colors to the hardware.
  Serial.println("Score: ");  Serial.println(score);

}
//Functie die de lestrip laat knipperen voor de winnaar
void rondeWinnaar(int pixNr) {
  for (int x = 0; x < 100; x++) {
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.setPixelColor(pixNr, pixels.Color(100, 0, 0));
    pixels.show();  // Send the updated pixel colors to the hardware.
    delay (500);
    pixels.clear();  // Set all pixel colors to 'off'
    pixels.setPixelColor(pixNr, pixels.Color(0, 100, 0));
    pixels.show();  // Send the updated pixel colors to the hardware.
  }

}
