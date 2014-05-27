#include "Marker.h"


Marker::Marker(void)
{
}


Marker::~Marker(void)
{
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