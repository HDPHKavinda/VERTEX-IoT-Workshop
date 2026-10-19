
# Practical 02 — Buzzer Control

**VERTEX IoT Workshop | Embedded Output Control**

## Objective

Control a buzzer using an ESP32 GPIO pin and learn how digital output signals can activate an electronic device.

## Learning Outcomes

- Configure a GPIO pin as an output.
- Control an output device using `digitalWrite()`.
- Use `delay()` to control timing.
- Understand the difference between activating a device and generating a tone.

## Components Required

- ESP32 development board
- Suitable low-current buzzer or buzzer module
- Breadboard
- Jumper wires
- USB data cable
- Computer with Arduino IDE 2.0 or later

## Wiring

| Component | Connection |
|---|---|
| Buzzer signal / positive terminal | ESP32 GPIO 23 |
| Buzzer GND / negative terminal | ESP32 GND |

Check the buzzer's specifications before connecting it directly to the ESP32. Use a suitable driver circuit if its current requirements exceed the GPIO's safe limits.

## Software Setup

1. Open Arduino IDE.
2. Select the appropriate ESP32 board and serial port.
3. Open `template.ino`.
4. Complete the missing code sections.
5. Verify and upload the sketch.
6. Listen for the buzzer's ON/OFF pattern.

## Expected Output

The buzzer activates for approximately 500 milliseconds, remains OFF for approximately one second, and repeats continuously.

## Understanding the Code

- `setup()` runs once after startup or reset.
- `loop()` repeats continuously.
- `pinMode()` configures the GPIO pin.
- `digitalWrite(HIGH)` and `digitalWrite(LOW)` control the output level.
- `delay()` controls how long the program waits.

## Important Concept

This practical demonstrates basic ON/OFF control. An **active buzzer** can produce sound from a steady DC control signal. A **passive buzzer** generally needs an oscillating signal at an appropriate frequency to generate a tone.

Tone generation will be explored in Practical 03.

## Challenges

1. Change the buzzer ON duration.
2. Change the OFF duration.
3. Create a short beep followed by a longer pause.
4. Explain how the buzzer practical builds on the LED practical.

## Troubleshooting

**No sound**
- Check the buzzer polarity and wiring.
- Confirm that the correct GPIO is used.
- Check whether the buzzer is active or passive.
- Verify its voltage and current requirements.

**Unexpected behavior**
- Check for loose connections.
- Verify the selected board and upload port.
- Confirm that the code matches the connected GPIO.

## Files

- `template.ino` — participant starter code
- `solution.ino` — complete reference implementation
