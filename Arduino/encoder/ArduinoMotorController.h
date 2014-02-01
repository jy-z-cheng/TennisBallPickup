#ifndef ArduinoMotorController_h
#define ArduinoMotorController_h

#include "Arduino.h"
#include "DualVNH5019MotorShield.h"

/*
A message structure will be:
switch mode (2):
    byte COMMAND_SWITCH_MODE, byte mode
run (5):
    byte COMMAND_RUN, int speedL, int speedR
analogWrite (3):
    byte COMMAND_ANALOG_WRITE, byte codename, byte value;
digitalWrite (3):
    byte COMMAND_DIGITAL_WRITE, byte codename, byte value;
analogRead (2):
    byte COMMAND_ANALOG_READ, byte codename;
analogRead _return_ (4):
    byte COMMAND_ANALOG_READ_RE, byte codename, int value;
digitalRead (2):
    byte COMMAND_DIGITAL_READ, byte codename;
digitalRead _return_ (4):
    byte COMMAND_DIGITAL_READ_RE, byte codename, int value;
read IR (1):
    byte COMMAND_READ_IR;
read IR _return_ (9):
    byte COMMAND_READ_IR_RE, int valueA, int valueB, int valueC, int valueD;


*/

class ArduinoMotorController
{
    public:
        ArduinoMotorController();
        void initialize();

        void process();

        void parseCommand();

        //Motion
        void _move(int wheelSpeed);
        void _stop(int brake);
        void _pointTurn(int wheelSpeed);
        void _crudeTurn(int wheelSpeed);
        void _swingTurn(int rSpeed, int lSpeed);

        //int IRread(uint8_t num);

        //void setMode(uint8_t mode);
        //void pauseMode(bool onOff);

        //void motorsWrite(int speedL, int speedR);
        //void motorsWritePct(int speedLpct, int speedRpct);//write motor values in percentage
        //void motorsStop();        
    private:

        //Both wheels
        void _stopIfFault();
        void _turnWheels(int rSpeed, int lSpeed);
        void _brakeWheels(int rBrake, int lBrake);

        //Right Wheel
        void _stopIfM1Fault();

        void _turnRightWheel(int wheelSpeed);
        void _brakeRightWheel(int brake);

        //Left Wheel
        void _stopIfM2Fault();
        void _turnLeftWheel(int wheelSpeed);
        void _brakeLeftWheel(int brake);
};

#endif


