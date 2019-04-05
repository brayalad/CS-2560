//
// ProductionWorker.h
//

#ifndef EXCEPTIONS_PRODUCTIONWORKER_H
#define EXCEPTIONS_PRODUCTIONWORKER_H


#include "Employee.h"
#include <string>


class ProductionWorker : public Employee{

private:
    int shift;
    double hourlyPay;

public:
    class InvalidShift {};
    class InvalidPayRate {};
    ProductionWorker(std::string employeeName, int employeeNumber, std::string hireDate, int shift, double hourlyPay);

    void setShift(int shift);
    void setHourlyPay(double hourlyPay);

    int getShift() const;
    double getHourlyPay() const;
};


#endif //EXCEPTIONS_PRODUCTIONWORKER_H
