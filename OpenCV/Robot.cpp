#include "Robot.h"


Robot::Robot(void)
{
}


Robot::~Robot(void)
{
}

double Robot::getAbsoluteHeading()
{
	return Robot::heading;
}

void Robot::setAbsoluteHeading(double h)
{
	Robot::heading = h;
}