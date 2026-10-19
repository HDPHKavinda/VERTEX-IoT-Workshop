
/*
 * VERTEX IoT Workshop
 * Practical 02: Buzzer Control
 * Reference Solution
 */

const int BUZZER_PIN = 23;

void setup() {
  // Configure the GPIO pin to control the buzzer.
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Activate the buzzer.
  digitalWrite(BUZZER_PIN, HIGH);

  // Keep it active for half a second.
  delay(500);

  // Deactivate the buzzer.
  digitalWrite(BUZZER_PIN, LOW);

  // Wait one second before repeating.
  delay(1000);
}
