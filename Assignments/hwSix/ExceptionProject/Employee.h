//
// Employee.h
//

#ifndef EXCEPTIONS_EMPLOYEE_H
#define EXCEPTIONS_EMPLOYEE_H


#include <string>


class Employee {

private:
    std::string employeeName;
    int employeeNumber;
    std::string hireDate;

public:
    class InvalidEmployeeNumber {};
    Employee(std::string employeeName, int employeeNumber, std::string hireDate);

    void setName(std::string employeeName);
    void setNumber(int employeeNumber);
    void setHireDate(std::string hireDate);

    const std::string& getName() const;
    int getNumber() const;
    const std::string& getHireDate() const;

};


#endif //EXCEPTIONS_EMPLOYEE_H
