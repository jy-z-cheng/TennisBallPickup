#include "MovementController.h"

enum { MOVE_FORWARD, MOVE_BACKWARD, POINTTURN_LEFT, POINTTURN_RIGHT, SWINGTURN_LEFT, SWINGTURN_RIGHT, CRUDETURN_LEFT, CRUDETURN_RIGHT, NOTFOUND_PATROL };

enum { TENNISBALL_NOTFOUND, TENNISBALL_FRONT, TENNISBALL_LEFT, TENNISBALL_RIGHT };

MovementController::MovementController(void)
{
}


MovementController::~MovementController(void)
{
}

bool MovementController::start(char *portName)
{
	SP = new Serial(portName);    // adjust as needed
	
	if (SP->IsConnected())
		printf("We're connected");

	return SP->IsConnected();
}

void MovementController::sendRawCommand (int command)
{
	int dataLength = 8;

	switch (command)
	{
	case MOVE_FORWARD:
		SP->WriteData("W",dataLength);
		printf("move forward\n");
		break;
	case MOVE_BACKWARD:
		SP->WriteData("X",dataLength);
		printf("move backward\n");
		break;
	case POINTTURN_LEFT:
		SP->WriteData("A",dataLength);
		printf("point turn left\n");
		break;
	case POINTTURN_RIGHT:
		SP->WriteData("D",dataLength);
		printf("point turn right\n");
		break;
	case SWINGTURN_LEFT:
		SP->WriteData("A",dataLength);
		printf("swing turn left\n");
		break;
	case SWINGTURN_RIGHT:
		SP->WriteData("D",dataLength);
		printf("swing turn right\n");
		break;
	case CRUDETURN_LEFT:
		SP->WriteData("A",dataLength);
		printf("crude turn left\n");
		break;
	case CRUDETURN_RIGHT:
		SP->WriteData("D",dataLength);
		printf("crude turn right\n");
		break;
	case NOTFOUND_PATROL:
		SP->WriteData("L",dataLength);
		printf("notfound\n");
		break;
	default:
		//SP->WriteData("S",dataLength);
		break;
	}
}

void MovementController::sendCommandByVision (int visionCommand)
{
	switch (visionCommand)
	{
	case TENNISBALL_FRONT:
		sendRawCommand(MOVE_FORWARD);
		break;
	case TENNISBALL_LEFT:
		sendRawCommand(POINTTURN_LEFT);
		break;
	case TENNISBALL_RIGHT:
		sendRawCommand(POINTTURN_RIGHT);
		break;
	case TENNISBALL_NOTFOUND:
		sendRawCommand(NOTFOUND_PATROL);
		break;
	default:
		//SP->WriteData("S",dataLength);
		break;
	}
}