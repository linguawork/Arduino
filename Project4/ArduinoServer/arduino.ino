#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <FS.h> // for serving html page
/**
the SPIFFS (SPI Flash File System) library
With this setup, when you access the ESP8266's IP address in a web browser, the index.html file will be served as the main web page. You can place your buttons and JavaScript functions inside this HTML file to control the LEDs on the LED matrix as described in the previous responses.

Please note that the SPIFFS file system has limited space, so if your HTML file is large or you plan to add more files in the future, you might need to consider alternative storage solutions.

*/


const int ledPin = D2;  // ESP8266 pin for controlling LED

// Setting wifi
const char* ssid = "WifiLogin";
const char* password = "WiFiPassword";

ESP8266WebServer server(80); // HTTP server port



void handleRoot() {
  String html = "<html><body>";
  for (int i = 0; i < 64; i++) {
    html += "<button onclick=\"sendRequest(" + String(i) + ")\">LED " + String(i) + "</button><br>";
  }
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLedControl() {
  int ledNumber = server.arg("led").toInt();

  if (ledNumber >= 0 && ledNumber < 64) {
    if (digitalRead(ledPin) == LOW) {
      digitalWrite(ledPin, HIGH);  // Turn on the corresponding LED
      server.send(200, "text/plain", "LED " + String(ledNumber) + " turned on");
    } else {
      digitalWrite(ledPin, LOW);   // Turn off the corresponding LED
      server.send(200, "text/plain", "LED " + String(ledNumber) + " turned off");
    }
  } else {
    server.send(400, "text/plain", "Invalid LED number");
  }
}

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED matrix pin as an output
  digitalWrite(ledPin, LOW);

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

   // Print wifi IP addess
  Serial.println("IP to connect: " + WiFi.localIP().toString());




    SPIFFS.begin();
      if (!SPIFFS.begin()) {
      Serial.println("Failed to mount file system");
      return;
    }

    //checking uploaded files
    Serial.println("SPIFFS files:");
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      Serial.println(dir.fileName());
    }  


      // Serve static files
      server.serveStatic("/", SPIFFS, "/index.html");



      server.on("/", handleRoot);
      server.on("/led", handleLedControl);

      server.begin();




}

void loop() {
  server.handleClient();
}
