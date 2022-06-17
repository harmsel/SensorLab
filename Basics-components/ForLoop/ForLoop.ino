void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    // begin ; einde ;  optellen
    Serial.println(i);
  }

  for (int i = 10; i >= 0; i--) {
    // begin ; einde ;  aftellen
    Serial.println(i);
  }
}