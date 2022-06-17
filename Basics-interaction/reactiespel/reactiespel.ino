// Reactiespel waarbij je reactie gaat weergegeven worden in een ledstrip
// IDEE kun je ook samenspelen? (bijvoorbeeld 

#include <elapsedMillis.h>


elapsedMillis timerMillis;
elapsedSeconds timerSeconden;

int pushButton = 6;  //drukknop zit op D5 in dit voorbeeld
bool knopStart = false;
bool knopReactie = true;
int randomNummer =5 ;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);  //lees de input pin
  Serial.println(buttonState);

  if (!buttonState && !knopStart) {
    knopStart = true;
    randomNummer = random(4, 8);
    Serial.println("spel gestart");
    timerSeconden = 0;
  }
  if (buttonState && knopStart e&& (timerSeconden>1)) {
    Serial.println("Spel gestopt. Verschil in tijd: ");
    Serial.print(timerSeconden - randomNummer);
        knopStart = false;
  }


delay(40);
}
