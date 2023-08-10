/*
https://www.youtube.com/watch?v=WMkN-uHd-Xo
Arduino Tutorial 25: Understanding Photoresistors and Photo Detectors


*/

// C++ code
//
int currA0 = A0;
int lightVal;
  
//настройка всех подключений
void setup()
{
  pinMode(currA0, INPUT);// getting connection from the circuit into the board
	Serial.begin(9600);
}


void loop()
{
	lightVal = analogRead(currA0); // getting current value from pin
    Serial.println(lightVal);//распечатка аналоговых значений
  	delay(250);
}