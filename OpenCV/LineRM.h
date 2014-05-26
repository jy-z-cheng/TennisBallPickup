#pragma once

#include "RobotMath.h"

class RobotMath::Line
{
public:
	Line(void);
	~Line(void);
	
	// y-coefficient
	double a;

	// y-intercept
	double b;
	
	// slope or x-coefficient
	double m;
};

