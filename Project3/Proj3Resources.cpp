/**

https://www.youtube.com/watch?v=QbgTl6VSA9Y&list=PLYlfM6qKBI5i4F9IQcpdoO1mvjw7GqS-A&index=9
How to Control a Servo With an Arduino

https://www.tinkercad.com/things/g1182wjWonM-glorious-lahdi-fulffy/editel?sharecode=UVMSzY9JRu9H5BbeCHxEMUg_qqvwE1EiqNDIq9Kh7OU

*/

/*
Servo.h
https://www.arduino.cc/reference/en/libraries/servo/

Allows Arduino boards to control a variety of servo motors.
This library can control a great number of servos. 
It makes careful use of timers: the library can control 12 servos using only 1 timer.
On the Arduino Due you can control up to 60 servos.


Circuit
Servo motors have three wires: power, ground, and signal.
The power wire is typically red, and should be connected to the 5V pin on the Arduino board.
 The ground wire is typically black or 
 brown and should be connected to a ground pin on the Arduino board. 
 The signal pin is typically yellow, 
 orange or white and should be connected to a digital pin on the Arduino board. 
 Note that servos draw considerable power, 
 so if you need to drive more than one or two, you’ll probably need to power them from a separate supply 
 (i.e. not the 5V pin on your Arduino).
  Be sure to connect the grounds of the Arduino and external power supply together.


Methods
attach()
write()
writeMicroseconds()
read()
attached()
detach()


Example projects:
https://docs.arduino.cc/learn/electronics/servo-motors


Knob Circuit
For the Knob example, 
wire the potentiometer so that its two outer pins are connected to power (+5V) and ground,
 and its middle pin is connected to A0 on the board. 
 Then, connect the servo motor to +5V, GND and pin 9.


*/


/*
  I registered for Arduino by bama gmail
  User name is Bama20180717


  https://www.arduino.cc/reference/en/libraries/simple-solartracker-arduino/
  Not a Simple Solar Tracker Project
  there is some spagetti code to understand
  (the explanation is on the author's git)

*/

/*
  https://www.arduino.cc/reference/en/libraries/rbd_lightsensor/
  Simple project to set a photoresistor

  More resources:
  https://circuitdigest.com/microcontroller-projects/arduino-light-sensor-using-ldr
*/

/*
  Explanation of Photoresistors:
  https://www.youtube.com/watch?v=WMkN-uHd-Xo 
  Arduino Tutorial 25: Understanding Photoresistors and Photo Detectors
  (Paul McWhorter youtube channel)
*/