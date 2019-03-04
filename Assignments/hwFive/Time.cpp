//
// Created by Bryan Ayala on 2019-03-03.
//

#include "Time.h"

Time::Time() {
    hour = 0;
    min = 0;
    sec = 0;
}

Time::Time(int sec) {
    hour = 0;
    min = 0;
    this->sec = sec;
}

Time::Time(int hour, int min, int sec) {
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}

void Time::setHour(int hour) {
    this->hour = hour;
}

void Time::setMin(int min) {
    this->min = min;
}

void Time::setSec(int sec) {
    this->sec = sec;
}

int Time::getHour() {
    return hour;
}

int Time::getMin() {
    return min;
}

int Time::getSec() {
    return sec;
}
