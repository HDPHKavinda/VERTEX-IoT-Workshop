
/*
   VERTEX IoT Workshop
   Practical 03: Tone Generation
 
   Goal: Generate different sound frequencies using an ESP32
   and a passive piezo buzzer.
 */

const int BUZZER_PIN = 32;  // GPIO connected to the passive buzzer

void setup() {
  /*
     Configure the buzzer connection.
    
     In this practical, we will use tone() to generate a
     repeating electrical signal at a chosen frequency.
    
     Frequency is measured in Hertz (Hz).
     A higher frequency generally produces a higher-pitched tone.
    
     Example:
     pinMode(BUZZER_PIN, OUTPUT);
   */

}

void loop() {
  /*
     Generate a tone using tone().
   
     tone() takes the pin number and frequency in Hertz.
    
     Example:
     tone(BUZZER_PIN, 1000);  // Generate a 1000 Hz tone
   
     Keep the tone playing for a short time using delay().
   
     Stop the sound using noTone().
   
     Example:
     noTone(BUZZER_PIN);
    
     Add a short pause before generating the next tone.

     Experiment with different frequencies:
      - 250 Hz: lower pitch
      - 500 Hz: medium-low pitch
      - 1000 Hz: higher pitch
    
     These are example frequencies. The audible result depends
     on the buzzer and its operating characteristics.
   */
}
