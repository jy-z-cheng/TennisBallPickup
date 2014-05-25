#include "Robot.h"


Robot::Robot(void)
{
}


Robot::~Robot(void)
{
}

double Robot::getXPosition()
{
	return Robot::xPos;
}

void Robot::setXPosition(double x)
{
	Robot::xPos = x;
}

double Robot::getYPosition()
{
	return Robot::yPos;
}

void Robot::setYPosition(double y)
{
	Robot::yPos = y;
}

double Robot::getAbsoluteHeading()
{
	return Robot::heading;
}

void Robot::setAbsoluteHeading(double h)
{
	Robot::heading = h;
}