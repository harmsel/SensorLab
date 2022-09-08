#include <elapsedMillis.h> //installeer de lapsedMillis.h library (van Peter Freerick)
elapsedMillis verstrekenTijd1;
int ledPin = 5;  //Sluit de blauwe LED/KNOP aan op D5

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  if (verstrekenTijd1 == 1000) {  //zolang de teller minder dan 1000 is, doe onderstaande regel:
    digitalWrite(ledPin, LOW);        // Zet de led aan (bij deze led: LOW = aan, HIGH = uit)

  } else if (verstrekenTijd1 == 2000) {  // zolang de teller niet onder 1000 wel onder de 2000 is:
    digitalWrite(ledPin, HIGH);
    verstrekenTijd1 = 0;

    delay(1);// zorg dat de output in Serial monitor beter leeesbaar is
  }
}
