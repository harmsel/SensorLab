// Installeer de library voor de afstandsensor zoek op "Grove ultrasonic ranger" by Seeed Studio
#include "Ultrasonic.h"    //verwijzing naar de library van de afstandsensor
Ultrasonic ultrasonic(6);  //Steek de ultrasoon sensor in D6 van je Arduino


int trilPin = 2;  //sluit de trilmotor aan op D2

void setup() {
  pinMode(trilPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long afstand = ultrasonic.MeasureInCentimeters();
  Serial.println(afstand);

  if (afstand < 5) {  // hij is heel BANG!!!
    digitalWrite(trilPin, HIGH);
  } else {
    digitalWrite(trilPin, LOW);
  }
  delay(20);

  }
