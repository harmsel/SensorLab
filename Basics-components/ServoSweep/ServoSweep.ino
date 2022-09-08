#include <Servo.h>
Servo myservo;  // maakt een servo object aan

void setup() {
  myservo.attach(8);  // Sluit de servo aan op D8
  Serial.begin(9600);
}

void loop() {
    myservo.write(10); // draai de servo naar 10 graden
    Serial.println ("Draai naar 10 graden"); // Stuur een string naar de serial Monitor
    delay(1000);  // 1 seconde wachten
  
    myservo.write(170); // draai de servo naar 170 graden,
    Serial.println ("Draai naar 170 graden");  // Stuur een string naar de serial Monitor
    delay(1000); // 1 seconde wachten
}
