
// installeer de library 'pulseSensor Playground' via de library manager
// Aansluiten sensor:
//    GND van de sensor aan op GND
//    + van de sensor aan op 5V
//    S van de sensor op A0

// Onderstaande code heeft als doel om de 'Treshold' van je vinger/sensor te vinden.
// Kijk in de grafiek van de 'Serial Plotter' (via Tools > Serial Plotter) wat de bovenwaarde is van je hartslag. 
// Voer deze in hieronder bij Treshold. 
// kijk vervolgens in de Serial Monitor of je hartslag continue (omgeveer 80slagen per minuut) zichtbaar is (in tekst)

// Werkt dit goed? Open dan 'File > Pulse Sensor Playground > Getting_BPM_to_Monitor'
// voor hier de eerder gevonden Treshold in

int Threshold = 520;  //deze waarde aanpassen


int PulseSensorPurplePin = A0;  // Pulse Sensor connected to ANALOG PIN 0
int LED = LED_BUILTIN;          //  The on-board Arduion LED


int Signal;

// The SetUp Function:
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensorPurplePin);

  Serial.println("Signal " + String(Signal));


  if (Signal > Threshold) {
    digitalWrite(LED, HIGH);
    Serial.println("----- HARTSLAG ----")
  } else {
    digitalWrite(LED, LOW);
  }


  delay(20);
}
