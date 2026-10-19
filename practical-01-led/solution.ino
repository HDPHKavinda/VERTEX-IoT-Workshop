
/*
   VERTEX IoT Workshop
   Practical 01 - LED Blinking
   Reference Solution
 */

const int LED_PIN = 23;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
Add practical 1 LED blinking materials"