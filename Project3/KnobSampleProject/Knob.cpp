/*
Knob is a small project to control Micro Servo with Potentiometer
    Example projects:
    https://docs.arduino.cc/learn/electronics/servo-motors
    The code is provided


Knob Circuit
    For the Knob example, 
    wire the potentiometer so that its two outer pins 
    are connected to power (+5V) and ground,
    and its middle pin is connected to A0 on the board. 
    Then, connect the servo motor to +5V, GND and pin 9.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  //can't go for 360 degree range
  //but for within 180 degrees
  val = map(val, 0, 1023, 0, 90);     // scale it to use it with the servo (value between 0 and 180)
  
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}