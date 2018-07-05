#include <Keyboard.h>

 int pressed = 0;
 int joyPin1 = A0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = A1;                 // slider variable connecetd to analog pin 1
 int joyPin3 = A2;                 // slider variable connecetd to analog pin 2
 int joyPin4= A3;                 // slider variable connecetd to analog pin 3
 int stick1X = 0;                  // variable to read the value from the analog pin 0
 int stick1Y = 0;                  // variable to read the value from the analog pin 1   
 int stick2X = 0;                  // variable to read the value from the analog pin 2
 int stick2Y = 0;                  // variable to read the value from the analog pin 3    
 int oldstick1X = 0; 
 int oldstick1Y = 0;
 int oldstick2X = 0;
 int oldstick2Y = 0;    
 int change1 = 1;
 int change2 = 1;
 int buttonpin = 9;
 unsigned long t1 , t2;
 void setup() {
  pinMode(13, OUTPUT);
 }

int checkval(int stick1X , int stick1Y,int stick2X , int stick2Y){
  
  if(change1 == 1)
  {
    if(stick1X < 460)
    { // above
      Keyboard.press(87);
      change1 = 0;  
      oldstick1X = stick1X;
      oldstick1Y = stick1Y;
    }
    if(stick1Y < 460)
    { // left
      Keyboard.press(65);
      change1 = 0;  
      oldstick1X = stick1X;
      oldstick1Y = stick1Y;
    }
    if(stick1X > 560)
    { // down
    Keyboard.press(83);
    change1 = 0;  
    oldstick1X = stick1X;
    oldstick1Y = stick1Y;
    }
    if(stick1Y > 560)
    { // right
    Keyboard.press(68);
    change1 = 0;  
    oldstick1X = stick1X;
    oldstick1Y = stick1Y;
    }
  } 
  if(oldstick1X + 40 < stick1X || oldstick1X - 40 > stick1X || oldstick1Y + 40 < stick1Y || oldstick1Y - 40 > stick1Y)
  {
     Keyboard.release(87); // Down
     Keyboard.release(65); // Up
     Keyboard.release(83); // Left
     Keyboard.release(68); // Right
     change1 = 1;
  }
  if(change2 == 1)
  {
    if(stick2X < 460)
    { // down
      Keyboard.press(KEY_DOWN_ARROW);
      change2 = 0;  
      oldstick2X = stick2X;
      oldstick2Y = stick2Y;
    }
    if(stick2Y < 460)
    { // left
      Keyboard.press(KEY_LEFT_ARROW);
      change2 = 0;  
      oldstick2X = stick2X;
      oldstick2Y = stick2Y;
    }
    if(stick2X > 560)
    { // up
      Keyboard.press(KEY_DOWN_ARROW);
      change2 = 0;  
      oldstick2X = stick2X;
      oldstick2Y = stick2Y;
    }
    if(stick2Y > 560)
    { // right
      Keyboard.press(KEY_RIGHT_ARROW);
      change2 = 0;  
      oldstick2X = stick2X;
      oldstick2Y = stick2Y;
    }
  }  
  if(oldstick2X + 40 < stick2X || oldstick2X - 40 > stick2X || oldstick2Y + 40 < stick2Y || oldstick2Y - 40 > stick2Y)
  {
     Keyboard.release(KEY_DOWN_ARROW); // Down
     Keyboard.release(KEY_UP_ARROW); // Up
     Keyboard.release(KEY_LEFT_ARROW); // Left
     Keyboard.release(KEY_RIGHT_ARROW); // Right
     change2 = 1;
  }
  return 1;
}


 void loop(){
  // reads the value of the variable resistor 
  stick1X = analogRead(joyPin1);   
  stick1Y = analogRead(joyPin2); 
  stick2X = analogRead(joyPin3);   
  stick2Y = analogRead(joyPin4); 

  checkval(stick1X , stick1Y ,stick2X, stick2Y);
  
}
