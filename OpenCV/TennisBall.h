#pragma once

#include <string>

using namespace std;

class TennisBall
{
public:
	TennisBall(void);
	~TennisBall(void);

	int getXPosition();
	void setXPosition(int x);

	int getYPosition();
	void setYPosition(int y);

private:
	int xPos, yPos;
	
};

