// C++ code
//This is the variant with more wires

int GreenLed = 3;
int RedLed = 4;
int YellowLed = 5;
int MandatorySwitch = 2;
int BonusSwitch = 6;
int BonusSwitch1 = 7;
int SwitchState = digitalRead(MandatorySwitch);
int BonusState = digitalRead(BonusSwitch);
int BonusState1 = digitalRead(BonusSwitch1);
void setup()
{
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  pinMode(MandatorySwitch, INPUT);
  pinMode(BonusSwitch, INPUT);
}

void loop()
{
  SwitchState = digitalRead(MandatorySwitch);
  BonusState = digitalRead(BonusSwitch);
  BonusState1 = digitalRead(BonusSwitch1);
  if (SwitchState == LOW)
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
  if (BonusState == LOW)
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
  if (BonusState1 == LOW)
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


//This the version without additional wires and the connection of ground is from the green LED ground line: 

int GreenLed = 3;
int RedLed = 4;
int YellowLed = 5;
int MandatorySwitch = 2; // Madatory Part set at 2 to test else not used one.
int BonusSwitch = 7;    //Bonus1 set it to 2 to test else not used one.
int BonusSwitch1 = 7;   //Bonus1 set it to 2 to test else not used one.
int SwitchState = digitalRead(MandatorySwitch);
int BonusState = digitalRead(BonusSwitch);
int BonusState1 = digitalRead(BonusSwitch1);
void setup()
{
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(YellowLed, OUTPUT);
  pinMode(MandatorySwitch, INPUT);
  pinMode(BonusSwitch, INPUT);
  pinMode(BonusSwitch1, INPUT);
}

void loop()
{
  SwitchState = digitalRead(MandatorySwitch);
  BonusState = digitalRead(BonusSwitch);
  BonusState1 = digitalRead(BonusSwitch1);
  if (SwitchState == LOW)
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
  if (BonusState == LOW)
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
  if (BonusState1 == LOW)
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