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

private:
	int prev_command;
	Serial* SP;
};
