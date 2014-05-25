#pragma once

#include <string>
#include <opencv\highgui.h>
#include <opencv\cv.h>

#include "RobotMath.h"
#include "PointRM.h"

using namespace cv;

class Marker: public RobotMath::Point
{
public:
	Marker(void);
	~Marker(void);

	Scalar getHSVMin();
	void setHSVMin(Scalar ihsvMin);

	Scalar getHSVMax();
	void setHSVMax(Scalar ihsvMax);

	bool isValid();
	void setValid(bool iValid);

private:
	bool valid;
	Scalar hsvMax, hsvMin;
	
};

