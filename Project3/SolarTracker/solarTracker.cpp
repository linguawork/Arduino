// C++ code
//

#include <Servo.h>

int currA0 = A0;
int lightVal;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
  
//настройка всех подключений
void setup()
{
  pinMode(currA0, INPUT);// getting connection from the circuit into the board
	Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop()
{
	lightVal = analogRead(currA0); // getting current value from pin
    Serial.println(lightVal);//распечатка аналоговых значений
  	delay(250);
  if (lightVal > 300){ 
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);
      Serial.println("the pos is :" + pos);// tell servo to go to position in variable 'pos'
      delay(250);                       // waits 15ms for the servo to reach the position
    }
  }
  else if(lightVal < 300) {
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);
      Serial.println(pos);// tell servo to go to position in variable 'pos'
      delay(250);                       // waits 15ms for the servo to reach the position
    }
  }
  
}