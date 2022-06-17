#include <elapsedMillis.h>
elapsedMillis timeElapsed;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (timeElapsed > 500) {
    Serial.println("tijd is over");
    timeElapsed = 0;
  }
}
