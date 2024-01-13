#include "point.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Point::Point() : x(0), y(0) {} //constructor, initial value is 0

void Point::move(double dx, double dy){
    x += dx;
    y += dy;
}
double Point::distanceFrom(const Point & p){ //calculating the distance from x to y
    double distance = 0;
    distance = sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    return distance;
}