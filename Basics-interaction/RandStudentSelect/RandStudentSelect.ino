// Lekker gore met Delay code versie 1 voor les 1, wie maakt het nog leuker voor les 2?
// maak de opstelling en zet die klaar voor het begin van het Tech deel van je klas bij de ingang
// plak de trilsensor vast en sluit de Uno aan op een powerbank
// laat de studenten er een voor een op drukken
// 3 studenten krijgen feedback
// het is mogelijk dat er minder dan 3 studenten geselecteerd worden (want de kans bestaat dat randnr1,2, of 3 gelijk zijn...)

const int buttonPin = 6;    // DE LED/KNOP  op D5
const int ledPin = 5;      // DE LED/KNOP komt op D5
const int trilPin = 2;      // TRILMOTOR op D2
const int aantalLeerlingen = 25; //is je klas veel kleiner, pas gerust aan

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


  randomSeed(analogRead(0));//nodig voor de randomizerrr
  randnr1 = random(aantalLeerlingen);
  randnr2 = random(aantalLeerlingen);
  randnr3 = random(aantalLeerlingen);
  
  Serial.print("Winnende nummers: "); Serial.print (randnr1); Serial.print (", "); Serial.print (randnr2); Serial.print (", "); Serial.println (randnr3);
delay(1000);//even tijd om de winnende nummers te kunnen lezen in je Serial Monitor
}

void loop() {

  // lees de status van het knopje
  int reading = digitalRead(buttonPin);
     Serial.print("state van de knop: ");Serial.println(reading);

  if (reading == LOW) {
    digitalWrite(ledPin, HIGH);
    delay (100);
    if (reading == LOW) { //twee keer meten of de knop nog dezelfde state heeft, voor de debounce
      Serial.print("Teller staat op: ");
      //Wacht 1 seconde
      delay(1000);
      digitalWrite(ledPin, LOW);
      teller++;
      Serial.println(teller);

      /// kijk of de teller staat op een getal uit de random lijst
      if (teller == randnr1 || teller == randnr2 || teller == randnr3)
      {
        //// ---- Als deze student geselecteerd is, doe onderstaande:

        Serial.println("------------------ We hebben een winnaar");
        delay(200);

        for (int x = 0; x < 30; x++) {
          delay(100);
          digitalWrite(ledPin, HIGH);
          digitalWrite(trilPin, HIGH);
          delay(100);
          digitalWrite(trilPin, LOW);
          digitalWrite(ledPin, LOW);
        }
      }
    }  else {
    }
    delay(100);
  }
}
