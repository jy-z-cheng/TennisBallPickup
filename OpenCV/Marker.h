#pragma once

#include <string>
#include <opencv\highgui.h>
#include <opencv\cv.h>

using namespace std;
using namespace cv;

class Marker
{
public:
	Marker(void);
	~Marker(void);

	int getXPosition();
	void setXPosition(int x);

	int getYPosition();
	void setYPosition(int y);

	Scalar getHSVMin();
	void setHSVMin(Scalar ihsvMin);

	Scalar getHSVMax();
	void setHSVMax(Scalar ihsvMax);

	bool isValid();
	void setValid(bool iValid);

private:
	bool valid;
	int xPos, yPos;
	Scalar hsvMax, hsvMin;
	
};

