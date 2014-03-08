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
	ImageProcessor ip;
	ip.process();

	MotorController mC;

	mC.start("\\\\.\\COM17");
	

	return 0;
}
