# VERTEX — Networked IoT Workshop

**From embedded hardware fundamentals to connected devices and interactive IoT applications.**

VERTEX is a hands-on workshop organised by the IEEE Robotics and Automation Society (RAS) Student Branch Chapter of IIT. The workshop introduces participants to embedded systems and the Internet of Things (IoT) through a series of practical activities using microcontroller development boards.

Participants begin with simple hardware control, progress to controlling physical components through a web interface, and finish with a team-based Network Hangman challenge built around wireless communication.

This repository contains the practical instructions, starter code, completed examples, and supporting documentation needed to run the workshop.

---

## About the Workshop

The goal of VERTEX is to help participants understand how software, electronics, web technologies, and wireless communication work together in a practical application.

Rather than starting with a complex project, the workshop builds knowledge step by step. Each activity introduces a concept that will be useful in the next stage.

By the end of the workshop, participants will have worked with microcontroller outputs, explored a web interface hosted by an embedded device, and experienced how connected devices can communicate as part of a shared game.

## Workshop Roadmap

| Activity | Topic | What You'll Do |
| --- | --- | --- |
| Practical 01 | LED Control | Configure an output pin and blink an LED. |
| Practical 02 | Buzzer Control | Turn a buzzer on and off using a microcontroller. |
| Practical 03 | Tone Generation | Explore generating a tone with a buzzer. |
| Practical 04 | Web-Based Hardware Control | Access a webpage from a phone and control an LED and buzzer through the ESP32. |
| Final Challenge | Network Hangman | Connect to a central game service, submit guesses, and compete with other teams. |

The tone-generation activity may be treated as an extension depending on the available time.

## Hardware and Technology

### Participant devices

The initial practical examples are being developed for the **ESP32 DevKit V1**. Magicbit boards are also intended for the workshop, with platform-specific support to be added after the hardware configuration has been confirmed.

The participant activities use:

- ESP32 development board
- LEDs and suitable current-limiting resistors
- Compatible buzzer
- USB cable and computer
- Smartphone for the web-control activity
- Access to the workshop's local Wi-Fi network

The exact components and pin assignments depend on the board and hardware used.

### Central game device

The final Network Hangman challenge is planned around a **Raspberry Pi Pico 2 W**. It will run the central game service, process team guesses, and maintain the game state.

Participant boards and the central game device have separate roles. The ESP32 participant firmware and the Pico 2 W game service will be maintained separately in this repository.

## How the Learning Activities Work

### 1. Start with the hardware

The first activities introduce digital outputs and basic buzzer control. Participants learn how a program can change the state of a physical component.

### 2. Move to a web interface

In the web-control activity, participants use a prepared ESP32 web-server template. They configure the required settings, connect the board to the local network, find its IP address, and open the webpage from a smartphone.

The webpage provides controls for the LED and buzzer. Participants can observe how a browser request results in a physical change on the device.

The focus is on understanding the relationship between the web interface, the local network, and the microcontroller—not on building a complete web server from scratch.

### 3. Finish with Network Hangman

For the final challenge, the organising team prepares the central game service and participant code before the workshop.

Participants use the provided firmware, configure their team details, connect their devices, and submit letter guesses through the game interface. The central service processes the guesses and updates the game state.

A buzzer response, such as a victory tone, is planned as an extension that connects the game outcome to physical hardware.

Participants are not expected to develop the entire multiplayer game themselves.

---

## Repository Structure

```text
VERTEX-IoT-Workshop/
│
├── README.md
├── LICENSE
├── .gitignore
│
├── docs/
│   ├── SPEAKER_GUIDE.md
│   ├── HARDWARE_SETUP.md
│   ├── TROUBLESHOOTING.md
│   └── WORKSHOP_FLOW.md
│
├── assets/
│   ├── images/
│   └── diagrams/
│
├── practical-01-led/
│   ├── README.md
│   ├── template.ino
│   └── solution.ino
│
├── practical-02-buzzer/
│   ├── README.md
│   ├── template.ino
│   └── solution.ino
│
├── practical-03-tone/
│   ├── README.md
│   ├── template.ino
│   └── solution.ino
│
├── practical-04-web-control/
│   ├── README.md
│   ├── template.ino
│   └── solution.ino
│
└── network-hangman/
    ├── README.md
    ├── participant-esp32/
    │   ├── README.md
    │   ├── template.ino
    │   └── solution.ino
    └── central-pico2w/
        └── README.md
```

The central game implementation will be added under `network-hangman/central-pico2w/` as development progresses.

## Starter Code and Reference Solutions

Each practical is designed around two code versions.

**`template.ino` — Try it yourself**

The starter version contains the basic structure, instructions, and clearly marked sections to complete. Participants should begin here and attempt the activity before looking at the finished implementation.

**`solution.ino` — Completed example**

The reference version contains the complete implementation for the activity. It is available when participants need help, want to compare their work, or need to recover from an incomplete attempt.

The speaker can use the reference solutions for demonstrations and troubleshooting.

For activities involving more complex functionality, such as web hosting, the template will retain the necessary setup code. Participants will only need to modify the selected sections and configuration values.

## Getting Started

### Requirements

Before beginning, prepare the following:

- A computer with the Arduino IDE installed.
- The appropriate ESP32 board support package.
- A compatible ESP32 development board and USB cable.
- The components listed in the relevant practical's README.
- A smartphone and access to the workshop's local Wi-Fi network for Practical 04.

For the final game, the organising team will also need the Raspberry Pi Pico 2 W and its separately prepared game firmware.

### Steps

1. Clone or download this repository.
2. Open the folder in your preferred code editor.
3. Read the README inside the practical you intend to complete.
4. Connect the required hardware and confirm the selected board and port.
5. Open `template.ino` and follow the instructions.
6. Compile and upload your code.
7. If you cannot complete the activity, consult `solution.ino` and compare it with your attempt.

Follow the practicals in order, since later activities build on concepts introduced earlier.

## Important Notes

- Confirm the correct board model and pin assignments before uploading code.
- Do not assume that Magicbit and ESP32 boards use identical pin mappings or libraries.
- Use a compatible buzzer and follow the wiring instructions for the selected hardware.
- For the web-control practical and final game, the relevant devices must be able to communicate over the configured local network.
- Internet access is not inherently required for local communication, but network configuration can affect whether devices can reach one another.
- Never commit personal Wi-Fi passwords, private credentials, or other secrets to the repository.
- The Network Hangman implementation and multi-device behaviour must be tested before the workshop.

## For Speakers and Organisers

The `docs/` directory is intended to hold the teaching guide, hardware setup instructions, workshop sequence, and troubleshooting information.

Before the event, organisers should:

- Verify all practicals on the actual boards.
- Test the web interface from a smartphone.
- Confirm the local network configuration.
- Test the central game service with the expected number of participant devices.
- Prepare working examples and a fallback demonstration.
- Ensure that the instructions match the hardware distributed to participants.

The repository will be updated as the workshop materials are developed and tested.

## Organised By

**IEEE Robotics and Automation Society (RAS) Student Branch Chapter of IIT**

**Webmaster:** Pasindu Heshan Kavinda  
**Term:** 2026/2027

*VERTEX — Build. Connect. Play.*
