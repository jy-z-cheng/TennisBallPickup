#pragma once

#include "RobotMath.h"

class RobotMath::Point {
	public:
		Point(void);
		~Point(void);

		int getXPosition();
		void setXPosition(int x);

		int getYPosition();
		void setYPosition(int y);

	private:
		int xPos, yPos;
};

