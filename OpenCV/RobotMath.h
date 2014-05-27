#pragma once

#include <string>

using namespace std;

namespace RobotMath
{
    class Point;
    class Line;

    Line findLine(Point pt1, Point pt2);

    double findAbsoluteHeading(Point pt1, Point pt2);

    Point findClosestPointToLine(Point pt, Line tLn);

    double findShortestDistanceToLine(Point pt, Line tLn);

    double findDistanceBetweenTwoPoints(Point pt1, Point pt2);

}
