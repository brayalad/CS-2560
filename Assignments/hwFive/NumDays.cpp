//
// Created by Bryan Ayala on 2019-03-03.
//

#include "NumDays.h"
#include <cmath>

NumDays::NumDays() {
    days = 0;
    hours = 0;
}

NumDays::NumDays(double hours) {
    days = (hours / 8);
    this->hours = hours;
}

void NumDays::setDays(double days) {
    this->days = days;
}

void NumDays::setHours(double hours) {
    this->hours = hours;
}

double NumDays::getDays() {
    return days;
}

double NumDays::getHours() {
    return hours;
}

NumDays NumDays::operator+(const NumDays& inputtedNumDays) {

    NumDays newNumDays;

    newNumDays.hours = this->hours + inputtedNumDays.hours;
    newNumDays.days = this->days + inputtedNumDays.days;

    return newNumDays;
}

NumDays NumDays::operator-(const NumDays& inputtedNumDays) {

    NumDays newNumDays;

    newNumDays.hours = fabs(this->hours - inputtedNumDays.hours);
    newNumDays.days = fabs(this->days - inputtedNumDays.days);

    return newNumDays;

}
