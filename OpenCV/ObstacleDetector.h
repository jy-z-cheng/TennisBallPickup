#pragma once

#include "SerialClass.h"

class ObstacleDetector
{
public:
	ObstacleDetector(void);
	~ObstacleDetector(void);

	bool start(char *portName);



private:
	Serial* SP;
};