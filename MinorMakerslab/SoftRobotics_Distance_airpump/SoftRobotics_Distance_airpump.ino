// --- CODE FOR ALL MAKERSLAB STUDENTS --- ///
// -- THIS CODE WIL MAKE PIN 13 (CONNECTED TO YOUR PUM AND SOLONOID) GO ON AND OFF DEPENDING ON THE DISTANCE TO THE SENSOR
// --- MAKE SURE YOUR TRIGGER PIN IS IN 10. AND YOUR ECHT PIN IS IN 11
// --- CHANGE THE VALUE FOR distance,blinkDelayOn and blinkDelayOff so it will suit you

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define LED_PIN 13  // Built-in LED

void setup() {
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    long duration;
    float distance;

    // Send ultrasonic signal
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Receive the echo signal
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;  // Calculate distance in cm

    int blinkDelayOn;
    int blinkDelayOff;

    if (distance >= 100) {
        blinkDelayOn = 2000; // Inflate 
        blinkDelayOff = 1000; // Deflate
    } else if (distance < 80 && distance >= 40) {
        blinkDelayOn = 1000; // Inflate 
        blinkDelayOff = 500; // Deflate
    } else if (distance < 40 && distance >= 20) {
        blinkDelayOn = 500; // Inflate 
        blinkDelayOff = 150; // Deflate
    } else {
        blinkDelayOff = 50;   // but for extra responsiveness)
    }

    digitalWrite(LED_PIN, LOW);
    delay(blinkDelayOn / 2);
    digitalWrite(LED_PIN, HIGH);
    delay(blinkDelayOff / 2);
}
