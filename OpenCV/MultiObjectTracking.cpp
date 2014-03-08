/*
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <tchar.h>
#include "TennisBall.h"
#include "SerialClass.h"
*/
#include "MotorController.h"
#include "ImageProcessor.h"

using namespace cv;

int main(int argc, char* argv[])
{
	
	MotorController mC;
	mC.start("\\\\.\\COM17");

	ImageProcessor ip(mC);
	ip.process();

	return 0;
}
