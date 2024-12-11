#include <CapacitiveSensor.h>
#include "MIDIUSB.h"
#include <elapsedMillis.h>
elapsedMillis wachtFF1;
elapsedMillis wachtFF2;
elapsedMillis wachtFF3;
int wachtTijd = 500;
int oudeSensorWaarde;

//50K - 50M Higher resistro is more sensitive
CapacitiveSensor   sensCap = CapacitiveSensor(12, 11);       // pin 11 yellow, pin 12 white. Black is the sensor wire



void setup()
{
  //sensCap.set_CS_AutocaL_Millis(0xFFFFFFFF);     // zet autocalibrate uit (elke 20 seconden)
  Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long sensorWaarde =  sensCap.capacitiveSensor(30);

 // Serial.print(millis() - start);        // performance in milliseconds
  Serial.println(sensorWaarde);                  //  sensor output

if (sensorWaarde != oudeSensorWaarde){
  Serial.println("verschil in waarde");
  }

  oudeSensorWaarde = sensorWaarde;

  if (sensorWaarde > 1000) { //sensitivity
    noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
    MidiUSB.flush();
    if (wachtFF1 > wachtTijd) {
      wachtFF1 = 0; //de wekker weer op 0 zetten
      noteOff(0, 48, 64); 
      MidiUSB.flush();
    }

  } else if (sensorWaarde > 600) {//gevoeligheid
  //  Serial.println("S3");
    noteOn(0, 60, 64);   // Channel 0, C3, normal velocity
    MidiUSB.flush();

    if (wachtFF2 > wachtTijd) {
      wachtFF2 = 0; //de wekker weer op 0 zetten
      noteOff(0, 60, 64);  // Channel 0, middle C, normal velocity
      MidiUSB.flush();
    }

  } else {
   // Serial.println("c4");
    noteOn(0, 63, 64);   // Channel 0, C3, normal velocity
    MidiUSB.flush();
    if (wachtFF3 > wachtTijd) {
      wachtFF3 = 0; //de wekker weer op 0 zetten
      noteOff(0, 63, 64);  
      MidiUSB.flush();
    }
  }


  delay(20); //gewoon omdat het leven al snel genoeg gaat
}


  
void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
