#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    //dtor
}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}


int Point::setX(int x) {
    this->x = x;
}

int Point::setY(int y) {
    this->y = y;
}



