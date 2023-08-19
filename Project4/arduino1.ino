#include <ESP8266WiFi.h> // wifi lib
#include <ESP8266WebServer.h> // server lib


const int ledPin = D2;  // ESP2866 pin for controlling LED

//setting wifi
const char* ssid = "WifiLogin";
const char* password = "WiFiPassword";

ESP8266WebServer server(80); // http server port

//The server responds to clients (in this case - web browsers) on port 80, which is a standard port web browsers talk to web servers.

void handleRoot() {
  server.send(200, "text/plain", "Welcome to the LED Control Server");

  /*
  In the context of programming for the ESP8266 using the Arduino core and the ESP8266WebServer library, server.send() is a function that allows you to send an HTTP response from the web server to the client that made the request.

Here's what server.send() does:

HTTP Response: The server.send() function constructs and sends an HTTP response to the client that made the request. This response includes an HTTP status code, headers, and the response content.

Parameters: The function takes several parameters to customize the response:

HTTP Status Code: This is a numerical code that indicates the status of the response (e.g., 200 for "OK", 404 for "Not Found", etc.).
Content Type: This specifies the type of content you're sending (e.g., "text/plain", "text/html", "application/json", etc.).
Response Content: This is the actual content you want to send in the response, such as text, HTML, JSON, etc.
  
  */
}

void handleControl() {
  String ledAction = server.arg("led");


  /*
  In the context of programming for the ESP8266 using the Arduino core and the ESP8266WebServer library, server.arg() is a function that allows you to retrieve the value of a URL query parameter from an incoming HTTP request.

Here's what server.arg() does:

Query Parameters: Query parameters are the key-value pairs that can be included in the URL of an HTTP request. They are often used to pass data from the client (e.g., a web browser) to the server. For example, in the URL http://example.com/?name=John&age=30, name and age are query parameters.

Retrieving Values: The server.arg() function is used to retrieve the value of a specific query parameter from the URL of the incoming HTTP request. You provide the name of the query parameter as an argument to the function, and it returns the corresponding value.
  
  
  
  */

  if (ledAction == "on") {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    server.send(200, "text/plain", "LED turned on");
  } else if (ledAction == "off") {
    digitalWrite(ledPin, LOW);   // Turn off the LED
    server.send(200, "text/plain", "LED turned off");
  } else {
    server.send(400, "text/plain", "Invalid action");
  }
}

void setup() {

  pinMode(ledPin, OUTPUT);// Set the only LED matrix pin as an output

  digitalWrite(ledPin, LOW);

  Serial.begin(115200);
  /*
    begin() Sets the data rate in bits per second (baud) for serial data transmission. 
    For USB baudrate is fixed on 115200 bps, on UART it is possible to select baudrate. 
    Sets the data rate in bits per second (baud) for serial data transmission.
  */
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

//server.on(uri, HTTP_METHOD, handlerFunction);
  server.on("/", handleRoot); //uniform resource identifier
  /*
  For example, if you want to handle requests to the root of your server (e.g., http://your-esp-ip/), you would use "/".
  If you want to handle requests to a specific path (e.g., http://your-esp-ip/control), you would use "/control"

  When using the server.on() function with only the URI and handler function,
   it's assumed to handle HTTP_GET requests by default. 
   In this case, the handler function (handleRoot in your example) will be executed when a GET request is made to the specified URI.
  */
  server.on("/control", handleControl);

  server.begin();
  /*
  In the context of programming for the ESP8266 using the Arduino core and the ESP8266WebServer library, server.begin() is a function that initializes and starts the web server.

Here's what server.begin() does:

Initialization: The server.begin() function initializes the web server instance you've created using the ESP8266WebServer class. This prepares the server to start listening for incoming HTTP requests.

Starting the Server: After initializing the server, the begin() function starts the server and makes it ready to handle incoming HTTP requests.
  
  */
}

void loop() {
  server.handleClient();

  /*
    The actual implementation of server.handleClient() is part of the ESP8266WebServer library itself.
    You don't need to provide its definition; you simply call it as a method of your server instance

    Server Loop (loop()): The loop() function is the main loop of your Arduino sketch. 
    In this loop, you need to call server.handleClient() to check for incoming client requests and manage them.

    Handling Client Requests: The server.handleClient() function is responsible for accepting incoming HTTP requests,
     parsing them, and directing them to the appropriate route handler function. 
     It checks if any new requests have arrived and, if so, 
     it calls the corresponding route handler function that you've defined using server.on().

  */
}
