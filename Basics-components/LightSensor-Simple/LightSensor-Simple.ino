void setup() {
  Serial.begin(9600); // connect serial monitor
}


void loop() {
  int lightValue = analogRead(A0); // read out and store in 'lightValue'
  Serial.println(lightValue); //Display LightValue in Serial Monitor
  delay(15); //wait 0.015 seconds, that makes reading easier

}
