//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_POLICEOFFICER_H
#define PARKINGTICKETSIMULATOR_POLICEOFFICER_H

#include <string>
#include "ParkingTicket.h"
#include "ParkedCar.h"


using namespace std;

class ParkingTicket;

class PoliceOfficer {

private:
    string name;
    string badgeNumber;

public:
    PoliceOfficer(string = "", string = "");

    ParkingTicket makeParkingTicket(ParkedCar parkedCar);

    void setName(string name);
    void setBadgeNumber(string badgeNumber);

    string getName();
    string getBadgeNumber();
    string getPoliceOfficer();

};


#endif //PARKINGTICKETSIMULATOR_POLICEOFFICER_H
