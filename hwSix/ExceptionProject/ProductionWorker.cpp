//
// Created by Bryan Ayala on 2019-03-03.
//

#include "ProductionWorker.h"

using namespace std;


ProductionWorker::ProductionWorker(string employeeName, int employeeNumber, string hireDate, int shift, double hourlyPay)
        : Employee(employeeName, employeeNumber, hireDate){
    setShift(shift);
    setHourlyPay(hourlyPay);
}

void ProductionWorker::setShift(int shift) {
    if(shift < 1 || shift > 2) {
        throw "InvalidShift";
    }
    else{
        this->shift = shift;
    }
}

void ProductionWorker::setHourlyPay(double hourlyPay) {
    if(hourlyPay < 0){
        throw "InvalidPayRate";
    }
    else {
        this->hourlyPay = hourlyPay;
    }
}

int ProductionWorker::getShift() const{
    return shift;
}

double ProductionWorker::getHourlyPay() const{
    return hourlyPay;
}

