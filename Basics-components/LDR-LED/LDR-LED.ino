void setup() {
  pinMode(3, OUTPUT);   //LED
  Serial.begin(9600); // aansluiten serial monitor
}

void loop() {

  int lichtWaarde = analogRead(A0);   // lees uit en sla op in ‘lichtWaarde’
  Serial.println(lichtWaarde); //Geef LichtWaarde weer in Serial Monitor
  delay(15); //0.015 seconden wachten, dat maakt uitlezen makkelijker

  
  if (lichtWaarde < 1000) { 
    digitalWrite(3, HIGH);   

  } else {
    digitalWrite(3, LOW);  
  }
}
