/*
C++ code

This code has mandatory tested part and bonus part that works in the simulator.

The suggested improved code to try

*/

#include <Servo.h>

const int currA0 = A0;
const int currA1 = A1;
const int currA2 = A2;

int lightValLeft;
int lightValRight;
int lightValUpper;

Servo myservo;
int pos = 90;

Servo bonusServo;
int bonusPos = 90;

const int servoSpeed = 5; // Adjust the servo speed
const int servoLimit = 175; // Servo angle limit

void setup() {
  pinMode(currA0, INPUT);
  pinMode(currA1, INPUT);
  pinMode(currA2, INPUT);
  
  Serial.begin(9600);
  myservo.attach(9);
  bonusServo.attach(3);
}

void loop() {
  lightValLeft = analogRead(currA0);
  lightValRight = analogRead(currA1);
  lightValUpper = analogRead(currA2);

  // Print light values
  Serial.print("Left: ");
  Serial.print(lightValLeft);
  Serial.print(" | Right: ");
  Serial.print(lightValRight);
  Serial.print(" | Upper: ");
  Serial.println(lightValUpper);

  // Control main servo
  if (lightValLeft > lightValRight) {
    pos = max(pos - servoSpeed, -servoLimit);
    Serial.print("Moving to the left pos: ");
    Serial.println(pos);
  } else {
    pos = min(pos + servoSpeed, servoLimit);
    Serial.print("Moving to the right pos: ");
    Serial.println(pos);
  }
  myservo.write(pos);

  // Control bonus servo
  if (lightValLeft > lightValUpper) {
    bonusPos = max(bonusPos - servoSpeed, -servoLimit);
    Serial.print("Moving down: ");
    Serial.println(bonusPos);
  } else {
    bonusPos = min(bonusPos + servoSpeed, servoLimit);
    Serial.print("Moving up: ");
    Serial.println(bonusPos);
  }
  bonusServo.write(bonusPos);

  delay(1000); // 1 sec delay for debugging
}