//objectTrackingTutorial.cpp

//Written by  Kyle Hounslow 2013

//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software")
//, to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//IN THE SOFTWARE.

#include "ImageProcessor.h"

enum { MOVE_FORWARD, MOVE_BACKWARD, POINTTURN_LEFT, POINTTURN_RIGHT, SWINGTURN_LEFT, SWINGTURN_RIGHT, CRUDETURN_LEFT, CRUDETURN_RIGHT };

const int LAPTOP = 0;
const int WEBCAM = 1;

//const int laptopFilter[6] = {31, 47, 53, 177, 103, 256};
//const int webcamFilter[6] = {26, 40, 0, 256, 242, 256};

// fish bowel - laptop
const int laptopFilter[6] = { 18, 42, 30, 100, 116, 256 };
	// {28, 77, 75, 256, 74, 256};
// default {26, 77,47,256,74,256};
//{47, 77, 18, 256, 235, 256};

// fish bowel - WEBCAM
//const int laptopFilter[6] = {14, 53, 32, 256, 0, 256};

int state = ImageProcessor::TENNISBALL_NOTFOUND;

int cameraInUse = LAPTOP;

int H_MIN_YELLOW = 0;
int H_MAX_YELLOW = 256;
int S_MIN_YELLOW = 0;
int S_MAX_YELLOW = 256;
int V_MIN_YELLOW = 0;
int V_MAX_YELLOW = 256;

//initial min and max HSV filter values.
//these will be changed using trackbars
int H_MIN = 0;
int H_MAX = 256;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20*20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string windowName3 = "After Morphological Operations";
const string trackbarWindowName = "Trackbars";

ImageProcessor::ImageProcessor(MotorController &mc): motorController(mc)
{
}

/*
ImageProcessor::ImageProcessor()
{
}
*/

ImageProcessor::~ImageProcessor()
{
}

void on_trackbar( int, void* )
{//This function gets called whenever a
	// trackbar position is changed





}

string ImageProcessor::intToString(int number)
{


	std::stringstream ss;
	ss << number;
	return ss.str();
}

void ImageProcessor::createTrackbars(){
	//create window for trackbars


	namedWindow(trackbarWindowName,0);
	//create memory to store trackbar name on window
	char TrackbarName[50];
	sprintf( TrackbarName, "H_MIN", H_MIN);
	sprintf( TrackbarName, "H_MAX", H_MAX);
	sprintf( TrackbarName, "S_MIN", S_MIN);
	sprintf( TrackbarName, "S_MAX", S_MAX);
	sprintf( TrackbarName, "V_MIN", V_MIN);
	sprintf( TrackbarName, "V_MAX", V_MAX);
	//create trackbars and insert them into window
	//3 parameters are: the address of the variable that is changing when the trackbar is moved(eg.H_LOW),
	//the max value the trackbar can move (eg. H_HIGH), 
	//and the function that is called whenever the trackbar is moved(eg. on_trackbar)
	//                                  ---->    ---->     ---->      
	createTrackbar( "H_MIN", trackbarWindowName, &H_MIN_YELLOW, H_MAX, on_trackbar );
	createTrackbar( "H_MAX", trackbarWindowName, &H_MAX_YELLOW, H_MAX, on_trackbar );
	createTrackbar( "S_MIN", trackbarWindowName, &S_MIN_YELLOW, S_MAX, on_trackbar );
	createTrackbar( "S_MAX", trackbarWindowName, &S_MAX_YELLOW, S_MAX, on_trackbar );
	createTrackbar( "V_MIN", trackbarWindowName, &V_MIN_YELLOW, V_MAX, on_trackbar );
	createTrackbar( "V_MAX", trackbarWindowName, &V_MAX_YELLOW, V_MAX, on_trackbar );


}
void ImageProcessor::drawObject(vector<TennisBall> theTennisBalls,Mat &frame){

	for (int i = 0; i < theTennisBalls.size(); i++) {
		cv::circle(frame,cv::Point(theTennisBalls.at(i).getXPosition(),theTennisBalls.at(i).getYPosition()),20,cv::Scalar(0,0,255));
		cv::putText(frame,intToString(theTennisBalls.at(i).getXPosition())+ " , " + intToString(theTennisBalls.at(i).getYPosition()),cv::Point(theTennisBalls.at(i).getXPosition(),theTennisBalls.at(i).getYPosition()+20),1,1,Scalar(0,255,0));
	}
}

void ImageProcessor::morphOps(Mat &thresh){

	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle

	Mat erodeElement = getStructuringElement( MORPH_RECT,Size(3,3));
	//dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement( MORPH_RECT,Size(8,8));

	erode(thresh,thresh,erodeElement);
	erode(thresh,thresh,erodeElement);


	dilate(thresh,thresh,dilateElement);
	dilate(thresh,thresh,dilateElement);



}

