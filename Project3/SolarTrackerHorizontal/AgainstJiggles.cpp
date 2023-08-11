/*
https://www.youtube.com/watch?v=BgIA_BjH-Yk&list=PLYlfM6qKBI5i4F9IQcpdoO1mvjw7GqS-A&index=6

Adding 15 to the side makes it smoother


*/

#define photor_resistor1 A0
#define photor_resistor2 A2
#include <Servo.h>
   Servo myservo;
int  angle;
int photo_R1;
int photo_R2;

void setup() {
  myservo.attach(9);
}

void loop() {
photo_R1 = analogRead(A0);
photo_R2 = analogRead(A1);
if(photo_R1 > 15 + photo_R2 && angle < 180){
  angle++;
  myservo.write(angle);
  delay(15);
}
if(photo_R2 > 15 + photo_R1 && angle >   0){
  angle--;
  myservo.write(angle);
  delay(15);
}
}