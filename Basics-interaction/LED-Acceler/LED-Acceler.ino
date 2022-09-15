// LET OP! Deze code werkt uitsluitend voor de 1.5 accelemeter
// Kijk op de achterkant van de sensor of het een 1.5g of een 16g versie betreft

// installeer de library "ADXL345.h" (van Seeed Studio) via "Tools > Manage libraries"
#include <Wire.h>     // Sluit de accelerometer aan op I2C
#include <ADXL345.h>  // Neemt de library op in deze sketch
ADXL345 accelemeter;         // Maakt een object van de library aan met de naam "adxl".


#include <Adafruit_NeoPixel.h>  //Deze library had je al eerder geinstalleerd, dus nogmaals installeren is niet nodig 
#define PIN 4                   // Sluit de ledstrip aan op D4
#define NUMPIXELS 16            // Dit zijn het aantal pixels in je ledstrip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <elapsedMillis.h>      // installeer (als je dat nog niet gedaan had bij ToDo1): "elapsedMillis.h" van Paul via: Tools > Manage Libraies
elapsedMillis stopWatch;      // maakt een timer object aan met de naam "stopWatch".

void setup() {
  Serial.begin(9600); //noodzakelijk voor het weergeven van debug tekst in de Serial Monitor
  accelemeter.powerOn();     // Zet de I2C poort open voor je Accelerometer
  pixels.begin();     // noodzakelijk voor de aangesloten ledstrip
  pixels.setBrightness(50);  // Set helderheid (max = 255)
}

void loop() {
  int x, y, z;
  accelemeter.readXYZ(&x, &y, &z);  // Leest the accelerometer waardes, sla ze op in variabelen

  Serial.print("x: ");  Serial.println(x); // Geef alleen de waarde van x weer in de Serial Monitor

  int pixNr = (x / 20) + 5;
  pixels.clear();   // Set all pixel colors to 'off'
  pixels.setPixelColor(pixNr, pixels.Color(0, 150, 0)); // de nummers zijn de R, G, B waarden
  pixels.show();    // Stuur bovenstaande waarden voor pixels naar de Ledstrip


  /// Pas de code hieronder aan zodat regenboogfunctie afgaat als de fles 5 seconden rechtop staat
  if (x > -20 && x < 20) { //de hoek van de fles (is 8 wel rechtop?)
    Serial.println(stopWatch);
    if (stopWatch > 2000) { // na 2 seconden wachten
      rainbowCycle(1, 3); // start de functie. Geef de wachttijd en herhalingen mee
      stopWatch = 0; //Zet de stopwatch na 10 seconden weer op 0 voor een volgende keer
    } else if (stopWatch > 3000) {
      stopWatch = 0; //Zet de stopwatch na 10 seconden weer op 0 voor een volgende keer
    }
  }

  delay(20);        //voor betere leesbaarheid van de serial monitor
}

// --- Hieronder de functies ----
// mooie regenboog functie, die had je al eerder gezien...
void rainbowCycle(uint8_t wait, int herhalingen) {
  uint16_t i, j;
  for (j = 0; j < 256 * herhalingen; j++) { // 2 cycles of all colors on wheel
    for (i = 0; i < pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Deze functie wordt door andere kleurenfuncties gebruikt.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
