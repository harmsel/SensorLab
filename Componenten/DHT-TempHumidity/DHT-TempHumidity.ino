#include "DHT.h" //Required libraries 
#define DHTpin 4 //Connect the sensor to D4 

DHT dht(DHTpin, DHT11); //If you don't have a default sensor you can change to DHT22 

void setup() { 
  Serial.begin(9600); 
  dht.begin(); 
} 

void loop() { 
  //Read the values from the sensor 
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 

  // Display the values in the serial monitor 
  Serial.print("temperature "); 
  serial.println(t, 1); //,1 to display the rounded temperature 
  Serial.print("humidity "); 

  serial.println(h, 1); //display rounded humidity 
  delay(100); //only useful to make the output readable (for us humans) 

} 
