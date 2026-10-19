
/*
 * VERTEX IoT Workshop
 * Practical 03: Tone Generation
 * Reference Solution
 */

const int BUZZER_PIN = 32;

void setup() {
  // Configure the GPIO pin connected to the passive buzzer.
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Generate a 500 Hz tone.
  tone(BUZZER_PIN, 500);
  delay(500);

  // Stop the tone before playing the next one.
  noTone(BUZZER_PIN);
  delay(200);

  // Generate a higher-pitched 1000 Hz tone.
  tone(BUZZER_PIN, 1000);
  delay(500);

  // Stop the tone and pause before repeating the sequence.
  noTone(BUZZER_PIN);
  delay(1000);
}
