// De library voor de teller (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include <elapsedMillis.h> //verwijzing naar de library (extra code voor de teller)
elapsedMillis timeElapsed; // maakt een teller aan met de naam "timeElapsed"

// De library voor de afstandsensor (zorg dat je deze geinstalleerd hebt via "Tools > Manage Libraies" )
#include "Ultrasonic.h" //verwijzing naar de library van de afstandsensor
Ultrasonic ultrasonic(6); //Steek de ultrasoon sensor in D6 van je Arduino

// De library voor de Servo (deze hoef je niet te installeren)
#include <Servo.h> //verwijzing naar de library van de servo
Servo mijnServo;  // Maak een servoObject aan met de naam 'mijnServo"

void setup() {
  Serial.begin(9600);
  mijnServo.attach(8);  // //Steek de servo in D8 van je Arduino
}

void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);

  if (afstand < 5) { // hij is heel BANG!!!
    wiebel(10, 60, 50);// hoekStart,  hoekEinde,  snelheid
  } else if (afstand < 10) {
    wiebel(10, 30, 200);// hoekStart,  hoekEinde,  snelheid
  } else if (afstand < 20) {
    wiebel(10, 160, 200);// hoekStart,  hoekEinde,  snelheid
  }

  delay(30);
}

// functie die laat wiebelen
void wiebel(int hoekStart, int hoekEinde, int snelheid)
{
  if (timeElapsed < snelheid) { //zolang de teller minder dan 1000 is, doe onderstaande
    mijnServo.write(hoekEinde);   // draai de servo naar 170 graden
  } else if (timeElapsed < (snelheid * 2)) { // zolang de teller niet onder 1000 wel onder de 2000 is:
    mijnServo.write(hoekStart);   // draai de servo naar 10 graden
  } else { // in de andere gevallen (dus NIET <1000 of <2000) doe dan:
    timeElapsed = 0; //begin opnieuw met tellen van Milliseconden
  }
}
