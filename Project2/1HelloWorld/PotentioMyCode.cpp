// C++ code
//this code works
#include <LiquidCrystal.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);// I had d5 2 times

void setup()
{
lcd.begin(16,2);//2 rows with 8 elements
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello World");
      
}