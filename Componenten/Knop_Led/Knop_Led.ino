// Sluit de LED en de KNOP aan op 
const int buttonPin = 3;  // sluit de knop/led aan op D2
const int ledPin = 2;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Lees de knop uit in deze var
  buttonState = digitalRead(buttonPin);

  // LET OP!  Als de knop ingedrukt is dan is je buttonstate LOW, beetje verwarrend maar je moet gewoon omgekeerd denken ;-)
  if (buttonState == HIGH) {
    // doe het ledje aan
    digitalWrite(ledPin, LOW);
  } else {
    // ledje uit
    digitalWrite(ledPin, HIGH);
  }
}
