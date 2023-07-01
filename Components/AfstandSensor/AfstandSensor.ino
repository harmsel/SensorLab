#include "Ultrasonic.h" // Zoek de library "Grove Ultrasonic" en installeer deze
Ultrasonic ultrasonic(6); //aansluiten op D6

void setup() { 
  Serial.begin(9600); 
} 

void loop() { 
  long afstand; //variable for storing the distance 
  afstand = ultrasonic.MeasureInCentimeters(); 
  Serial.println(afstand);//
 delay(50);//even wachten tussen de metingen voor leebaarheid
} 
