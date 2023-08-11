//Modified during the trial:
Serial.println(lightValLeft);//распечатка аналоговых значений
    lightValRight = analogRead(currA1); // getting current value from pin
    Serial.print("The left light value is: ");
    Serial.println(lightValLeft);
    Serial.print("The right light value is: ");
    Serial.println(lightValRight);
    delay(100); //without delay is not good for motor reaction. The changing
    // of resistors is too fast and motor sometimes reacts in different directions
  
  while (lightValLeft != lightValRight){
    if (lightValLeft > lightValRight){ 
      
        pos > 175 ? pos = 175 : pos +=5;// iterator value controls the rotation speed
      
        myservo.write(pos);
        Serial.print("Moving to the left pos: ");
        Serial.println(pos);// tell servo to go to position in variable 'pos'
        //delay(250);// waits 15ms for the servo to reach the position
        break;
    }else{
   
        pos < 5 ? pos = 5 : pos -= 5;

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