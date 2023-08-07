// C++ code
// https://linuxhint.com/display-led-brightness-arduino/
// the code is the same as in the folder 3WorkingMandat

#include <LiquidCrystal.h>
//This library is compatible with all architectures so you should be able to use it on all the Arduino boards.
//source: https://www.arduino.cc/reference/en/libraries/liquidcrystal/

int rs=7;
int enable=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

int pot = A0;/* analog pin for potentiometer for LED brightness control*/
int led = 6;/* defining the LED pin for Arduino */
int Value = 0;/* declaring variable for storing the potentiometer value*/
int LEDvalue = 0; /* variable that will store the scalarizing value of pot*/
int status = 0; /* declaring the variable that will store the brightness value of LED */
int i = 0; /* declaring variable for using the for loop */
int status2=0; /* variable that will store the value of brightness in percentage */

LiquidCrystal lcd(rs,enable,d4,d5,d6,d7);
//https://www.arduino.cc/reference/en/libraries/liquidcrystal/liquidcrystal/
//d0, d1, d2, and d3 are optional; if omitted, the LCD will be controlled using only the four data lines (d4, d5, d6, d7).

//elements are the characters to show the scale of brightness
byte statusbar[8] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B10101,
  B11111,
  B10101,
  B01110
};

void setup()
{
  	//pinMode(LED_PIN, OUTPUT);
	lcd.begin(16,2);//2 rows with 8 elements
  //https://www.electronicwings.com/arduino/lcd-16x2-interfacing-with-arduino-uno
  /*
  This function is used to define the number of rows and columns the LCD has and to initialize the LCD.
  Needs to be called before calling other functions, once the object is defined using the function in point 1.
  Example, for 16x2 LCD we write lcd.begin(16,2) lcd is the name of the object of the class LiquidCrystal. 16 is the number of columns and 2 is the number of rows.

  */
}

void loop()
{

  Value = analogRead(pot);/* getting the value of potentiometer*/ 
  LEDvalue=map(Value, 0, 1024, 0, 255); /* scalarizing the  analog values in the range of PWM*/
  //LEDvalue=Value/4; // this version is also possible 
  analogWrite(led, LEDvalue); /* assigning the scalarizing values to the LED */
  status=map(LEDvalue, 0, 255, 0, 17);/* to display the status bar scalarizing the PWM values to the size of LCD*/
  lcd.setCursor(0,0);
  /*
  This function positions the cursor of the LCD to a location specified by the row and column parameters.
  col is the column number at which the cursor should be at (0 for column 1, 4 for column 5 and so on).
  row is the row number at which the cursor should be at (0 for row 1, 1 for row 2).
  Example, for setting the cursor at the 5th  column in the 2nd  row, lcd.setCursor(4,1) lcd is the name of the object of the class LiquidCrystal.
  */
  
  lcd.clear();//cleaning and reprinting the screen
  lcd.print("Brightness");
 
  status2=map(status, 0, 16, 0, 100);/* to display the percentage brightness bar scalizing LCD size values to 0 to 100*/
  lcd.setCursor(11,0); //from the 8th element on the first row
  lcd.print(status2);/* displaying the value of percentage on the place allocated in the above line */
  lcd.setCursor(14,0);
  lcd.print("%");/* display the parentage sign */

  for (i=0; i < status; i++)// to display the progress bar we have used the for loop*/
  {
    lcd.setCursor(i, 1);  
    lcd.write(byte(0));  /* displaying the character declared above */
  }
  delay(750);        
      
}