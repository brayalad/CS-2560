/**
 * @file Date.cpp
 * @brief Date class implementation
 *
 * Class that represents a date
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */

#include <cstdlib>
#include <exception>
#include <climits>
#include "Date.h"

using namespace std;

extern const int current_year;

/**
   * @brief Constructor
   *
   * Constructor for the date class
   */
Date::Date(int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
    setMonthStr(month);
}

/**
 * @brief month setter
 *
 * sets the dates month
 *
 * @param month date's month
 */
void Date::setMonth(int month) {
    this->month = month;
}

/**
 * @brief day setter
 *
 * sets the date's day
 *
 * @param day date's day
 */
void Date::setDay(int day) {
    this->day = day;
}

/**
 * @brief year setter
 *
 * sets the date's year
 *
 * @param year  date's year
 */
void Date::setYear(int year) {
    this->year = year;
}

/**
 * @brief monthStr setter
 *
 * Sets the string representation of the month
 * @param month date's month
 */
void Date::setMonthStr(int month){

    if(month==1)
        monthStr="January";
    else if(month==2)
        monthStr="February";
    else if(month==3)
        monthStr="March";
    else if(month==4)
        monthStr="April";
    else if(month==5)
        monthStr="May";
    else if(month==6)
        monthStr="June";
    else if(month==7)
        monthStr="July";
    else if(month==8)
        monthStr="August";
    else if(month==9)
        monthStr="September";
    else if(month==10)
        monthStr="October";
    else if(month==11)
        monthStr="November";
    else if(month==12)
        monthStr="December";
    else
        monthStr="NULL";
}

/**
 * @brief prints the date
 * @param option printing format
 */
void Date::print(int option) {

    if(option==1)
        cout << month << "/" << day << "/" << year << endl;
    else if(option==2)
        cout <<  monthStr << " " << day << ", " << year << endl;
    else if(option==3)
        cout << day << " " <<  monthStr << " " << year << endl;

}

/**
 * @brief overloading postfix ++ operator
 * @return same date
 */
Date& Date::operator ++() {

    ++day;

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10) {
        if (day > 31) {
            ++month;
            day -= 31;
        }
    }
    else if(month==4 || month==6 || month==9 || month==11) {
        if (day > 30) {
            ++month;
            day -= 30;
        }
    }
    else if(month==2 && day>28){
        ++month;
        day-=28;
    }
    else if(month==12 && day>31){
        ++year;
        day-=31;
        month-=11;
    }


    return *this;
}

/**
 * @brief overloading prefix ++ operator
 * @return inremented date
 */
Date Date::operator ++(int) {
    Date D = *this;
    ++(*this);
    return D;
}

/**
 * @brief overloading postfix -- operator
 * @return same date
 */
Date& Date::operator --() {

    --day;

    if(day<=0){
        if(month==2 || month==4 || month==6 || month==8 || month==9 || month==11){
            --month;
            day+=31;
        }
        else if(month==5 || month==7 || month==10 || month==12){
            --month;
            day+=30;
        }
        else if(month==3){
            --month;
            day+=28;
        }
        else if(month==1){
            year--;
            day += 31;
            month += 11;
        }
    }

    return *this;
}

/**
 * @brief overloading prefix -- operator
 * @return decremented date
 */
Date Date::operator --(int) {
    Date D = *this;
    --(*this);
    return D;
}

/**
 * @brief Overload - operator
 * @param date date to be subtracted
 * @return difference between dates
 */
int Date::operator-(const Date &date) {

    int difference = 0;

    Date low;
    Date high;
    if(this->year==date.year) {
        if (this->month == date.month) {
            if (this->day == date.day) {
                difference = -1;
            } else if (this->day > date.day) {
                high = Date(month, day, year);
                low = Date(date.month, date.day, date.year);
            } else if (date.day > this->day) {
                high = Date(date.month, date.day, date.year);
                low = Date(month, day, year);
            }
        }
        else if(this->month > date.month){
            high = Date(month, day, year);
            low = Date(date.month, date.day, date.year);
        }
        else if(date.month > this->month){
            high = Date(date.month, date.day, date.year);
            low = Date(month, day, year);
        }
    }
    else if(this->year > date.year){
        high = Date(month, day, year);
        low = Date(date.month, date.day, date.year);
    }
    else if(date.year > this->year){
        high = Date(date.month, date.day, date.year);
        low = Date(month, day, year);
    }

    if(difference != -1) {
        while (true) {
            difference++;
            low++;

            if (low.getDay() == high.getDay() && low.getMonth() == high.getMonth() && low.getYear() == high.getYear())
                break;
        }
    }
    else
        difference = 0;
    return difference + 1;
}

/**
 * @brief overload << operator
 * @param out stream
 * @param date date to put out
 * @return stream
 */
ostream &operator<<(ostream &out, const Date &date) {
    out << date.monthStr << " " << date.day << ", " << date.year << endl;
    return out;
}

/**
 * @brief overload >> operator
 * @param in stream
 * @param date date to put in
 * @return stream
 */
istream &operator>>(istream &in, Date &date) {


    bool valid = false;
    while(!valid) {

        bool isInt;
        do{
            cout << "Enter Month: ";
            in >> date.month;
            isInt = in.fail();
            if(isInt) {
                cout << "\nInput must be an integer\n" << endl;
                in.clear();
                in.ignore(INT_MAX, '\n');
            }
        }while(isInt);
        do{
            cout << "Enter Day: ";
            in >> date.day;
            isInt = in.fail();
            if(isInt) {
                cout << "\nInput must be an integer\n" << endl;
                in.clear();
                in.ignore(INT_MAX, '\n');
            }
        }while(isInt);
        do{
            cout << "Enter Year: ";
            in >> date.year;
            isInt = in.fail();
            if(isInt) {
                cout << "\nInput must be an integer\n" << endl;
                in.clear();
                in.ignore(INT_MAX, '\n');
            }
        }while(isInt);


        if (date.year <= current_year) {
            if (date.month >= 1 && date.month <= 12) {
                if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 ||
                    date.month == 8 || date.month == 10 || date.month == 12) {
                    if (date.day <= 31) {
                        valid = true;
                    }
                } else if (date.month == 4 || date.month == 6 || date.month == 9 ||
                           date.month == 11) {
                    if (date.day <= 30) {
                        valid = true;
                    }
                } else if (date.month == 2 && date.day <= 28) {
                    valid = true;
                }
            }
        }
        if (!valid) {
            cout << "\nDate Inputted is invalid.\nPlease Try Again.\n" << endl;
        }

    }

    if(date.month==1)
        date.monthStr="January";
    else if(date.month==2)
        date. monthStr="February";
    else if(date.month==3)
        date.monthStr="March";
    else if(date.month==4)
        date.monthStr="April";
    else if(date.month==5)
        date.monthStr="May";
    else if(date.month==6)
        date.monthStr="June";
    else if(date.month==7)
        date.monthStr="July";
    else if(date.month==8)
        date.monthStr="August";
    else if(date.month==9)
        date.monthStr="September";
    else if(date.month==10)
        date.monthStr="October";
    else if(date.month==11)
        date.monthStr="November";
    else if(date.month==12)
        date.monthStr="December";
    else
        date.monthStr="NULL";

    return in;
}






