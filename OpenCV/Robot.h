#pragma once

#include <string>
#include <opencv\highgui.h>
#include <opencv\cv.h>

using namespace std;
using namespace cv;

class Robot
{
public:
	Robot(void);
	~Robot(void);

	double getXPosition();
	void setXPosition(double x);

	double getYPosition();
	void setYPosition(double y);

	double getAbsoluteHeading();
	void setAbsoluteHeading(double h);

private:
	bool valid;
	double xPos, yPos, heading;
	
};


