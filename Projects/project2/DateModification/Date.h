//
// Created by BRYAN on 3/13/2019.
//

#ifndef DATEMODIFICATION_DATE_H
#define DATEMODIFICATION_DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {

private:
    int month;
    int day;
    int year;
    string monthStr;

public:
    Date(int=0,int=0,int=0);

    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    void setMonthStr(int month);

    int getMonth();
    int getDay();
    int getYear();


    void print(int option);

    Date &operator ++();
    Date operator ++(int);
    Date &operator --();
    Date operator --(int);
    int operator -(const Date &date);

    friend ostream &operator << (ostream &out, const Date &date);
    friend istream &operator >> (istream &in, Date &date);

};


#endif //DATEMODIFICATION_DATE_H
