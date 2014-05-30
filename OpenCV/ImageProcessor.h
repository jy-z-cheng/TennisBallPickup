#pragma once

#include <string>
#include <vector>
#include <math.h>

#include <opencv\highgui.h>
#include <opencv\cv.h>

#include "MotorController.h"
#include "Marker.h"
#include "Robot.h"

using namespace cv;
using namespace std;

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
    enum TennisBallLocation { TENNISBALL_NOTFOUND, TENNISBALL_FRONT, TENNISBALL_LEFT, TENNISBALL_RIGHT, TENNISBALL_IDLE };
    enum NavigationMode { MODE_CALIBRATION, MODE_LOCAL, MODE_GLOBAL};

private:
    MotorController motorController;
    bool isEnabled;
    bool calibrationMode;
    int navMode;

    //void on_trackbar( int, void* );
    string intToString(int number);
    void createTrackbars();

    void drawObject(RobotMath::Point thePoint,Mat &frame, string tag, Scalar colour);
    void drawObjects(vector<Marker> thePoints,Mat &frame);
    //void drawObjects(vector<RobotMath::Point> thePoints,Mat &frame);
    void drawLine(RobotMath::Point thePoint1, RobotMath::Point thePoint2, Mat &frame, Scalar colour);

	void morphOps(Mat &thresh);
    
	int checkPosition(bool haveBall, Marker tennisBall);
    void trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed);
    Marker trackRobotMarker(Mat threshold, Mat HSV, Mat &cameraFeed);
    void trackRobotState(Mat threshold1, Mat threshold2, Mat HSV, Mat &cameraFeed);
};