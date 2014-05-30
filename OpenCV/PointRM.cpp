#include "PointRM.h"


RobotMath::Point::Point(void)
{
}

RobotMath::Point::Point(int x, int y)
{
	RobotMath::Point::xPos = x;
	RobotMath::Point::yPos = y;
}

RobotMath::Point::~Point(void)
{
}

int RobotMath::Point::getXPosition()
{
    return RobotMath::Point::xPos;
}

void RobotMath::Point::setXPosition(int x)
{
    RobotMath::Point::xPos = x;
}

int RobotMath::Point::getYPosition()
{
    return RobotMath::Point::yPos;
}

void RobotMath::Point::setYPosition(int y)
{
    RobotMath::Point::yPos = y;
}

