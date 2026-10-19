
# Practical 01 — LED Blinking

**VERTEX IoT Workshop | ESP32 Fundamentals**

## Objective

Learn how to control an external LED using an ESP32 GPIO pin and understand how named constants make code easier to maintain.

## Learning Outcomes

By completing this practical, participants will learn to:

- Connect an LED with a current-limiting resistor.
- Configure a GPIO pin as an output.
- Control an output using `digitalWrite()`.
- Control timing using `delay()`.
- Understand the difference between using a direct pin number and a named constant.
- Write more maintainable embedded code.

## Components Required

- ESP32 development board
- Breadboard
- 1 LED
- 1 × 220 Ω resistor
- Jumper wires
- USB data cable
- Computer with Arduino IDE 2.0 or later

## Wiring

| Component | Connection |
|---|---|
| ESP32 GPIO 23 | 220 Ω resistor |
| Resistor other end | LED anode (long leg) |
| LED cathode (short leg) | GND |

Keep the resistor connected in series with the LED.

## Software Setup

1. Open Arduino IDE.
2. Ensure ESP32 board support is installed.
3. Connect the board using a USB data cable.
4. Select the appropriate board and serial port.
5. Open `template.ino`.
6. Complete the missing code sections.
7. Upload the sketch and observe the LED.
8. Complete the second method after testing the first.

## Method 1 — Direct GPIO Number

Use the GPIO number directly in functions.

Example:

```cpp
pinMode(23, OUTPUT);
digitalWrite(23, HIGH);
```

This approach is easy to understand in a small example. However, if the LED moves to another GPIO, every occurrence of the pin number must be updated.

## Method 2 — Named Constant

Define the pin once at the top of the program.

```cpp
const int LED_PIN = 23;
```

Then use the constant in your functions:

```cpp
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, HIGH);
```

If you change the LED connection, update the constant declaration rather than searching through the entire program.

**Why use this method?**

Named constants improve readability, reduce repeated values, and make hardware changes easier. This is a useful coding practice for larger embedded systems.

> Complete and test one method at a time. Do not leave both implementations active together.

## Understanding the Main Functions

- `setup()` runs once when the ESP32 starts or resets.
- `loop()` runs repeatedly.
- `pinMode()` configures a GPIO pin.
- `digitalWrite()` sets the pin HIGH or LOW.
- `delay(1000)` pauses execution for approximately one second.

## Expected Output

The LED turns ON for approximately one second, turns OFF for approximately one second, and repeats continuously.

## Challenges

1. Change the blink interval to 500 milliseconds.
2. Make the LED stay ON longer than it stays OFF.
3. Move the LED to another suitable GPIO and update the code.
4. Explain why a named constant is useful.

## Troubleshooting

**LED does not turn on**
- Check LED polarity and resistor connections.
- Confirm the selected GPIO matches the wiring.
- Check the GND connection.

**Sketch does not upload**
- Check the selected board and serial port.
- Confirm that the USB cable supports data transfer.
- Check whether your board requires a USB driver.

## Files

- `template.ino` — participant starter code
- `solution.ino` — complete reference implementation

## Safety

Disconnect USB power before changing wiring. Always use a current-limiting resistor with the external LED.
