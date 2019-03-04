#ifndef HWFIVE_CIRCLE_H
#define HWFIVE_CIRCLE_H

class Circle{

private:
    static const double pi;
    double radius;

public:
    Circle();
    Circle(double radius);

    void setRadius(double radius);

    double getRadius();
    double getArea();
    double getDiameter();
    double getCircumference();

};

#endif