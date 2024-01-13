//Your circle class should have two private fields:
//A Point for the center (remember: Point is a type, so we can have a field whose type is "Point")
//A const double for the radius
#include "point.hpp"

class Circle{
private:
    Point center;
    const double radius;
public:
    Circle(Point c,const double r); //constructor
    void move(double dx, double dy);
    double intersectionArea(const Circle & otherCircle);
};