// application reads from the specified serial port and reports the collected data
int ImageProcessor::checkPosition(bool haveBall, TennisBall tennisBall)
{
	int x = tennisBall.getXPosition();
	int y = tennisBall.getYPosition();

	double leftLimit = (601.4-y)/1.94;
	double rightLimit = (-657.4-y)/(-1.73);

	//printf(leftLimit + " ");
	//printf(rightLimit + " ");

	if (haveBall) {
		if (tennisBall.getXPosition() < 0)
		{
			state = ImageProcessor::TENNISBALL_NOTFOUND;
		}
		else if (x < leftLimit)
		{
			//SP->WriteData("A",dataLength);
			state = ImageProcessor::TENNISBALL_LEFT;

		}
		else if (x > rightLimit)
		{
			//SP->WriteData("D",dataLength);
			state = ImageProcessor::TENNISBALL_RIGHT;
		}
		else
		{
			state = ImageProcessor::TENNISBALL_FRONT;
			//SP->WriteData("W",dataLength);
		}
		//printf("We see a ball!\n");
	} else {
		//SP->WriteData("S",dataLength);
		state = ImageProcessor::TENNISBALL_NOTFOUND;
		//printf("We do not sees a ball!\n");
	}

	return 0;
}

void ImageProcessor::trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed){

	vector<TennisBall> tennisBalls;

	Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0) {
		int numObjects = hierarchy.size();
		//if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
		if(numObjects<MAX_NUM_OBJECTS){
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;

				//if the area is less than 20 px by 20px then it is probably just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we safe a reference area each
				//iteration and compare it to the area in the next iteration.
				if(area>MIN_OBJECT_AREA){

					TennisBall tennisBall;

					tennisBall.setXPosition(moment.m10/area);
					tennisBall.setYPosition(moment.m01/area);

					tennisBalls.push_back(tennisBall);

					objectFound = true;
				}else {
					objectFound = false;
				}
			}
			//let user know you found an object
			if(objectFound ==true){
				//draw object location on screen
				drawObject(tennisBalls,cameraFeed);		
			}

		}else putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
	}

	if (objectFound)
	{
		checkPosition(objectFound, tennisBalls.at(0));
	}
	else
	{
		state = ImageProcessor::TENNISBALL_NOTFOUND;
	}
}

void ImageProcessor::setCalibrationMode(bool calibrationMode)
{
	ImageProcessor::calibrationMode = calibrationMode;
}

void ImageProcessor::setEnable(bool enable)
{
	ImageProcessor::isEnabled = enable;
}

void ImageProcessor::process()
{
	
	bool useMorphOps = true;
	
	//Matrix to store each frame of the webcam feed
	Mat cameraFeed;
	Mat threshold;
	Mat HSV;

	/*
	if (cameraInUse == WEBCAM)
	{
		H_MIN_YELLOW = webcamFilter[0];
		H_MAX_YELLOW = webcamFilter[1];
		S_MIN_YELLOW = webcamFilter[2];
		S_MAX_YELLOW = webcamFilter[3];
		V_MIN_YELLOW = webcamFilter[4];
		V_MAX_YELLOW = webcamFilter[5];
	} else {
	*/
		H_MIN_YELLOW = laptopFilter[0];
		H_MAX_YELLOW = laptopFilter[1];
		S_MIN_YELLOW = laptopFilter[2];
		S_MAX_YELLOW = laptopFilter[3];
		V_MIN_YELLOW = laptopFilter[4];
		V_MAX_YELLOW = laptopFilter[5];
	//}

	if(ImageProcessor::calibrationMode==true){
		//create slider bars for HSV filtering
		createTrackbars();
	}
	//video capture object to acquire webcam feed
	VideoCapture capture;
	//open capture object at location zero (default location for webcam)
	capture.open(cameraInUse);
	//set height and width of capture frame
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
	//start an infinite loop where webcam feed is copied to cameraFeed matrix
	//all of our operations will be performed within this loop
	while(1)
	{
		//store image to matrix
		capture.read(cameraFeed);
		//convert frame from BGR to HSV colorspace
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		inRange(HSV,Scalar(H_MIN_YELLOW,S_MIN_YELLOW,V_MIN_YELLOW),Scalar(H_MAX_YELLOW,S_MAX_YELLOW,V_MAX_YELLOW),threshold);
		if(useMorphOps)
			morphOps(threshold);

		if(ImageProcessor::calibrationMode==true){
			//if in calibration mode, we track objects based on the HSV slider values.
			imshow(windowName2,threshold);
		}

		trackFilteredObject(threshold,HSV,cameraFeed);

		//show frames 
		//imshow(windowName2,threshold);

		imshow(windowName,cameraFeed);
		//imshow(windowName1,HSV);

		if (ImageProcessor::isEnabled)
		{
			motorController.sendCommandByVision(state);
		}

		//delay 30ms so that screen can refresh.
		//image will not appear without this waitKey() command
		waitKey(30);
	}



}