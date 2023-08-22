//arduino ino code: 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FastLED.h>
#include "webpage.h"
//#include <FS.h> // we switched off the spiff lib because it is hard to upload the files

#define NUM_LEDS 64
#define DATA_PIN 0
CRGB leds[NUM_LEDS];

char j[11][9][9]={{"01000001","11111111","10000000","01111110","10000001","10000001","10000001","01111110"},
{"00000000","01001110","10010001","10010001","10010001","01111110","00000000","00000000"},
{"00000000","01110110","10001001","10001001","10001001","01110110","00000000","00000000"},
{"00000000","00000001","11100001","00010001","00001001","00000111","00000000","00000000"},
{"00000000","01111110","10001001","10001001","10001001","01110010","00000000","00000000"},
{"00000000","01001111","10001001","10001001","10001001","01110001","00000000","00000000"},
{"00000000","00110000","00101000","00100100","00100010","11111111","00100000","00000000"},
{"00000000","01000010","10000001","10001001","10001001","01110110","00000000","00000000"},
{"00000000","10000010","11000001","10100001","10010001","10001110","00000000","00000000"},
{"00000000","00000000","10000001","11111111","10000000","00000000","00000000","00000000"},
{"00011110","00111111","01111111","11111110","11111110","01111111","00111111","00011110"}};

const int ledPin = DATA_PIN;  // ESP8266 pin for controlling LED

// Setting wifi
const char* ssid = "42Wolfsburg_FabLab";
const char* password = "0nly5ky15theL1m17";

ESP8266WebServer server(80); // HTTP server port

void handleRoot() {
  server.send(200, "text/html", WEBPAGE_HTML); // Send the embedded HTML string
}

void handleLedControl() {
  int ledNumber = server.arg("id").toInt();
  String status = server.arg("status");

  if (status == "pattern")
  {
    display_counter(0);
  }
  else if (status == "not pattern")
  {
    int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Black;
      }
  }
  else if (status == "true")
  {
    leds[ledNumber] = CRGB::White;
  }
  else if (status == "off")
  {
    int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Black;
      }
  }
  else if (status == "on")
  {
    int j = 0;
      while (j < 64){
        leds[j++] = CRGB::White;
      }
  }
  else
  {
    leds[ledNumber].setHSV(0,0,0);
  }

  Serial.print("LED NUMBER: ");
  Serial.println(ledNumber);
  
   server.send(200, "text/plain", "Data received");
  FastLED.show(); // Update the LED display
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
  server.on("/led", HTTP_GET, handleLedControl); // Handle the button data
  server.begin();
  FastLED.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(20);
}

void display_counter(int h)
{
  int ledpos = 0;
  for(; h < 11; h++)
  {
    ledpos = 0;
    for (int i = 0; i < 8;i++)
    {
      for (int k = 0; k < 8; k++)
      {
        if(j[h][i][k] == '1')
          leds[ledpos] = CRGB::White;
        else
          leds[ledpos] = CRGB::Black;
        ledpos++;
      }
    }
    delay(500);
    FastLED.show();
    delay(500);
  }
}
void loop() {
  //display_counter();
  server.handleClient();
}