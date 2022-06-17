#include <Wire.h>
#include <ADXL345.h>
ADXL345 adxl; //variable adxl is an instance of the ADXL345 library

void setup(){
  Serial.begin(9600);
  adxl.powerOn();
}

void loop(){
  

	int x;  
	adxl.readXYZ(x); //lees de 

	Serial.print("x: ");	Serial.println(x);
	
	delay(500);
}
