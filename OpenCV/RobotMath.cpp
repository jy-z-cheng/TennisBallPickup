#include "RobotMath.h"

#include "PointRM.h"

namespace RobotMath
{
	//
	void findSlopeOfLine(Point pt1, Point pt2) 
	{
		string message;

		double a, b, m;
		double dx, dy;

		dx = pt2.getXPosition() - pt1.getXPosition();
		dy = pt2.getYPosition() - pt2.getYPosition();

		if (dx == 0)
		{
			b = - pt2.getXPosition();
			a = 0;
			m = 1;

			message = "x = " + to_string(-b);
		}
		else if (dy == 0)
		{
			b = pt2.getYPosition();
			a = 1;
			m = 0;

			message = "x = " + to_string(-b);
		}
		else
		{
			m = dy / dx;
			a = 1;
			b = pt2.getYPosition() - m * pt2.getXPosition();

			message = "y = " + to_string(m) + " * x + " + to_string(b);
		}

		printf("%s", message.c_str);
	}
	void function2() 
	{
		//code
	}
	void function3() 
	{
		//code
	}
}
