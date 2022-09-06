#include <Servo.h>

Servo myservo;  // Maakt het servo object

void setup() {
  myservo.attach(8);  // Verbind de servo op D8
}

void loop() {
  myservo.write(10);                  // draai de servo naar 10 graden, op 0 graden gaat deze vaak trillen
  delay(5000);                           // 1 seconde wachten
  myservo.write(170);                  // draai de servo naar 170 graden, op 180 graden gaat soms vaak trillen
  delay(5000);   
}
