//
// Employee.cpp
//

#include "Employee.h"

Employee::Employee(std::string employeeName, int employeeNumber, std::string hireDate) {
    setName(employeeName);
    setNumber(employeeNumber);
    setHireDate(hireDate);
}

void Employee::setName(std::string employeeName) {
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

void Employee::setHireDate(std::string hireDate) {
    this->hireDate = hireDate;
}

const std::string& Employee::getName() const{
    return employeeName;
}

int Employee::getNumber() const{
    return employeeNumber;
}

const std::string& Employee::getHireDate() const{
    return hireDate;
}
