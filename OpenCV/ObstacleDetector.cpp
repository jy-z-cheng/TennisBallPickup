#include "ObstacleDetector.h"


ObstacleDetector::ObstacleDetector(void)
{
}

ObstacleDetector::~ObstacleDetector(void)
{
}

bool ObstacleDetector::start(char *portName)
{
	SP = new Serial(portName);    // adjust as needed
	
	//if (SP->IsConnected())
	//	printf("We're connected");

	return SP->IsConnected();
}