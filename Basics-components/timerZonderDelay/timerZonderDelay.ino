extern volatile unsigned long timer0_millis;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.println(millis());

  if (millis() < 2000) {
    Serial.println("EEEEEEEEN");
    
  }  else if (millis() < 4000) {
    Serial.println("Tweeeeee");
    
  }  else if (millis() < 6000) {
    Serial.println("333333 3- 3-3 -3 -3-3- ");

  } else {
    // Millis op 0 zetten
    noInterrupts ();
    timer0_millis = 0;
    interrupts ();
  }
delay (20);
  
}
