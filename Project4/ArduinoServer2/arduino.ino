#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include <FS.h> // for serving html page
/**
the SPIFFS (SPI Flash File System) library
With this setup, when you access the ESP8266's IP address in a web browser, the index.html file will be served as the main web page. You can place your buttons and JavaScript functions inside this HTML file to control the LEDs on the LED matrix as described in the previous responses.

Please note that the SPIFFS file system has limited space, so if your HTML file is large or you plan to add more files in the future, you might need to consider alternative storage solutions.

*/
// Include the header file containing the HTML string
#include "webpage.h"

const int ledPin = D2;  // ESP8266 pin for controlling LED

// Setting wifi
const char* ssid = "WifiLogin";
const char* password = "WiFiPassword";

ESP8266WebServer server(80); // HTTP server port



void handleRoot() {
  server.send(200, "text/html", WEBPAGE_HTML); // Send the embedded HTML string
}




void handleRoot() {
  server.send(200, "text/html", WEBPAGE_HTML); // Send the embedded HTML string
}

void setup() {
  // ... Your setup code ...
  
  // Start the server and handle root requests
  server.on("/", HTTP_GET, handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}




....=======================
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//#include <FS.h> // for serving html page
/**
the SPIFFS (SPI Flash File System) library
With this setup, when you access the ESP8266's IP address in a web browser, the index.html file will be served as the main web page. You can place your buttons and JavaScript functions inside this HTML file to control the LEDs on the LED matrix as described in the previous responses.

Please note that the SPIFFS file system has limited space, so if your HTML file is large or you plan to add more files in the future, you might need to consider alternative storage solutions.

*/
// Include the header file containing the HTML string
#include "webpage.h"

#define DATA_PIN 0

const int ledPin = DATA_PIN;  // ESP8266 pin for controlling LED

// Setting wifi

const char* ssid = "42Wolfsburg_FabLab";
const char* password = "0nly5ky15theL1m17";

ESP8266WebServer server(80); // HTTP server port



void handleRoot() {
  server.send(200, "text/html", WEBPAGE_HTML); // Send the embedded HTML string
}
