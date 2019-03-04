//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_NUMDAYS_H
#define HWFIVE_NUMDAYS_H

#include <cmath>

class NumDays {

private:
    double days;
    double hours;

public:
    NumDays();
    NumDays(double hours);

    void setDays(double days);
    void setHours(double hours);

    double getDays();
    double getHours();

    NumDays operator+(const NumDays& inputtedNumDays);
    NumDays operator-(const NumDays& inputtedNumDays);

};


#endif //HWFIVE_NUMDAYS_H
