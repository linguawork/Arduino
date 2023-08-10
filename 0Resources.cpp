/*some resources in Russian
https://www.youtube.com/playlist?list=PLgAbBhxTglwmVxDDC5TSYUI91oZ0LZQMw 
Алекс Гайвер


https://search.arduino.cc/search?q=arduino%20uno%20r3&tab=projecthub
проекты Ардуино

Уроки Arduino #1 - структура программы и типы данных  https://www.youtube.com/watch?v=CRRlbzzt3VA  

Уроки Arduino #2 - работа с монитором COM порта  https://www.youtube.com/watch?v=gmgw6nLgzbY

*/



/*Arduino tutorial in English (FOR Arduino UNO R3)

https://www.youtube.com/watch?v=fJWR7dBuc18
    Arduino Tutorial 1: Setting Up and Programming the Arduino for Absolute Beginners
        https://www.arduino.cc/en/software Arduino software to download
*/

/*SIMULATOR OF ARDUINO
https://www.tinkercad.com/things/g1182wjWonM-glorious-lahdi-fulffy/editel?sharecode=UVMSzY9JRu9H5BbeCHxEMUg_qqvwE1EiqNDIq9Kh7OU
*/

/*
Ликбез по электротехнике.

https://www.youtube.com/watch?v=3596An8qDec
Заземление. Кто придумал? Зачем? Какие бывают системы заземления. Мощный #энерголикбез

https://www.youtube.com/watch?v=QRDKSX8ahE0&t=77s
Почему птицу на проводе ЛЭП не бьет током? А человека будет бить?#энерголикбез
*/


/*
LCD 16X2 explained the pins 
https://www.elprocus.com/lcd-16x2-pin-configuration-and-its-working/
*/


/*
Chat:

Here's how the voltage range from 0 to 5 volts is converted to a range from 0 to 1023:

Voltage Range: The maximum voltage that the ADC of most Arduino boards 
can handle is the reference voltage. In most cases, 
this reference voltage is 5 volts for Arduino boards that are powered with 5 volts.

Resolution: The analog-to-digital converter divides 
the reference voltage range into a certain number of discrete steps,
 which determines the resolution of the ADC. For an Arduino ADC with 
 a 10-bit resolution, there are 2^10 (1024) possible steps.

Mapping: The analog voltage being measured is mapped 
to the available range of digital values. In the case of a 10-bit ADC, 
the range is divided into 1024 steps, ranging from 0 to 1023.

So, when you call analogRead() on an Arduino pin, 
the ADC measures the voltage on that pin, 
maps it to a value between 0 and 1023 (corresponding to the full range of 0 to 5 volts), 
and returns that value as an integer.

Mathematically, the formula for converting the analog value to voltage is:

Voltage = (AnalogValue * ReferenceVoltage) / MaximumDigitalValue

In the case of Arduino with a 5V reference voltage and a 10-bit ADC (1024 steps),
the formula simplifies to:
Voltage = (AnalogValue * 5.0) / 1023.0


*/