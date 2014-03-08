#pragma once

#include <string>
#include <vector>
#include "TennisBall.h"
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include "MotorController.h";

using namespace std;
using namespace cv;

class ImageProcessor
{
public:
	ImageProcessor(MotorController &mc);
	//ImageProcessor(void);
	~ImageProcessor(void);
	void process();
	void setCalibrationMode(bool enable);
	void setEnable(bool enable);

private:
	MotorController motorController;
	bool isEnabled;
	bool calibrationMode;

	//void on_trackbar( int, void* );
	string intToString(int number);
	void createTrackbars();
	void drawObject(vector<TennisBall> theTennisBalls,Mat &frame);
	void morphOps(Mat &thresh);
	int checkPosition(bool haveBall, TennisBall tennisBall);
	void trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed);

};