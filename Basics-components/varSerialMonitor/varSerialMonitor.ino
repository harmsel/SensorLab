
/// maak varibele aan
int getal = 100;

void setup() {
  Serial.begin(9600); // aansluiten SM

}

void loop() {
  Serial.println(getal);

  if (getal < 100) {
    getal = getal + 1;
  } else {
    getal = 0;
  }

}
