//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_MILTIME_H
#define HWFIVE_MILTIME_H

#include "Time.h"

class MilTime : public Time {

protected:
    int milHours;
    int milSeconds;

public:
    MilTime();
    MilTime(int milHours, int milSeconds);

    void setTime(int milHours, int milSeconds);

    int getHour();
    int getStandHr();

};


#endif //HWFIVE_MILTIME_H
