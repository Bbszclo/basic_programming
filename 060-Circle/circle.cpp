#include "circle.hpp"
#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.141592653;
Circle::Circle(Point c,const double r):center(c),radius(r){} //constructor

void Circle::move(double dx, double dy){
    center.move(dx,dy);
}
//double area = circles[c1].intersectionArea(circles[c2]);

double Circle::intersectionArea(const Circle & otherCircle){
    double distance = center.distanceFrom(otherCircle.center);
    double r1 = radius;
    double r2 = otherCircle.radius;
    if(distance >= (r1 + r2)){ //they are not intersecting
        return 0.0;
    }
    else if (distance >=0 && distance <= abs(r1-r2)){ //Bigger circle include the smaller circle
        if (r1 >= r2){
            return pi*r2*r2; //intersection area is the area of the smaller circle
        }
        if (r1 < r2){
            return pi*r1*r1;
        }
    }
    else{ //two circles intersect a little bit(Normal case).
        double a = (r1 * r1 - r2* r2 + distance * distance) / (2 * distance);
        double b = (r2 * r2 - r1 * r1 + distance * distance) / (2 * distance);
        double h = sqrt(r1 * r1 - a * a);
        
        double area = r1 * r1 * acos(a / r1) + r2 * r2 * acos(b / r2) - distance * h;
        return area;
    }
    return 0.0;
}