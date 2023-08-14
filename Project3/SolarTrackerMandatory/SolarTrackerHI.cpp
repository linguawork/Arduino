// C++ code
//

#include <Servo.h>

int currA0 = A0;
int currA1 = A1;
int lightValLeft;
int lightValRight;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 90;    // variable to store the servo position
  
//настройка всех подключений
void setup()
{
  pinMode(currA0, INPUT);// getting connection from the circuit into the board
	Serial.begin(9600);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
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
  	delay(500);
  
  while (lightValLeft != lightValRight){
    if (lightValLeft > lightValRight){ 
      
      	pos > 180 ? pos = 180 : pos -= 10;// iterator value controls the rotation speed
      
      	
        myservo.write(pos);
        Serial.print("Moving to the left pos: ");
        Serial.println(pos);// tell servo to go to position in variable 'pos'
        //delay(250);// waits 15ms for the servo to reach the position
      	break;
    }else{
   
      	pos < 0 ? pos = 0 : pos += 10;

      	myservo.write(pos);
      	Serial.print("Moving to the right pos: ");
        Serial.println(pos);// tell servo to go to position in variable 'pos'
        //delay(250);// waits 15ms for the servo to reach the position
      	break;
      
    }
    
    //here can be added the second servo with upper photoresistor
    //that will compare the value with any of the lower one
  }
  
}