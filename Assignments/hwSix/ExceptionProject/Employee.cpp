//
// Employee.cpp
//

#include "Employee.h"

using namespace std;

Employee::Employee(string employeeName, int employeeNumber, string hireDate) {
    setName(employeeName);
    setNumber(employeeNumber);
    setHireDate(hireDate);
}

void Employee::setName(string employeeName) {
    this->employeeName = employeeName;
}

void Employee::setNumber(int employeeNumber) {
    if(employeeNumber > 0 && employeeNumber < 9999) {
        this->employeeNumber = employeeNumber;
    }
    else{
        throw InvalidEmployeeNumber();
    }
}

void Employee::setHireDate(string hireDate) {
    this->hireDate = hireDate;
}

const string& Employee::getName() const{
    return employeeName;
}

int Employee::getNumber() const{
    return employeeNumber;
}

const string& Employee::getHireDate() const{
    return hireDate;
}
