#include <CapacitiveSensor.h>

//50K - 50M tussen de pinnen. weerstand. Hoe groter des te gevoeliger

CapacitiveSensor   sensCap = CapacitiveSensor(11, 13);       // pin 13 is de sensor

void setup()
{
  //sensCap.set_CS_AutocaL_Millis(0xFFFFFFFF);     // zet autocalibrate uit (elke 20 seconden)
  Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long total1 =  sensCap.capacitiveSensor(30);

  Serial.println(millis() - start);        // performance in milliseconds
  Serial.println(total1);                  //  sensor output

  if (total1 > 2000){
    Serial.println("nu wil ik dat MADMAPPER iets gaat veranderen");
    }

  delay(20); //gewoon omdat het leven al snel genoeg gaat
}
