//
// Created by Bryan Ayala on 2019-03-03.
//

#include "ProductionWorker.h"

ProductionWorker::ProductionWorker() : Employee() {
    shift = 0;
    hourlyPay = 0;
}

ProductionWorker::ProductionWorker(string employeeName, int employeeNumber, string hireDate, int shift, double hourlyPay)
    : Employee(employeeName, employeeNumber, hireDate){
    this->shift = shift;
    this->hourlyPay = hourlyPay;
}

void ProductionWorker::setShift(int shift) {
    this->shift = shift;
}

void ProductionWorker::setHourlyPay(double hourlyPay) {
    this->hourlyPay = hourlyPay;
}

int ProductionWorker::getShift() {
    return shift;
}

double ProductionWorker::getHourlyPay() {
    return hourlyPay;
}

