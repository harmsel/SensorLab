/// --- MAKERSLAB soft robotics CODE: button push will open the solonoid
/// -------------------------------------------- ///



// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  //// ---- --------- BUTTON PART --------- --------- ---------
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  /// --------- --------- ---------DISTANCE SENSOR PART  --------- ---------

  distance = hc.dist();
  delay(50);
  Serial.println(distance);

  // ----- interaction
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
    delay (200);
        digitalWrite(ledPin, LOW);
    delay (200);
    
  }
}
