#define motorPin 5

void setup()
{
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  // Gradually Increase Duty Cycle
  for(int i=0; i<255; i++)
  {
    analogWrite(motorPin, i);
    delay(20);
  }
  // Gradually Decrease Duty Cycle
  for(int i=255; i>0; i--)
  {
    analogWrite(motorPin, i);
    delay(50);
  }
}