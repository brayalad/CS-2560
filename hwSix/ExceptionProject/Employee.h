//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_EMPLOYEE_H
#define HWFIVE_EMPLOYEE_H

#include <string>


class Employee {

private:
    std::string employeeName;
    int employeeNumber;
    std::string hireDate;

public:
    Employee(std::string employeeName, int employeeNumber, std::string hireDate);

    void setName(std::string employeeName);
    void setNumber(int employeeNumber);
    void setHireDate(std::string hireDate);

    const std::string& getName() const;
    int getNumber() const;
    const std::string& getHireDate() const;

};


#endif //HWFIVE_EMPLOYEE_H
