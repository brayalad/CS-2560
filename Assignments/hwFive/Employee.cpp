//
// Created by Bryan Ayala on 2019-03-03.
//

#include "Employee.h"
#include <string>

using namespace std;

Employee::Employee() {
    employeeName = "";
    employeeNumber = 0;
    hireDate = "";
}

Employee::Employee(string employeeName, int employeeNumber, string hireDate) {
    this->employeeName = employeeName;
    this->employeeNumber = employeeNumber;
    this->hireDate = hireDate;
}

void Employee::setName(string employeeName) {
    this->employeeName = employeeName;
}

void Employee::setNumber(int employeeNumber) {
    this->employeeNumber = employeeNumber;
}

void Employee::setHireDate(string hireDate) {
    this->hireDate = hireDate;
}

string Employee::getName() {
    return employeeName;
}

int Employee::getNumber() {
    return employeeNumber;
}

string Employee::getHireDate() {
    return hireDate;
}
