//code om zoner gebruik van een library interactie te timen zonder Delay
extern volatile unsigned long timer0_millis; //deze variabele niet veranderen

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(millis());

  if (millis() < 2000) {
    Serial.println("alles onder twee seconden");

  }  else if (millis() < 4000) {
    Serial.println("minder dan 4 seconden");

  }  else if (millis() < 6000) {
    Serial.println("minder dan 6 seconden");

  } else {
    // Millis op 0 zetten
    noInterrupts ();
    timer0_millis = 0;
    interrupts ();
  }
  delay (1);
}
