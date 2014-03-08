#pragma once

#include "SerialClass.h"

class MovementController
{
public:
	MovementController(void);
	~MovementController(void);

	bool start(char *portName);

	void sendRawCommand (int command);

	void sendCommandByVision (int command);

private:
	int prev_command;
	Serial* SP;
};
