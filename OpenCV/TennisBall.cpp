#include "TennisBall.h"


TennisBall::TennisBall(void)
{
}


TennisBall::~TennisBall(void)
{
}

int TennisBall::getXPosition()
{
	return TennisBall::xPos;
}

void TennisBall::setXPosition(int x)
{
	TennisBall::xPos = x;
}

int TennisBall::getYPosition()
{
	return TennisBall::yPos;
}

void TennisBall::setYPosition(int y)
{
	TennisBall::yPos = y;
}
