#include "DualVNH5019MotorShield.h"
#include "ArduinoMotorController.h"

ArduinoMotorController arduinoMotorController;

int incomingByte;    // a variable to read incoming serial data into

int command;

int tangentialSpeed = 200;

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
      arduinoMotorController._move(tangentialSpeed);
    } else if (incomingByte == 'X') {
      arduinoMotorController._move(-tangentialSpeed);
    } else if (incomingByte == 'S') {
      arduinoMotorController._move(0);
    } else if (incomingByte == 'Q') {
      arduinoMotorController._swingTurn(tangentialSpeed/2, tangentialSpeed);
    } else if (incomingByte == 'E') {
      arduinoMotorController._swingTurn(tangentialSpeed, tangentialSpeed/2);
    } else if (incomingByte == 'A') {
      arduinoMotorController._pointTurn(tangentialSpeed/2);
    } else if (incomingByte == 'D') {
      arduinoMotorController._pointTurn(-tangentialSpeed/2);
    } else if (incomingByte == 'Z') {
      arduinoMotorController._crudeTurn(tangentialSpeed);
    } else if (incomingByte == 'C') {
      arduinoMotorController._crudeTurn(-tangentialSpeed);
    } else {
      //arduinoMotorController._move(0);
      command = 0;
    }
  }
}


void loop()
{
  //Serial.write('O');
  //arduinoMotorController._pointTurn(-300);
  //arduinoMotorController._move(300);
  //arduinoMotorController._stop(300);
  //delay(50);
}
