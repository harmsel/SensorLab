#include <ChainableLED.h> // Installeer de 'Grove-Chanaable RGB LED"
#define NUM_LEDS 3  //aantal LEDS die je gaat aansluiten
ChainableLED leds(5, 6, NUM_LEDS);  //Sluit aan op D5. Eerste is de input pin. Dus sluit aan 


byte power = 0;

void setup() {
  Serial.begin(9600); //zodat je de serial monitor kan uitlezen
}


void loop(){
  for (byte i=0; i<NUM_LEDS; i++)
  {
    if (i%2 == 0){
      leds.setColorRGB(i, power, 0, 0);
    } else { 
      leds.setColorRGB(i, 0, 255-power, 0);
    }
  }  
  power+= 10;
  
  delay(10);
}