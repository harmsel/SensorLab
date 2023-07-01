// Installeer de library voor de teller. Zoek op "elapsedMillis.h" by Peter Freerick. Via "Tools > Manage Libraies".
// Lukt het niet? Kijk dan naar de uitgebreide uitleg op de introductiepagina https://github.com/harmsel/Ubicomp-code
#include <elapsedMillis.h>  //verwijzing naar de library (extra code voor de teller)
elapsedMillis timer1;       // maakt een teller aan met de naam "timer1"
elapsedMillis timer2;       // maakt een teller aan met de naam "timer2"
elapsedMillis timer3;       // maakt een teller aan met de naam "timer2"

// De library voor de Servo (deze hoef je niet te installeren)
#include <Servo.h>  //verwijzing naar de library van de servo
Servo mijnServo;    // Maakt een servoObject aan met de naam 'mijnServo"

void setup() {
  Serial.begin(9600);
  mijnServo.attach(8);  // //Steek de servo in D8 van je Arduino
  mijnServo.write(10);  //de servo bij het opstarten naar 10 graden draaien
}

void loop() {
  int lichtWaarde = analogRead(A0);  // Sluit de Lichtsensor aan op A0
  Serial.println(lichtWaarde);       //toon lichtWaarde in de Serial Monitor

  /// - ALs je vinger op de sensor zit
  if (lichtWaarde < 300) {  //als je vinger op de sensor zit
    timer1 = 0;             //zet de timer op 0
    int randomNummer = random(100, 6000);

    while (timer1 < randomNummer) {
      lichtWaarde = analogRead(A0);
      if (lichtWaarde > 400) {  //als je vinger van de sensor gaat voor einde van de tijd
        Serial.println("VALSSPELER");
        wiebel(10, 20, 200);  // hoekStart,  hoekEinde,  snelheid
      }
      timer3 = 0;
    }

    // Na de while ----
    Serial.println("HAK HAK HAK HAK");

    mijnServo.write(150);
    delay(500);
    mijnServo.write(10);
  }

  delay(20);  //wacht 0.020 seconds, voor makkelijker uitlezen van de waarde
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// functie die laat wiebelen
void wiebel(int hoekStart, int hoekEinde, int snelheid) {
  if (timer2 < snelheid) {               //zolang de teller minder dan 1000 is, doe onderstaande
    mijnServo.write(hoekEinde);          // draai de servo naar 170 graden
  } else if (timer2 < (snelheid * 2)) {  // zolang de teller niet onder 1000 wel onder de 2000 is:
    mijnServo.write(hoekStart);          // draai de servo naar 10 graden
  } else {                               // in de andere gevallen (dus NIET <1000 of <2000) doe dan:
    timer2 = 0;                          //begin opnieuw met tellen van Milliseconden
  }
}
