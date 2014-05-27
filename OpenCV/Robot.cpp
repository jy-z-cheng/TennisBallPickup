#include "Robot.h"

const int TOP = 0;
const int RIGHT = 1;
const int BOTTOM = 2;
const int LEFT = 3;

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

void Robot::setCorners(int* ix, int* iy)
{
	int* xS = ix;
	int* yS = iy;

	for (int ind = 0; ind < 4; ind++)
	{
		Robot::corners[ind].setXPosition(xS[ind]);
		Robot::corners[ind].setYPosition(yS[ind]);
	}

	for (int ind = 0; ind < 4; ind++)
	{
		int nextInd = ind + 1;
		if (nextInd >= 4)
		{
			nextInd = 0;
		}
		Robot::fences[ind] = RobotMath::findLine(corners[ind], corners[nextInd]);
	}
}

bool* Robot::verifyIfRobotInZone()
{

	bool borderCheck[4] = {0, 0, 0, 0};

	for (int ind = 0; ind < 4; ind++)
	{
		double a, b, m, refY, refX;
		
		RobotMath::Line currBorder = fences[ind];

        a=currBorder.a;
        b=currBorder.b;
        m=currBorder.m;

        if (ind==TOP || ind==BOTTOM)
		{
            if (m==0)
			{
                refY=b;
			}
            else
			{
                refY=m*Robot::getXPosition()+b;
			}
            
            if (ind==TOP)
			{
                if (Robot::getYPosition() <= refY)
				{
                    borderCheck[ind] = 1;
				}
			}
            else
			{
                if (Robot::getYPosition() > refY)
				{
                    borderCheck[ind] = 1;
				}
			}
		}
        else
		{
            if (a==0)
			{
                refX=-b;
			}
            else
			{
                refX=(Robot::getYPosition()-b)/m;
			}
            
            if (ind==RIGHT)
			{
                if (Robot::getXPosition() <= refX)
				{
                    borderCheck[ind] = 1;
				}
			}
            else
			{
                if (Robot::getXPosition() > refX)
				{
                    borderCheck[ind] = 1;
				}
			}            
		}
	}

	copy(borderCheck, borderCheck+4, Robot::borderChecks);

	return borderCheck;
}

RobotMath::Point Robot::getMidpoint()
{
	double xSum = 0;
	double ySum = 0;



	for (int ind = 0; ind < 4; ind++)
	{
		xSum = Robot::corners[ind].getXPosition();
		ySum = Robot::corners[ind].getYPosition();
	}

	Robot::midpoint.setXPosition(xSum/4.0);
	Robot::midpoint.setXPosition(ySum/4.0);

	return Robot::midpoint;
}

RobotMath::Point Robot::determineGoal(Point nextBall)
{
	int sum = 0;
	for (int ind=0; ind < 4; ind ++)
	{
		sum += borderChecks[ind];
	}

	if ( sum == 4 )
	{
		return nextBall;
	}
	else if ( sum == 2 )
	{
		return Robot::midpoint;
	}
	else if ( sum == 3 )
	{
		int vilatedInd = 0;

		for (int ind=0; ind < 4; ind ++)
		{
			if ( borderChecks[ind] == 0 )
			{
				vilatedInd = ind;
				break;
			}
		}

		RobotMath::Point robot_pos;
		robot_pos.setXPosition(Robot::getXPosition());
		robot_pos.setYPosition(Robot::getYPosition());

		return RobotMath::findClosestPointToLine(robot_pos, fences[vilatedInd]);
	}

}