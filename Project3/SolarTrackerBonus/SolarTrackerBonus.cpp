/*
C++ code

This code has mandatory tested part and bonus part that works in the simulator.

*/

#include <Servo.h>

int currA0 = A0;
int currA1 = A1;
int lightValLeft;
int lightValRight;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 90;    // variable to store the servo position


//bonus
int currA2 = A2;
int lightValUpper;
Servo bonusServo;
int bonusPos = 90;
  
//настройка всех подключений
void setup()
{
  pinMode(currA0, INPUT);// getting connection from the circuit into the board
  pinMode(currA1, INPUT);
  pinMode(currA2, INPUT);

  Serial.begin(9600);
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  //bonus
  bonusServo.attach(3);
}


void loop()
{
	lightValLeft = analogRead(currA0); // getting current value from pin
    Serial.println(lightValLeft);//распечатка аналоговых значений
  	lightValRight = analogRead(currA1); // getting current value from pin
    Serial.print("The left light value is: ");
  	Serial.println(lightValLeft);
  	Serial.print("The right light value is: ");
    Serial.println(lightValRight);
  	delay(1000); // 1 sec delay to read the messages in the terminal for the debug mode
      
    while (lightValLeft != lightValRight){
        if (lightValLeft > lightValRight){ 

            pos > 175 ? pos = 175 : pos -= 5;// iterator value controls the rotation speed and limits the degrees in the soft


            myservo.write(pos);
            Serial.print("Moving to the left pos: ");
            Serial.println(pos);// tell servo to go to position in variable 'pos'
            //delay(250);// waits 15ms for the servo to reach the position
            break;
        }else{

            pos < 0 ? pos = 5 : pos += 5; // iterator value controls the rotation speed and limits the degrees in the soft

            myservo.write(pos);
            Serial.print("Moving to the right pos: ");
            Serial.println(pos);// tell servo to go to position in variable 'pos'
            //delay(250);// waits 15ms for the servo to reach the position
            break;
        }
        
    }

      
     //bonus
  	lightValUpper = analogRead(currA2); // getting current value from pin
    Serial.println(lightValUpper);
    Serial.print("The left light value is: ");
  	Serial.println(lightValLeft);
  	Serial.print("The upper light value is: ");
    Serial.println(lightValUpper);
    delay(1000); // 1 sec delay to read the messages in the terminal for the debug mode
     
     
    while (lightValLeft != lightValUpper){
        if (lightValLeft > lightValUpper){ 

            bonusPos > 175 ? bonusPos = 175 : bonusPos -= 5;// iterator value controls the rotation speed and limits the degrees in the soft


            bonusServo.write(bonusPos);
            Serial.print("Moving down: ");
            Serial.println(bonusPos);// tell servo to go to position in variable 'pos'
            //delay(250);// waits 15ms for the servo to reach the position
            break;
        }else{

            bonusPos < 0 ? bonusPos = 5 : bonusPos += 5;

            bonusServo.write(bonusPos);
            Serial.print("Moving up: ");
            Serial.println(bonusPos);// tell servo to go to position in variable 'pos'
            //delay(250);// waits 15ms for the servo to reach the position
            break;
      }
  	}
}