#include "RobotMath.h"

#include "PointRM.h"
#include "LineRM.h"

#define PI 3.14159265

namespace RobotMath
{
	// Find line coefficients
	Line findLine(Point pt1, Point pt2) 
	{
		Line theLine;

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

		//printf("%s", message.c_str);

		theLine.a = a;
		theLine.b = b;
		theLine.m = m;

		return theLine;
	}

	// Find the heading, in radians, from pt1 to pt2
	double findAbsoluteHeading(Point pt1, Point pt2)
	{
		double heading, dy, dx;

		dy = pt2.getYPosition() - pt1.getYPosition();
		dx = pt2.getXPosition() - pt1.getXPosition();

		heading = -atan2(dy, dx);

		if (heading < 0)
		{
			heading = 2*PI + heading;
		}

		return heading;
	}

	// http://math.ucsd.edu/~wgarner/math4c/derivations/distance/distptline.htm
	Point findClosestPointToLine(Point pt, Line tLn)
	{
		// Local variables for calculations
		double x1 = pt.getXPosition();
		double y1 = pt.getYPosition();

		double a = tLn.a;
		double b = tLn.b;
		double m = tLn.m;

		double x0 = 0;
		double y0 = 0;

		// Calculations
		if (a == 0)
		{
			x0 = -b;
			y0 = y1;
		}
		else
		{
			x0 = (m * y1 + x1 - m * b) / (m*m + 1);
			y0 = (m*m*y1 + m*x1 + b) / (m*m + 1);
		}

		Point closestPoint;

		closestPoint.setXPosition(x0);
		closestPoint.setYPosition(y0);

		return closestPoint;
	}

	double findShortestDistanceToLine(Point pt, Line tLn)
	{
		Point closestPoint = findClosestPointToLine(pt, tLn);
		double dist = findDistanceBetweenTwoPoints(pt, closestPoint);

		return dist;
	}

	double findDistanceBetweenTwoPoints(Point pt1, Point pt2)
	{
		double distance = sqrt((pt1.getXPosition() - pt2.getXPosition())^2 + (pt1.getYPosition() - pt2.getYPosition())^2);
		return distance;
	}
}
