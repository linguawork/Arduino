
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FastLED.h>
#include "webpage.h"// Include the header file containing the HTML string

#define NUM_LEDS 64
#define DATA_PIN 0 // The pin 0 is actually pin D3 on ESP board (please, see the picture in the folder)
CRGB leds[NUM_LEDS]; //array

const int ledPin = DATA_PIN;  // ESP8266 pin for controlling LED

// Setting wifi
const char* ssid = "42Wolfsburg_FabLab";
const char* password = "0nly5ky15theL1m17";

ESP8266WebServer server(80); // HTTP server port


void handleRoot() {
  server.send(200, "text/html", WEBPAGE_HTML); // Send the embedded HTML string
}

//modified in try button version
void handleLedControl() {
    int ledNumber = server.arg("led").toInt();

    Serial.print("LED NUMBER: ");
    Serial.println(ledNumber);

    // Toggle the LED state
    leds[ledNumber] = leds[ledNumber] == CRGB::Black ? CRGB::White : CRGB::Black;
    FastLED.show();

    server.send(200, "text/plain", leds[ledNumber] == CRGB::White ? "on" : "off");
}



void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);


  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP to connect: " + WiFi.localIP().toString());

  
  // Start the server and handle root requests
  server.on("/", handleRoot);
  server.on("/led", HTTP_GET, handleLedControl); // Handle the LED Control
  server.begin();
  FastLED.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(50);

}

void loop() {
  server.handleClient();
}  
