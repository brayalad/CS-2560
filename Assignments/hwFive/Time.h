//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_TIME_H
#define HWFIVE_TIME_H


class Time {

protected:
    int hour;
    int min;
    int sec;

public:
    Time();
    Time(int sec);
    Time(int hour, int min, int sec);

    void setHour(int hour);
    void setMin(int min);
    void setSec(int sec);

    int getHour();
    int getMin();
    int getSec();

};


#endif //HWFIVE_TIME_H
