#include <NewPing.h>  // Zoek de library "NewPing" (van Tim Eckel) en installeer deze

#define PIN 6             // Sluit de Sensor aan op D6
#define MAX_DISTANCE 200  // Maximale meetafstand, wil je minder ver meten? Maak dan deze max_distance kleiner om je respons tijd van je sensor te verhogen
NewPing sonar(PIN, PIN, MAX_DISTANCE);  // Pin komt twee keer voor, want de eerste is voor de trigger de tweede voor de echo

void setup() {
  Serial.begin(9600);  // Open serial monitor op 9600
}

void loop() {
  long afstand = sonar.ping_cm();
  Serial.println(afstand);
  delay(50);  // 50 ms tussen metingen. 29 ms is minimaal
}