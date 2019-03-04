//
// Created by Bryan Ayala on 2019-03-03.
//

#include "MilTime.h"

MilTime::MilTime() : Time() {
    milHours = 0;
    milSeconds = 0;
}

MilTime::MilTime(int milHours, int milSeconds) : Time(milSeconds){
    this->milHours = milHours;
    this->milSeconds = milSeconds;

    int stdHrs = milHours / 100;
    int stdMin = milHours % 100;

    if(stdHrs > 12)
        stdHrs -= 12;

    if(stdHrs == 0)
        stdHrs = 12;

    Time::setHour(stdHrs);
    Time::setMin(stdMin);
}

void MilTime::setTime(int milHours, int milSeconds) {
    this->milHours = milHours;
    this->milSeconds = milSeconds;

    int stdHrs = milHours / 100;
    int stdMin = milHours % 100;

    if(stdHrs < 12)
        stdHrs -= 12;

    Time::setHour(stdHrs);
    Time::setMin(stdMin);
    Time::setSec(milSeconds);
}

int MilTime::getHour() {
    return milHours;
}

int MilTime::getStandHr() {
    return Time::getHour();
}
