// C++ code
//pin numbers act like global var
int GreenLed = 3;
int RedLed = 4;
int YellowLed = 5;

//you may change the wire to the pin number or set pin 2 to the required variable  
int MandatorySwitch = 2; // For Madatory Part, set MandatorySwitch at 2 to test else not used one.
int BonusSwitch = 6;    //For Bonus, set BonusSwitch it to 2 to test else not used one.
int BonusSwitch1 = 7;   //For Bonus1, set BonusSwitch1 to 2 to test else not used one.


void setup()
{
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  pinMode(MandatorySwitch, INPUT);
  pinMode(BonusSwitch, INPUT);
  pinMode(BonusSwitch1, INPUT);
}

//other variables may be declared inside the function
void loop()
{
  int SwitchState = digitalRead(MandatorySwitch);
  int BonusState = digitalRead(BonusSwitch);
  int BonusState1 = digitalRead(BonusSwitch1);
  
  if (SwitchState == LOW)		//Mandatory Part
  {
    digitalWrite(GreenLed, HIGH);
    digitalWrite(RedLed, LOW);
    digitalWrite(YellowLed, LOW);
  }
  else if (SwitchState == HIGH)
  {
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    digitalWrite(YellowLed, HIGH);
    delay(1000);
    digitalWrite(RedLed, LOW);
    digitalWrite(YellowLed, LOW);
    delay(1000);
  }
  if (BonusState == LOW)		//First Bonus Part
  {
    digitalWrite(GreenLed, HIGH);
    digitalWrite(RedLed, LOW);
    digitalWrite(YellowLed, LOW);
  }
  else if (BonusState == HIGH)
  {
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    digitalWrite(YellowLed, LOW);
    delay(2000);
    digitalWrite(RedLed, LOW);
    digitalWrite(YellowLed, HIGH);
    delay(2000);
  }
  if (BonusState1 == LOW)		// Second Bonus part
  {
    digitalWrite(GreenLed, HIGH);
    digitalWrite(RedLed, LOW);
    digitalWrite(YellowLed, LOW);
  }
  else if (BonusState1 == HIGH)
  {
    digitalWrite(YellowLed, HIGH);
    digitalWrite(GreenLed, LOW);
    digitalWrite(RedLed, HIGH);
    delay(500);
    digitalWrite(RedLed, LOW);
    delay(500);
    digitalWrite(RedLed, HIGH);
    delay(500);
    digitalWrite(RedLed, LOW);
    delay(500);
    digitalWrite(YellowLed, LOW);
    digitalWrite(RedLed, HIGH);
    delay(500);
    digitalWrite(RedLed, LOW);
    delay(500);
    digitalWrite(RedLed, HIGH);
    delay(500);
    digitalWrite(RedLed, LOW);
    delay(500);
    digitalWrite(YellowLed, HIGH);
  }
}