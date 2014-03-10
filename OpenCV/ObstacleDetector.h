#pragma once

#include "SerialClass.h"

class ObstacleDetector
{
public:
	ObstacleDetector(void);
	~ObstacleDetector(void);

	bool connect(char *portName, DWORD baudRate);



private:
	Serial* SP;
};