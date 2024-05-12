#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }

    bool operator<(const Point& other) const {
        return distanceToOrigin() < other.distanceToOrigin();
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

#endif 
