#include "Robot.h"

const int TOP = 1;
const int RIGHT = 2;
const int BOTTOM = 3;
const int LEFT = 4;

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
		if (nextInd > 4)
		{
			nextInd = 1;
		}
		Robot::fences[ind] = RobotMath::findLine(corners[ind], corners[nextInd]);
	}
}

bool* Robot::verifyIfRobotInZone(RobotMath::Line* ifences)
{
	*Robot::fences = *ifences;

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
                refY=m*Robot::xPos+b;
			}
            
            if (ind==TOP)
			{
                if (Robot::yPos <= refY)
				{
                    borderCheck[ind] = 1;
				}
			}
            else
			{
                if (Robot::yPos > refY)
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
                refX=(Robot::yPos-b)/m;
			}
            
            if (ind==RIGHT)
			{
                if (Robot::xPos <= refX)
				{
                    borderCheck[ind] = 1;
				}
			}
            else
			{
                if (Robot::xPos > refX)
				{
                    borderCheck[ind] = 1;
				}
			}            
		}
	}
	return borderCheck;
}