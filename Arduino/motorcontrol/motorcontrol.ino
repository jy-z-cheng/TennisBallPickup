#include "DualVNH5019MotorShield.h"
#include "ArduinoMotorController.h"

ArduinoMotorController arduinoMotorController;

int incomingByte;    // a variable to read incoming serial data into

int command;

void setup()
{
  Serial.begin(115200);
  arduinoMotorController.initialize();
}

void serialEvent()
{
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == 'W') {
      command = 1;
    } else if (incomingByte == 'X') {
      command = 2;
    } else if (incomingByte == 'S') {
      command = 3;
    } else if (incomingByte == 'Q') {
      command = 4;
    } else if (incomingByte == 'E') {
      command = 5;
    } else if (incomingByte == 'A') {
      command = 6;
    } else if (incomingByte == 'D') {
      command = 7;
    } else if (incomingByte == 'Z') {
      command = 8;
    } else if (incomingByte == 'C') {
      command = 9;
    } else {
      command = 0;
    }
  }
}


void loop()
{
  int tangentialSpeed = 300;
  
  //command = -1;
  switch(command){
    case 0:
    //arduinoMotorController._move(0);
    //arduinoMotorController._stop(tangentialSpeed);
    command = -1;
        break;
    case 1: //W
        arduinoMotorController._move(tangentialSpeed);
    command = 0;
        break;
    case 2: //X
    arduinoMotorController._move(-tangentialSpeed);
    command = 0;
        break;
    case 3: //S
    arduinoMotorController._move(0);
    command = 0;
        break;
    case 4: //Q
    arduinoMotorController._swingTurn(tangentialSpeed/2, tangentialSpeed);
    command = 0;
        break;
    case 5:  //E
    arduinoMotorController._swingTurn(tangentialSpeed, tangentialSpeed/2);
    command = 0;
        break;
    case 6:  //A
    arduinoMotorController._pointTurn(tangentialSpeed/2);
    command = 0;
        break;
    case 7:  //D
    arduinoMotorController._pointTurn(-tangentialSpeed/2);
    command = 0;
        break;
    case 8: //Z
    arduinoMotorController._crudeTurn(tangentialSpeed);
    command = 0;
        break;
    case 9: //C
    arduinoMotorController._crudeTurn(-tangentialSpeed);
    command = 0;
        break;
  }

  //arduinoMotorController._pointTurn(-300);
  //arduinoMotorController._move(300);
  //arduinoMotorController._stop(300);
  delay(100);
}
