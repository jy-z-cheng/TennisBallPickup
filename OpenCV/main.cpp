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
#include "RobotControlUI.h"

using namespace cv;

using namespace System;
using namespace System::Windows::Forms;

int main(int argc, char* argv[])
{

	MotorController motorController;
	motorController.start("\\\\.\\COM17", CBR_115200);
	
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	TennisBallCollection::RobotControlUI form(motorController);
    Application::Run(%form);

	/*
		
	MotorController mC;
	mC.start("\\\\.\\COM17");

	ImageProcessor ip(mC);
	ip.process();
	*/

	return 0;
}