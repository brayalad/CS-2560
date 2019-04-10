/**
 * @file Date.h
 * @brief Date class
 *
 * Class that represents a date
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */

#ifndef DATEMODIFICATION_DATE_H
#define DATEMODIFICATION_DATE_H

#include <iostream>

/**
 * @brief Date Class
 *
 * Class that represents a date. Holding its month,
 * day, and year as fields.
 *
 */
class Date {

private:
    int month; /**<Date's month*/
    int day; /**<Date's day*/
    int year; /**Date's year*/
    std::string monthStr; /**<String representation of date's year*/

public:
    /**
     * @brief Constructor
     *
     * Constructor for the date class
     */
    explicit Date(int=0,int=0,int=0);

    /**
     * @brief month setter
     *
     * sets the dates month
     *
     * @param month date's month
     */
    void setMonth(int month);

    /**
     * @brief day setter
     *
     * sets the date's day
     *
     * @param day date's day
     */
    void setDay(int day);

    /**
     * @brief year setter
     *
     * sets the date's year
     *
     * @param year  date's year
     */
    void setYear(int year);

    /**
     * @brief monthStr setter
     *
     * Sets the string representation of the month
     * @param month date's month
     */
    void setMonthStr(int month);

    /**
     * @brief month getter
     * @return date's month
     */
    int getMonth() const{ return month; }

    /**
     * @brief day getter
     * @return date's month
     */
    int getDay() const{ return day; }
    /**
     * @brief year getter
     * @return return's date's year
     */
    int getYear() const{ return year; }

    /**
     * @brief prints the date
     * @param option printing format
     */
    void print(int option);

    /**
     * @brief overloading postfix ++ operator
     * @return same date
     */
    Date &operator ++();
    /**
     * @brief overloading prefix ++ operator
     * @return inremented date
     */
    Date operator ++(int);
    /**
     * @brief overloading postfix -- operator
     * @return same date
     */
    Date &operator --();
    /**
     * @brief overloading prefix -- operator
     * @return decremented date
     */
    Date operator --(int);

    /**
     * @brief Overload - operator
     * @param date date to be subtracted
     * @return difference between dates
     */
    int operator -(const Date &date);

    /**
     * @brief overload << operator
     * @param out stream
     * @param date date to put out
     * @return stream
     */
    friend std::ostream &operator << (std::ostream &out, const Date &date);
    /**
     * @brief overload >> operator
     * @param in stream
     * @param date date to put in
     * @return stream
     */
    friend std::istream &operator >> (std::istream &in, Date &date);

};


#endif //DATEMODIFICATION_DATE_H
