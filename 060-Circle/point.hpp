//The point.hpp contains the definition of the class.
class Point{
private:
    double x;
    double y;
public:
    Point(); //constructor
    void move(double dx, double dy);
    double distanceFrom(const Point & p);
};

