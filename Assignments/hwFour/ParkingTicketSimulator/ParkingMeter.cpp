//
// Created by BRYAN on 3/8/2019.
//

#include "ParkingMeter.h"


ParkingMeter::ParkingMeter(int parkedTime) {
    this->parkedTime = parkedTime;
}

void ParkingMeter::setParkedTime(int parkedTime) {
    this->parkedTime = parkedTime;
}

void ParkingMeter::addTime(int addedTime) {
    parkedTime += addedTime;
}

int ParkingMeter::getParkedTime() const{
    return parkedTime;
}
