//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_EMPLOYEE_H
#define HWFIVE_EMPLOYEE_H

#include <string>

using namespace std;


class Employee {

private:
    string employeeName;
    int employeeNumber;
    string hireDate;

public:
    Employee();
    Employee(string employeeName, int employeeNumber, string hireDate);

    void setName(string employeeName);
    void setNumber(int employeeNumber);
    void setHireDate(string hireDate);

    string getName();
    int getNumber();
    string getHireDate();

};


#endif //HWFIVE_EMPLOYEE_H
