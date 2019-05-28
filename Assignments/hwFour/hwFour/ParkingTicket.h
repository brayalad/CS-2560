//
// Created by BRYAN on 3/8/2019.
//

#ifndef PARKINGTICKETSIMULATOR_PARKINGTICKET_H
#define PARKINGTICKETSIMULATOR_PARKINGTICKET_H

#include <string>
#include "ParkedCar.h"
#include "PoliceOfficer.h"

class PoliceOfficer;

class ParkingTicket {

private:
    ParkedCar parkedCar;
    PoliceOfficer *policeOfficer;
    double fine;

public:
    ParkingTicket(ParkedCar car, PoliceOfficer &officer);

    void setParkedCar(ParkedCar parkedCar);
    void setPoliceOfficer(PoliceOfficer &policeOfficer);
    void setFine(int parkedMin);

    ParkedCar getParkedCar();
    PoliceOfficer getPoliceOfficer();
    double getFine();

    std::string getParkingTicket();

};


#endif //PARKINGTICKETSIMULATOR_PARKINGTICKET_H
