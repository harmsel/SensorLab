//meet de lichtwaarde met de lichtsensor en geef deze weer in de Serial monitor

void setup() {
  Serial.begin(9600);
}


void loop() {
  int lightValue = analogRead(A0); // Sluit de Lichtsensor aan op A0
  Serial.println(lightValue); //toon LightValue in de Serial Monitor
  delay(20); //wacht 0.020 seconds, voor makkelijker uitlezen van de waarde

}
