/* Aansluiten op je arduino board:
- VCC  op 5V (of 3V bij de NodeMCU)
- GND op GND
- OUT op A0

Uitleg sensor: geluid zijn trillingen. Het is geen constante waarde. Veel geluid betekend dat de trillingen ver uit slaan, 
tussen de trillingen is er echter niet veel te meten. Daarom meet onderstaande code gedurende een bepaalde periode de
hoogte van meerdere trillingen. Daar komt een gemiddelde uit, dat gemiddelde wordt weergegeven. 
De volledige uitleg: https://lastminuteengineers.com/max4466-arduino-tutorial/

Tip: gebruik ook de Serial Plotter weergave (Arduino > Tools > Serial Plotter) om het goed te kunnen zien.

*/

const int sampleWindow = 50;  // welke frequentie van geluid wil je meten? Dat geef je hier aan in milliseconden (50 mS = 20Hz)
int const AMP_PIN = A0;       // Hier zit de OUT aan vast van de sensor
unsigned int sample;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned long startMillis = millis(); // Start met het nemen van samples
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // verzamele data for 50 mS, geef het daarna weer
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(AMP_PIN);
    if (sample < 1024)  // verwijder rare sample waarden
    {
      if (sample > signalMax)
      {
        signalMax = sample;  // bewaard de max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample;  // bewaar de min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;  // max - min = totale amplitude (geluidsdruk)
  Serial.println(peakToPeak);
  //double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
  //Serial.println(volts);
}