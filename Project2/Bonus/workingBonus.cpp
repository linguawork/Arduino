/*
We changed the code of the resources:
to the working one.

*/

const int ledPin = 9; // PWM pin connected to the LED
int brightness = 100;

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(ledPin, OUTPUT);
}


//this function is used to get read of all new lines that may happen 
//while reading serial
void serialFlush()
{
  while(Serial.available() > 0)
  {
    char t = Serial.read();
  }
}

void loop() {
  if (Serial.available() > 0) {
    brightness = Serial.parseInt(); // Read the integer value from Serial Monitor
    serialFlush();
    brightness = constrain(brightness, 0, 255); // Limit the value to 0-255
    Serial.print("LED brightness set to: ");
    Serial.println(brightness);
  }
  analogWrite(ledPin, brightness); // Set the LED brightness
}
