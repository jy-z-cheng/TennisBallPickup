#pragma once

#include <string>
#include <opencv\highgui.h>
#include <opencv\cv.h>

#include "RobotMath.h"
#include "PointRM.h"
#include "LineRM.h"

using namespace cv;

class Robot: public RobotMath::Point
{
public:
	Robot(void);
	~Robot(void);

	double getAbsoluteHeading();
	void setAbsoluteHeading(double h);

	void setCorners(int* ix, int* iy);

	bool* verifyIfRobotInZone(RobotMath::Line* ifences);

private:
	bool valid;
	double xPos, yPos, heading;

	RobotMath::Point corners[4];

	RobotMath::Line fences[4];
};


