#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getX() const {
   return this->x;
}

int Point::getY() const {
    return this->y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt( pow(point.getX() - this->getX(),2) + pow(point.getY() - this->getY(),2));
}


