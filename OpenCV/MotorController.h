#pragma once

#include "SerialClass.h"
#include "ObstacleDetector.h"

class MotorController
{
public:
	MotorController(void);
	~MotorController(void);

	bool connect(char *portName, DWORD baudRate);

	void sendRawCommand (int command);
	void sendCommandByVision (int command);

	void setUltraSonicSensor(char *portName, DWORD baudRate);
	void initializeUltraSonicSensor();


	enum { STOP, MOVE_FORWARD, MOVE_BACKWARD, POINTTURN_LEFT, POINTTURN_RIGHT, SWINGTURN_LEFT, SWINGTURN_RIGHT, CRUDETURN_LEFT, CRUDETURN_RIGHT, NOTFOUND_PATROL };

private:
	int prev_command;
	Serial* SP;

	ObstacleDetector obstacleDetector;

	char *sensorPortName;
	DWORD sensorBaudRate;
};
