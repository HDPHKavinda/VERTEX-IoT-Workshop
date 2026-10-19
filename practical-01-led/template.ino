
/*
   VERTEX IoT Workshop
   Practical 01: LED Blinking
 */

void setup() {
  /*
     METHOD 1: Using the GPIO pin number directly
   
     pinMode() configures a GPIO pin as INPUT or OUTPUT.
     We use OUTPUT because the ESP32 must control the LED.
   
     The first argument is the GPIO pin number.
     The second argument is the pin mode.
   
     Example:
     pinMode(23, OUTPUT);
   
     However, if you change the LED pin later, you must
     update every place where that number appears.
   */

}

void loop() {
  /*
     Control the LED using digitalWrite().
   
     HIGH turns the LED ON, while LOW turns it OFF.
     delay() pauses execution; its argument is in milliseconds.
    
     Example:
     digitalWrite(23, HIGH);
     delay(1000);
     digitalWrite(23, LOW);
     delay(1000);
   */


  /*
     METHOD 2: Using a named constant
    
     Instead of repeating the GPIO number, define:
    
     const int LED_PIN = 23;
    
     Then use LED_PIN in both pinMode() and digitalWrite().
     If you move the LED to another GPIO, you only need to
     change the number in the constant declaration.
   
     Example:
     pinMode(LED_PIN, OUTPUT);
     digitalWrite(LED_PIN, HIGH);
    
     Try this approach after completing Method 1.
   */
}
