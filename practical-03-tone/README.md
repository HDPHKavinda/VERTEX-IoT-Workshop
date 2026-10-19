
# Practical 03 — Tone Generation

**VERTEX IoT Workshop | Embedded Sound and Frequency**

## Objective

Generate sound at different frequencies using an ESP32 and a passive piezo buzzer.

## Learning Outcomes

By completing this practical, participants will learn to:

- Understand frequency and pitch.
- Generate a tone using `tone()`.
- Stop a tone using `noTone()`.
- Control tone duration using `delay()`.
- Change the frequency to produce different pitches.
- Understand the difference between basic buzzer control and tone generation.

## Components Required

- ESP32 development board
- Passive piezo buzzer
- Breadboard
- Jumper wires
- USB data cable
- Computer with Arduino IDE 2.0 or later

## Hardware Connection

| Component | Connection |
|---|---|
| Passive buzzer positive / signal terminal | ESP32 GPIO 23 |
| Passive buzzer negative terminal | ESP32 GND |

Check the buzzer specifications before connecting it directly to a GPIO. Use an appropriate driver circuit if required by its electrical characteristics.

## Software Setup

1. Open Arduino IDE.
2. Select the appropriate ESP32 board and serial port.
3. Open `template.ino`.
4. Complete the missing code sections.
5. Verify and upload the sketch.
6. Listen to the sequence of tones.
7. Change the frequencies and compare the results.

## Understanding Frequency

Frequency describes how many cycles occur per second and is measured in Hertz (Hz).

- Lower frequency generally produces a lower-pitched sound.
- Higher frequency generally produces a higher-pitched sound.

The exact sound depends on the buzzer's characteristics and operating range.

## Understanding the Functions

### `tone()`

Generates a periodic signal at the specified frequency.

Example:

```cpp
tone(BUZZER_PIN, 1000);
```

This requests a 1000 Hz tone.

### `noTone()`

Stops tone generation on the specified pin.

Example:

```cpp
noTone(BUZZER_PIN);
```

### `delay()`

Pauses program execution for a specified duration in milliseconds.

Example:

```cpp
delay(500);
```

This waits for approximately half a second.

## Expected Output

The buzzer plays a lower-pitched tone, pauses, plays a higher-pitched tone, and pauses again. The sequence repeats continuously.

## Challenges

1. Try frequencies of 250 Hz, 500 Hz, and 1500 Hz.
2. Create a sequence of three different pitches.
3. Change the duration of each tone.
4. Create a short melody using a sequence of frequencies.
5. Explain how frequency differs from duration.

## Troubleshooting

**No sound**
- Confirm that the buzzer is passive.
- Check the polarity and wiring.
- Verify the GPIO number.
- Check the buzzer's frequency and electrical requirements.

**The pitch does not change as expected**
- Confirm that the code changes the frequency argument.
- Check the buzzer's operating range.
- Try frequencies within the buzzer's supported range.

**Compilation or upload problems**
- Confirm that the correct ESP32 board and serial port are selected.
- Check the Arduino-ESP32 core version and its tone API support.
- Use a USB data cable.

## Files

- `template.ino` — participant starter code
- `solution.ino` — complete reference implementation

## Safety

Disconnect USB power before changing wiring. Do not connect a buzzer that exceeds the ESP32 GPIO's safe current limits directly to the pin.
