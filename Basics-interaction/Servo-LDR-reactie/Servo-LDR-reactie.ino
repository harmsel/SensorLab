// Installeer de library voor de teller. Zoek op "elapsedMillis.h" by Peter Freerick. Via "Tools > Manage Libraies".
// Lukt het niet? Kijk dan naar de uitgebreide uitleg op de introductiepagina https://github.com/harmsel/Ubicomp-code
#include <elapsedMillis.h>  //verwijzing naar de library (extra code voor de teller)
elapsedMillis timer1;       // maakt een teller aan met de naam "timeElapsed"


// De library voor de Servo (deze hoef je niet te installeren)
#include <Servo.h>  //verwijzing naar de library van de servo
Servo mijnServo;    // Maakt een servoObject aan met de naam 'mijnServo"

void setup() {
  Serial.begin(9600);
  mijnServo.attach(8);  // //Steek de servo in D8 van je Arduino
}

void loop() {
  int lichtWaarde = analogRead(A0);  // Sluit de Lichtsensor aan op A0
  Serial.println(lichtWaarde);       //toon lichtWaarde in de Serial Monitor


  if (lichtWaarde < 50) {  //als je vinger op de sensor zit
    timer1 = 0;            //zet de timer op 0
    int randomNummer = random(100, 6000);
     mijnServo.write(10);
    while (timer1 < randomNummer) {
 
      if (lichtWaarde > 500) {  //als je vinger van de sensor gaat voor einde van de tijd
                                // je speelt vals!!
        mijnServo.write(170);
        delay(500);
        mijnServo.write(10);
        delay(500);
      }
    }

    mijnServo.write(170);
    Serial.print("Reactiesnelheid: ");
    Serial.println(timer1);
    timer1 = 0;


    delay(20);  //wacht 0.020 seconds, voor makkelijker uitlezen van de waarde
  }