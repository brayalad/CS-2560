#include "Circle.h"

const double Circle::pi = 3.14159;

Circle::Circle() {

    radius = 0;

}

Circle::Circle(double radius) {
    this->radius = radius;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getArea() {
    return (pi * radius * radius);
}

double Circle::getDiameter() {
    return (radius * 2);
}

double Circle::getCircumference() {
    return (2 * pi * radius);
}