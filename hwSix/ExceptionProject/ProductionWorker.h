//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_PRODUCTIONWORKER_H
#define HWFIVE_PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>


class ProductionWorker : public Employee{

private:
    int shift;
    double hourlyPay;

public:
    ProductionWorker(std::string employeeName, int employeeNumber, std::string hireDate, int shift, double hourlyPay);

    void setShift(int shift);
    void setHourlyPay(double hourlyPay);

    int getShift() const;
    double getHourlyPay() const;
};


#endif //HWFIVE_PRODUCTIONWORKER_H
