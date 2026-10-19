
/*
   VERTEX IoT Workshop
   Practical 04: Web-Based IoT Control

   Goal: Control three LEDs and a buzzer using a webpage
   hosted by the ESP32 and accessed through a web browser.
*/

#include <WiFi.h>
#include <WebServer.h>

// Enter the Wi-Fi credentials provided for the workshop.
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// GPIO pins connected to the output devices.
const int LED1_PIN = 23;
const int LED2_PIN = 22;
const int LED3_PIN = 21;
const int BUZZER_PIN = 19;

// Create a web server that listens on HTTP port 80.
WebServer server(80);

// This webpage provides ON/OFF controls for the four devices.
const char webpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>VERTEX IoT Control</title>
</head>
<body>
  <h1>VERTEX IoT Control</h1>

  <button onclick="control('led1','on')">LED 1 ON</button>
  <button onclick="control('led1','off')">LED 1 OFF</button><br>

  <button onclick="control('led2','on')">LED 2 ON</button>
  <button onclick="control('led2','off')">LED 2 OFF</button><br>

  <button onclick="control('led3','on')">LED 3 ON</button>
  <button onclick="control('led3','off')">LED 3 OFF</button><br>

  <button onclick="control('buzzer','on')">BUZZER ON</button>
  <button onclick="control('buzzer','off')">BUZZER OFF</button>

  <p id="status">Ready</p>

  <script>
    /*
       JavaScript sends a request to the ESP32 when a button
       is pressed.

       Example request:
       /control?device=led1&state=on

       The ESP32 processes the request and controls the device.
    */

    async function control(device, state) {
      // Send the device name and requested state to the ESP32.
      const response = await fetch(
        `/control?device=${device}&state=${state}`
      );

      // Display the response returned by the ESP32.
      document.getElementById('status').textContent =
        await response.text();
    }
  </script>
</body>
</html>
)rawliteral";

void handleRoot() {
  /*
     This function handles requests to the main webpage.

     When someone opens the ESP32's IP address in a browser,
     the ESP32 should send the HTML webpage to that browser.

     Example:
     server.send(200, "text/html", webpage);
  */

}

void handleControl() {
  /*
     This function processes commands sent by the webpage.

     The request contains two parameters:
       1. device — led1, led2, led3 or buzzer
       2. state  — on or off

     Use server.hasArg() to check whether a parameter exists.
     Use server.arg() to read its value.

     Example request:
     /control?device=led1&state=on

     Identify the requested device, select its GPIO pin,
     and use digitalWrite() to switch it ON or OFF.

     Return an HTTP response to the browser.

     Example:
     server.send(200, "text/plain", "LED 1 turned on");
  */

}

void setup() {
  Serial.begin(115200);

  /*
     Configure the three LED pins and the buzzer pin as OUTPUT.
     This allows the ESP32 to control the connected devices.

     Example:
     pinMode(LED1_PIN, OUTPUT);
  */


  /*
     Connect the ESP32 to the selected Wi-Fi network.

     WiFi.begin() takes the network name and password.
     The ESP32 needs a successful connection before the
     browser can reach its local IP address.
  */


  /*
     Print the assigned local IP address to Serial Monitor.

     Participants will enter this address in their phone's
     browser to open the control webpage.

     Example:
     Serial.println(WiFi.localIP());
  */


  /*
     Register the web server routes.

     The "/" route serves the webpage.
     The "/control" route receives device-control commands.

     Example:
     server.on("/", HTTP_GET, handleRoot);
     server.on("/control", HTTP_GET, handleControl);
  */


  /*
     Start the web server so it can accept HTTP requests.

     Example:
     server.begin();
  */

}

void loop() {
  /*
     Continuously process incoming browser requests.

     Example:
     server.handleClient();
  */

}
