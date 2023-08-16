#include <Servo.h> 

Servo horizontal; // horizontal servo
int servoh = 180; 
int servohLimitHigh = 175;
int servohLimitLow = 5;
// 170 degrees MAX

Servo vertical; // vertical servo
int servov = 90; 
int servovLimitHigh = 120;
int servovLimitLow = 60;
// 60 degrees MAX

// LDR pin connections

int ldrup = A0; //LDR UP
int ldrrt = A1; //LDR RIGHT
int ldrlt = A2; //LDR LEFT

void setup(){
horizontal.attach(9);
vertical.attach(10);
horizontal.write(servoh);
vertical.write(servov);
}
void loop() {
int up = analogRead(ldrup); // Up
int rt = analogRead(ldrrt); // Right
int lt = analogRead(ldrlt); // Left
int rd = (lt + rt) / 2; // Down
int tol = 90; // tol=toleransi
int avu = up; // average value top
int avd = (up + rd) / 2; // average value down
int avl = (lt + up) / 2; // average value left
int avr = (rt + rd) / 2; // average value right
int dvert = avu - avd; // check the diffirence of up and down
int dhoriz = avl - avr;// check the diffirence og left and rigt

if (-1*tol > dvert || dvert > tol) 
 {
 if (avu > avd)
 {
 servov = ++servov;
 if (servov > servovLimitHigh)
 {servov = servovLimitHigh;}
 }
 else if (avu < avd)
 {servov= --servov;
 if (servov < servovLimitLow)
 { servov = servovLimitLow;}
 }
 vertical.write(servov);
 }
if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
 {
 if (avl > avr)
 {
 servoh = --servoh;
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (avl < avr)
 {
 servoh = ++servoh;
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 horizontal.write(servoh);
 }
 delay(10);
}
