/*

The project works according to the logics of the article:
https://circuitdigest.com/microcontroller-projects/interfacing-sound-sensor-with-arduino 

*/
#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 15
CRGB leds[NUM_LEDS];
const int ledPin = DATA_PIN;

int sound_sensor = A0; //assign to pin A2
 
void setup()
{
  pinMode(sound_sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //begin Serial Communication
  FastLED.addLeds<WS2812B,DATA_PIN,GRB>(leds,NUM_LEDS);
  FastLED.setBrightness(20);
}
 
void loop()
{
  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
//  Serial.print("Before bit shift:");
//  Serial.println(soundValue);
  soundValue >>= 5; //bitshift operation
  Serial.println(soundValue); //print the value of sound sensor
if (soundValue == 555)
 {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::White;
      }
   FastLED.show();
 }
else if (soundValue == 556 || soundValue == 554)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Violet;
      }
   FastLED.show();
 }
else if (soundValue == 557 || soundValue == 553)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Indigo;
      }
   FastLED.show();
 }
else if (soundValue == 558 || soundValue == 552)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Blue;
      }
   FastLED.show();
 }  
else if (soundValue == 559 || soundValue == 551)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Green;
      }
   FastLED.show();
 }
else if (soundValue == 560 || soundValue == 550)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Yellow;
      }
   FastLED.show();
 }
else if (soundValue == 561 || soundValue == 549)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Orange;
      }
   FastLED.show();
 }
else if (soundValue == 562 || soundValue == 548)
  {
  int j = 0;
      while (j < 64){
        leds[j++] = CRGB::Red;
      }
   FastLED.show();
 }
//if a value higher than 500 is registered, we will print the following
//this is done so that we can clearly see if the threshold is met
 
  delay(50); //a shorter delay between readings
}
