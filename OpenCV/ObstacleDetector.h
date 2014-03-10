#pragma once

#include "SerialClass.h"
#include <string>


class ObstacleDetector
{
public:
	ObstacleDetector(void);
	~ObstacleDetector(void);

	bool connect(char *portName, DWORD baudRate);

	void readState();


private:
	Serial* SP;
};