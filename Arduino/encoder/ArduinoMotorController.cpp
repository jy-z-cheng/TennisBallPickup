#include "DualVNH5019MotorShield.h"
#include "ArduinoMotorController.h"

DualVNH5019MotorShield md;

const bool isMotorDebug = false;

ArduinoMotorController::ArduinoMotorController()
{
    
}

void ArduinoMotorController::initialize()
{
	if (isMotorDebug)
	{
	    Serial.println("Dual VNH5019 Motor Shield");
    }
    md.init();
}

void ArduinoMotorController::process()
{
}

void ArduinoMotorController::parseCommand()
{
}


//Right Wheel
void logM1()
{
	if (isMotorDebug)
	{
		Serial.print("M1 current: ");
		Serial.println(md.getM1CurrentMilliamps());
	}
}

void ArduinoMotorController::_stopIfM1Fault()
{
    if (md.getM1Fault())
    {
        Serial.println("M1 fault");
        while(1);
    }
}

void ArduinoMotorController::_turnRightWheel(int wheelSpeed)
{
    int _wheelSpeed = wheelSpeed;
    md.setM1Speed(_wheelSpeed);
    _stopIfM1Fault();
    logM1();
}

void ArduinoMotorController::_brakeRightWheel(int brake)
{
    int _brake = brake;
    md.setM1Brake(_brake);
    _stopIfM1Fault();
    logM1();
}


//Left Wheel
void logM2()
{
	if (isMotorDebug)
	{
        Serial.print("M2 current: ");
        Serial.println(md.getM2CurrentMilliamps());
	}
}

void ArduinoMotorController::_stopIfM2Fault()
{
    if (md.getM2Fault())
    {
        Serial.println("M2 fault");
        while(1);
    }
}

void ArduinoMotorController::_turnLeftWheel(int wheelSpeed)
{
    int _wheelSpeed = wheelSpeed;
    md.setM2Speed(_wheelSpeed);
    _stopIfM2Fault();
    logM2();
}

void ArduinoMotorController::_brakeLeftWheel(int brake)
{
    int _brake = -brake;
    md.setM2Brake(_brake);
    _stopIfM2Fault();
    logM2();
}

//Both wheels
void ArduinoMotorController::_stopIfFault()
{
    if (md.getM1Fault())
    {
        Serial.println("M1 fault");
        while(1);
    }
    if (md.getM2Fault())
    {
        Serial.println("M2 fault");
        while(1);
    }
}

void ArduinoMotorController::_turnWheels(int rSpeed, int lSpeed)
{
    int _rSpeed = rSpeed;
    int _lSpeed = lSpeed;
    md.setSpeeds(_rSpeed, _lSpeed);
    _stopIfFault();
    logM1();
    logM2();
}

void ArduinoMotorController::_brakeWheels(int rBrake, int lBrake)
{
    int _rBrake = rBrake;
    int _lBrake = lBrake;
    md.setBrakes(_rBrake, _lBrake);
    _stopIfFault();
    logM1();
    logM2();
}

//Motion
void ArduinoMotorController::_move(int sSpeed)
{
    int _speed = sSpeed;
    _turnWheels(_speed, _speed);
}

void ArduinoMotorController::_stop(int brake)
{
    int _brake = brake;
    _brakeWheels(_brake, _brake);
}

void ArduinoMotorController::_pointTurn(int sSpeed)
{
    int _speed = sSpeed;
    _turnWheels(-_speed, _speed);
}

void ArduinoMotorController::_crudeTurn(int sSpeed)
{
    int _speed = sSpeed;
    if (_speed >= 0)
    {
        _turnRightWheel(_speed);
        //_brakeLeftWheel(_speed);
        _turnLeftWheel(0);
    }
    else
    {
        _turnRightWheel(0);
        //_brakeRightWheel(_speed);
        _turnLeftWheel(-_speed);
    }
}

void ArduinoMotorController::_swingTurn(int rSpeed, int lSpeed)
{
    int _rSpeed = rSpeed;
    int _lSpeed = lSpeed;
    _turnWheels(_rSpeed, _lSpeed);
}


