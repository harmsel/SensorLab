#include <elapsedMillis.h>
elapsedMillis verstrekenTijd1;

void setup() {
  pinMode(3, OUTPUT);  //LED
  pinMode(5, OUTPUT);  //LED
}

void loop() {

  if (verstrekenTijd1 == 1000) {  //zolang de teller minder dan 1000 is, doe onderstaande regel:
    digitalWrite(3, LOW);        // Zet de led aan (bij deze led: LOW = aan, HIGH = uit)

  } else if (verstrekenTijd1 == 2000) {  // zolang de teller niet onder 1000 wel onder de 2000 is:
    digitalWrite(3, HIGH);
    verstrekenTijd = 0;     

 delay(1);// zorg dat de output in Serial monitor beter leeesbaar is   
}