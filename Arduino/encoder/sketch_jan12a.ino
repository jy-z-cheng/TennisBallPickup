#include "DualVNH5019MotorShield.h"
#include "ArduinoMotorController.h"

ArduinoMotorController arduinoMotorController;

 int val;
 int encoder0PinA = 3;
 int encoder0PinB = 5;
 int encoder0Pos = 0;
 int lastN = -1;
 int lastM = -1;
 int n = LOW;
 int m = LOW;


 void setup() { 

   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   
   Serial.begin(115200);
   arduinoMotorController.initialize();
 } 

void loop() {
arduinoMotorController._move(0);
  while ( encoder0Pos < 2000)
  {
     arduinoMotorController._move(200);
     
     n = digitalRead(encoder0PinA);
     //m = digitalRead(encoder0PinB);
     
     if ( lastN != n) {
       encoder0Pos++;
       lastN = n;
     }

     //if ( lastM != m) {
     //  encoder0Pos++;
     //  lastM = m;
     //}  

     Serial.print (encoder0Pos);
     Serial.println ("/");
   }
   //arduinoMotorController._move(200);
 }  

