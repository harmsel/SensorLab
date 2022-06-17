#include <Servo.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(7);

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  long RangeInCentimeters; //variabele voor het opslaan van de afstand
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  Serial.println(RangeInCentimeters);//0~400cm
  delay(50);// korte tijd tussen metingen


  if (RangeInCentimeters < 30) {
    myservo.write(10);                  // draai de servo naar 10 graden, op 0 graden gaat deze vaak trillen
    delay(100);                           // 1 seconde wachten
    myservo.write(40);                  // draai de servo naar 170 graden, op 180 graden gaat soms vaak trillen
    delay(100);
  }
}
