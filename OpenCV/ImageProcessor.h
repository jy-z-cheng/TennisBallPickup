#pragma once

#include <string>
#include <vector>
#include "Marker.h"
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
	void setNavigationMode(int nmode);
	enum TennisBallLocation { TENNISBALL_NOTFOUND, TENNISBALL_FRONT, TENNISBALL_LEFT, TENNISBALL_RIGHT };
	enum NavigationMode { MODE_LOCAL, MODE_GLOBAL};

private:
	MotorController motorController;
	bool isEnabled;
	bool calibrationMode;
	int navMode;

	//void on_trackbar( int, void* );
	string intToString(int number);
	void createTrackbars();
	void drawObject(vector<Marker> theTennisBalls,Mat &frame);
	void morphOps(Mat &thresh);
	int checkPosition(bool haveBall, Marker tennisBall);
	void trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed);
	Marker trackRobotMarker(Mat threshold, Mat HSV, Mat &cameraFeed);
	void trackRobotState(Mat threshold1, Mat threshold2, Mat HSV, Mat &cameraFeed);
};