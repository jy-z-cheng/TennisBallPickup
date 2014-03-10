#include "ObstacleDetector.h"


ObstacleDetector::ObstacleDetector(void)
{
}

ObstacleDetector::~ObstacleDetector(void)
{
}

bool ObstacleDetector::connect(char *portName, DWORD baudRate)
{
	SP = new Serial(portName, baudRate);    // adjust as needed
	
	//if (SP->IsConnected())
	//	printf("We're connected");

	return SP->IsConnected();
}