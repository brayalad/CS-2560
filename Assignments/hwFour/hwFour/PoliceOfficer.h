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
    PoliceOfficer(std::string = "", std::string = "");

    ParkingTicket makeParkingTicket(ParkedCar parkedCar);

    void setName(std::string name);
    void setBadgeNumber(std::string badgeNumber);

    std::string getName();
    std::string getBadgeNumber();
    std::string getPoliceOfficer();

};


#endif //PARKINGTICKETSIMULATOR_POLICEOFFICER_H
