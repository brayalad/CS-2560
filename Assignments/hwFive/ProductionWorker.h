//
// Created by Bryan Ayala on 2019-03-03.
//

#ifndef HWFIVE_PRODUCTIONWORKER_H
#define HWFIVE_PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>

using namespace std;


class ProductionWorker : public Employee{

private:
    int shift;
    double hourlyPay;

public:
    ProductionWorker();
    ProductionWorker(string employeeName, int employeeNumber, string hireDate, int shift, double hourlyPay);

    void setShift(int shift);
    void setHourlyPay(double hourlyPay);

    int getShift();
    double getHourlyPay();
};


#endif //HWFIVE_PRODUCTIONWORKER_H
