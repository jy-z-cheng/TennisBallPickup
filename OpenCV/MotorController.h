#pragma once

#include "SerialClass.h"

class MotorController
{
public:
	MotorController(void);
	~MotorController(void);

	bool start(char *portName);

	void sendRawCommand (int command);

	void sendCommandByVision (int command);

	enum { STOP, MOVE_FORWARD, MOVE_BACKWARD, POINTTURN_LEFT, POINTTURN_RIGHT, SWINGTURN_LEFT, SWINGTURN_RIGHT, CRUDETURN_LEFT, CRUDETURN_RIGHT, NOTFOUND_PATROL };

private:
	int prev_command;
	Serial* SP;
};
