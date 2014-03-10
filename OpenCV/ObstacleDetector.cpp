#include "ObstacleDetector.h"


ObstacleDetector::ObstacleDetector(void)
{
}

ObstacleDetector::~ObstacleDetector(void)
{
}

bool ObstacleDetector::connect(char *portName, DWORD baudRate)
{
	SP = new Serial(portName, baudRate); 
	if (SP->IsConnected())
		printf("Sensor connected.\n");

	return SP->IsConnected();
}

void ObstacleDetector::readState()
{
	char incomingData[256] = "";			// don't forget to pre-allocate memory
	//printf("%s\n",incomingData);
	int dataLength = 256;
	int readResult = 0;

	if(SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData,dataLength);
		printf("Bytes read: (-1 means no data available) %i\n",readResult);

		std::string test(incomingData);

		printf("%s",incomingData);
		test = "";

		//Sleep(500);
	}
}