
# Practical 04 — Web-Based IoT Control

**VERTEX IoT Workshop | Connecting Web Applications with Embedded Systems**

## Objective

Build a web-controlled IoT system using an ESP32. Participants will control three LEDs and a buzzer through a webpage opened in a phone or computer browser.

## Learning Outcomes

By completing this practical, participants will learn to:

- Connect multiple output devices to an ESP32.
- Connect an ESP32 to a Wi-Fi network.
- Host a basic webpage directly on the ESP32.
- Understand HTTP requests and query parameters.
- Connect HTML buttons to JavaScript functions.
- Send commands from a browser to an embedded device.
- Process requests and control GPIO outputs.

## Components Required

- ESP32 development board
- 3 LEDs (red, green and blue recommended)
- 3 × 220 Ω current-limiting resistors
- Suitable active buzzer or buzzer module
- Breadboard
- Jumper wires
- USB data cable
- Computer with Arduino IDE 2.0 or later
- Phone or computer with a web browser
- Local Wi-Fi network

## Hardware Connections

| Component | ESP32 connection |
|---|---|
| LED 1 anode through 220 Ω resistor | GPIO 23 |
| LED 2 anode through 220 Ω resistor | GPIO 22 |
| LED 3 anode through 220 Ω resistor | GPIO 21 |
| All LED cathodes | GND |
| Buzzer signal / positive terminal | GPIO 19 |
| Buzzer GND / negative terminal | GND |

Use one current-limiting resistor per LED. Check the buzzer's electrical requirements before connecting it directly to a GPIO.

## Software Requirements

- Arduino IDE 2.0 or later
- ESP32 board support for Arduino IDE
- A USB data cable
- Wi-Fi credentials provided by the workshop team

The sketch uses the `WiFi.h` and `WebServer.h` libraries provided by the Arduino-ESP32 core.

## Setup Instructions

### 1. Configure Wi-Fi

Open `solution.ino` and replace the placeholders:

```cpp
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
```

Use the correct local network credentials.

### 2. Select the ESP32 Board

1. Connect the ESP32 to the computer.
2. Select the correct board and serial port in Arduino IDE.
3. Select the appropriate upload settings for your board.

### 3. Upload the Program

1. Verify the sketch.
2. Upload it to the ESP32.
3. Open Serial Monitor.
4. Set the baud rate to 115200.
5. Wait for the Wi-Fi connection message.

### 4. Open the Web Interface

The Serial Monitor prints the ESP32's local IP address.

For example, if it prints `192.168.1.120`, open:

`http://192.168.1.120/`

Use the actual address printed by your board.

The phone or computer must be connected to the same reachable local network as the ESP32. Guest networks or client isolation may prevent communication.

### 5. Test the Controls

- Press LED 1 ON and OFF.
- Repeat for LED 2 and LED 3.
- Turn the buzzer ON and OFF.
- Confirm that the correct hardware responds to each command.

## How the System Works

### Browser Interface

The webpage contains four device controls. JavaScript sends an HTTP request when a button is pressed.

Example:

`/control?device=led1&state=on`

### ESP32 Web Server

The ESP32 listens for HTTP requests on port 80.

- `/` serves the webpage.
- `/control` receives device commands.

### Query Parameters

The ESP32 reads the `device` and `state` parameters, validates them, and updates the corresponding GPIO pin.

### GPIO Output

The selected GPIO is set HIGH for ON or LOW for OFF. The browser receives a response indicating the result.

## Expected Output

A webpage displays four sets of controls. Pressing a button changes the corresponding LED or buzzer state without requiring another sketch upload.

## Challenges

1. Change the webpage title and heading.
2. Improve the button colors and layout.
3. Add a status message for each device.
4. Add a button that switches all LEDs off.
5. Explain how a browser request becomes a physical output change.

## Troubleshooting

**ESP32 cannot connect to Wi-Fi**
- Check the network name and password.
- Confirm the network is available.
- Check the Serial Monitor for connection messages.

**Webpage does not open**
- Confirm the ESP32 has connected successfully.
- Use the exact IP address printed in Serial Monitor.
- Ensure the phone and ESP32 are on the same reachable network.
- Check whether the network uses client isolation.

**Webpage opens but outputs do not change**
- Check the wiring and GPIO numbers.
- Confirm that the request URL and parameter names match the code.
- Check Serial Monitor for command messages.

**Buzzer does not switch correctly**
- Confirm the buzzer type and polarity.
- Verify voltage and current requirements.
- Use an appropriate driver circuit if required.

**Sketch does not compile**
- Check that ESP32 board support is installed.
- Confirm that the selected board is an ESP32.
- Check the installed Arduino-ESP32 core version.

## Files

- `template.ino` — participant starter code
- `solution.ino` — complete reference implementation

## Safety and Network Notes

- Disconnect USB power before changing wiring.
- Never connect an LED without a current-limiting resistor.
- Do not expose this unauthenticated control page to an untrusted network.
- This practical is designed for a controlled local workshop network, not direct public internet access.
