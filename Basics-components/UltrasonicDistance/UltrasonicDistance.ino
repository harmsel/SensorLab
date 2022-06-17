#include "Ultrasonic.h" 
Ultrasonic ultrasonic(7); 

void setup() { 
  Serial.begin(9600); 
} 

void loop() { 
  long RangeInCentimeters; //variable for storing the distance 
  RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
  Serial.println(RangeInCentimeters);//0~400cm 
  delay(50);//short time between measurements 
} 
