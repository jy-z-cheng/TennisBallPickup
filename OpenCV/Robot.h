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

    bool* verifyIfRobotInZone();

    RobotMath::Point getMidpoint();

    RobotMath::Point determineGoal(Point nextBall);

private:
    bool valid;
    double heading;

    RobotMath::Point corners[4];

    RobotMath::Line fences[4];

    bool borderChecks[4];

    RobotMath::Point midpoint;
};


