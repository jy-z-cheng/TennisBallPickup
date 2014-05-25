#pragma once

#include <string>
#include <opencv\highgui.h>
#include <opencv\cv.h>

#include "RobotMath.h"
#include "PointRM.h"

using namespace cv;

class Robot: public RobotMath::Point
{
public:
	Robot(void);
	~Robot(void);

	double getAbsoluteHeading();
	void setAbsoluteHeading(double h);

private:
	bool valid;
	double xPos, yPos, heading;
	
};


