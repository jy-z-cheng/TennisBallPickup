#include "Marker.h"


Marker::Marker(void)
{
}


Marker::~Marker(void)
{
}

int Marker::getXPosition()
{
	return Marker::xPos;
}

void Marker::setXPosition(int x)
{
	Marker::xPos = x;
}

int Marker::getYPosition()
{
	return Marker::yPos;
}

void Marker::setYPosition(int y)
{
	Marker::yPos = y;
}

Scalar Marker::getHSVMin()
{
	return Marker::hsvMin;
}

void Marker::setHSVMin(Scalar ihsvMin)
{
	Marker::hsvMin = ihsvMin;
}

Scalar Marker::getHSVMax()
{
	return Marker::hsvMax;
}

void Marker::setHSVMax(Scalar ihsvMax)
{
	Marker::hsvMax = ihsvMax;
}

bool Marker::isValid()
{
	return Marker::valid;
}

void Marker::setValid(bool iValid)
{
	Marker::valid = iValid;
}