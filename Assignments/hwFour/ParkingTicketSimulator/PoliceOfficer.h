//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_POLICEOFFICER_H
#define PARKINGTICKETSIMULATOR_POLICEOFFICER_H

#include <string>
#include "ParkingTicket.h"
#include "ParkedCar.h"

class ParkingTicket;

class PoliceOfficer {

private:
    std::string name;
    std::string badgeNumber;

public:
    PoliceOfficer(string = "", string = "");

    ParkingTicket makeParkingTicket(ParkedCar parkedCar);

    void setName(string name);
    void setBadgeNumber(string badgeNumber);

    const std::string& getName() const{ return name; }
    const std::string& getBadgeNumber() const{ return badgeNumber; }
    std::string getPoliceOfficer();

};


#endif //PARKINGTICKETSIMULATOR_POLICEOFFICER_H
