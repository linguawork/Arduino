/*
Chat:
o control the brightness of an LED via the Arduino terminal without using a potentiometer,
 you can utilize the Serial Monitor in the Arduino IDE to send commands from your computer to the Arduino board.
  The Arduino will receive these commands and adjust the brightness of the LED accordingly.

Here's a step-by-step guide to achieve this:

Connect your LED to a PWM (Pulse Width Modulation) capable pin on your Arduino board.
 PWM allows you to control the brightness of an LED by varying the duty cycle of the signal.

Write an Arduino sketch that listens for commands from the Serial Monitor and adjusts the LED brightness based on the received values.
 For this example, we'll use pin 9 as the PWM pin for the LED.
*/

const int ledPin = 9; // PWM pin connected to the LED

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int brightness = Serial.parseInt(); // Read the integer value from Serial Monitor
    brightness = constrain(brightness, 0, 255); // Limit the value to 0-255
    analogWrite(ledPin, brightness); // Set the LED brightness
    Serial.print("LED brightness set to: ");
    Serial.println(brightness);
  }
}

/*

Upload the sketch to your Arduino board.

Open the Serial Monitor in the Arduino IDE (click on the magnifying glass icon or press Ctrl+Shift+M).

In the Serial Monitor, enter the desired brightness value (0 to 255) and press Enter. 
The Arduino will receive the value and adjust the LED brightness accordingly.

Now, you can manually control the brightness of the LED by typing the brightness value in the Serial Monitor and pressing Enter. 
For example, sending "128" will set the LED brightness to 50%, "255" will set it to 100%, and "0" will turn off the LED.

Remember that the analogWrite() function, used to control the PWM pins,
 can set the brightness using values from 0 (LED off) to 255 (maximum brightness). 
The Serial Monitor allows you to send these values to the Arduino, 
enabling you to adjust the LED's brightness at your command.

*/

/*
https://www.youtube.com/watch?v=7aP5KL5clWA
Arduino Tutorial 18: Reading Numbers from the Serial Monitor
*/





