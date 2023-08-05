// C++ code

// #define LED_PIN 5
// #define POTENTIOMETER_PIN A1
#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

int pot = A0;/* analog pin for potentiometer for LED brightness control*/
int led = 6;/* defining the LED pin for Arduino */
int Value = 0;/* declaring variable for storing the potentiometer value*/
int LEDvalue = 0; /* variable that will store the scalarizing value of pot*/


LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup()
{
  	//pinMode(LED_PIN, OUTPUT);
  
	lcd.begin(16,2);//2 rows with 8 elements
}

void loop()
{
  
  //int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  //int brightness = potentiometerValue / 4;
  //analogWrite(LED_PIN, brightness);
  
  Value = analogRead(pot);/* getting the value of potentiometer*/ 
  LEDvalue=map(Value, 0, 1024, 0, 255); /* scalarizing the  analog values in the range of PWM*/
  analogWrite(led, LEDvalue); /* assigning the scalarizing values to the LED */
  
  lcd.setCursor(0,0);
  lcd.print("Brightness");
      
}