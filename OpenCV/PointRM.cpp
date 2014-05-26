#include "PointRM.h"


RobotMath::Point::Point(void)
{
}


RobotMath::Point::~Point(void)
{
}

int RobotMath::Point::getXPosition()
{
	return RobotMath::Point::xPos_normalized;
}

void RobotMath::Point::setXPosition(int x)
{
	RobotMath::Point::xPos_normalized = x;
}

int RobotMath::Point::getYPosition()
{
	return RobotMath::Point::yPos_normalized;
}

int RobotMath::Point::getYPositionOriginal()
{
	return RobotMath::Point::yPos_original;
}

void RobotMath::Point::setYPosition(int y)
{
	RobotMath::Point::yPos_original = y;
	RobotMath::Point::yPos_normalized = 720-y;
}

