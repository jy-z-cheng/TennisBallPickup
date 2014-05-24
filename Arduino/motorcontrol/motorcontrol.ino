#include "DualVNH5019MotorShield.h"
#include "ArduinoMotorController.h"

ArduinoMotorController arduinoMotorController;

int incomingByte;    // a variable to read incoming serial data into

int command;

int DESIREDSPEED = 340;

int currentSpeed;

int pastCommand;
int sameCommandCount;

void setup()
{
  Serial.begin(115200);
  arduinoMotorController.initialize();
}

void serialEvent()
{
  currentSpeed = DESIREDSPEED;
  
  if (command != pastCommand) {
    if (sameCommandCount > 3) {
      currentSpeed = 400;
    }
    sameCommandCount = 0;
  } else {
    sameCommandCount ++;
  }
  
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == 'W') {
      arduinoMotorController._move(currentSpeed);
    } else if (incomingByte == 'X') {
      arduinoMotorController._move(-currentSpeed);
    } else if (incomingByte == 'S') {
      arduinoMotorController._move(0);
    } else if (incomingByte == 'Q') {
      arduinoMotorController._swingTurn(currentSpeed/2, currentSpeed);
    } else if (incomingByte == 'E') {
      arduinoMotorController._swingTurn(currentSpeed, currentSpeed/2);
    } else if (incomingByte == 'A') {
      arduinoMotorController._pointTurn(currentSpeed/2);
    } else if (incomingByte == 'D') {
      arduinoMotorController._pointTurn(-currentSpeed/2);
    } else if (incomingByte == 'Z') {
      arduinoMotorController._crudeTurn(currentSpeed);
    } else if (incomingByte == 'C') {
      arduinoMotorController._crudeTurn(-currentSpeed);
    } else if (incomingByte == 'L') {
      arduinoMotorController._crudeTurn(290);
    } else {
      //arduinoMotorController._move(0);
      command = 0;
    }
  }
  
  pastCommand = command;
}


void loop()
{
  //Serial.write('O');
  //arduinoMotorController._pointTurn(-300);
  //arduinoMotorController._move(300);
  //arduinoMotorController._stop(300);
  //delay(50);
}
