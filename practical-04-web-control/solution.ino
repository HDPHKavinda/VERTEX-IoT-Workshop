
/*
 * VERTEX IoT Workshop
 * Practical 04: Web-Based IoT Control
 * Reference Solution
 */

#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const int LED1_PIN = 23;
const int LED2_PIN = 22;
const int LED3_PIN = 21;
const int BUZZER_PIN = 19;

WebServer server(80);

const char webpage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>VERTEX IoT Control</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
      margin: 24px;
      background: #f3f6fb;
    }
    h1 { color: #123d78; }
    .panel {
      max-width: 420px;
      margin: auto;
      padding: 18px;
      background: white;
      border-radius: 14px;
    }
    button {
      padding: 13px 15px;
      margin: 6px 3px;
      border: 0;
      border-radius: 8px;
      background: #174ea6;
      color: white;
      font-size: 15px;
      cursor: pointer;
    }
    #status { overflow-wrap: anywhere; }
  </style>
</head>
<body>
  <div class="panel">
    <h1>VERTEX IoT Control</h1>
    <p>Control devices connected to your ESP32.</p>

    <h3>LED 1</h3>
    <button onclick="control('led1','on')">ON</button>
    <button onclick="control('led1','off')">OFF</button>

    <h3>LED 2</h3>
    <button onclick="control('led2','on')">ON</button>
    <button onclick="control('led2','off')">OFF</button>

    <h3>LED 3</h3>
    <button onclick="control('led3','on')">ON</button>
    <button onclick="control('led3','off')">OFF</button>

    <h3>Buzzer</h3>
    <button onclick="control('buzzer','on')">ON</button>
    <button onclick="control('buzzer','off')">OFF</button>

    <p id="status">Ready</p>
  </div>

  <script>
    async function control(device, state) {
      const status = document.getElementById('status');
      status.textContent = 'Sending command...';

      try {
        const response = await fetch(
          `/control?device=${device}&state=${state}`
        );
        const message = await response.text();
        status.textContent = message;
      } catch (error) {
        status.textContent =
          'Request failed. Check your Wi-Fi connection.';
      }
    }
  </script>
</body>
</html>
)rawliteral";

void handleRoot() {
  // Send the HTML page stored in program memory.
  server.send(200, "text/html", webpage);
}

void handleControl() {
  // Check that both required parameters were provided.
  if (!server.hasArg("device") || !server.hasArg("state")) {
    server.send(400, "text/plain", "Missing device or state");
    return;
  }

  String device = server.arg("device");
  String state = server.arg("state");

  // Convert the requested state into a digital output level.
  int outputState;

  if (state == "on") {
    outputState = HIGH;
  } else if (state == "off") {
    outputState = LOW;
  } else {
    server.send(400, "text/plain", "Invalid state");
    return;
  }

  // Find the requested device and update its output.
  int pin = -1;

  if (device == "led1") {
    pin = LED1_PIN;
  } else if (device == "led2") {
    pin = LED2_PIN;
  } else if (device == "led3") {
    pin = LED3_PIN;
  } else if (device == "buzzer") {
    pin = BUZZER_PIN;
  } else {
    server.send(404, "text/plain", "Unknown device");
    return;
  }

  digitalWrite(pin, outputState);

  String message = device + " turned " + state;
  Serial.println(message);
  server.send(200, "text/plain", message);
}

void setup() {
  Serial.begin(115200);

  // Configure the three LED pins and buzzer pin.
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Begin with every output switched off.
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Connect the ESP32 to the local Wi-Fi network.
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");

  unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - startTime < 20000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("\nWi-Fi connection failed. Restarting...");
    delay(1000);
    ESP.restart();
  }

  Serial.println("\nWi-Fi connected.");
  Serial.print("Open this address in your browser: http://");
  Serial.println(WiFi.localIP());

  // Register the webpage and command handler.
  server.on("/", HTTP_GET, handleRoot);
  server.on("/control", HTTP_GET, handleControl);

  // Start listening for browser requests.
  server.begin();
  Serial.println("Web server started.");
}

void loop() {
  // Handle incoming HTTP requests.
  server.handleClient();
}
