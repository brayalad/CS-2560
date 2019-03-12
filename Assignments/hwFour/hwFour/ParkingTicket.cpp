//
// Created by BRYAN on 3/8/2019.
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include "ParkingTicket.h"

using namespace std;


ParkingTicket::ParkingTicket(ParkedCar car, PoliceOfficer &officer) {
    parkedCar = car;
    policeOfficer = &officer;
    setFine(car.getMinParked());
}

void ParkingTicket::setParkedCar(ParkedCar parkedCar) {
    this->parkedCar = parkedCar;
}

void ParkingTicket::setPoliceOfficer(PoliceOfficer &policeOfficer) {
    this->policeOfficer = &policeOfficer;
}

void ParkingTicket::setFine(int parkedHours) {

    double timeParked = ceil((double)parkedHours/60);
    if(timeParked > 1){
        fine = 25 + ((timeParked-1) * 10);

    }
    else
        fine = 25;

}

ParkedCar ParkingTicket::getParkedCar() {
    return parkedCar;
}

PoliceOfficer ParkingTicket::getPoliceOfficer() {
    return *policeOfficer;
}

double ParkingTicket::getFine() {
    return fine;
}

string ParkingTicket::getParkingTicket() {

    ostringstream fineString;
    fineString << fixed << setprecision(2) << fine << endl;

    ostringstream ticket;
    ticket << "\n-----------------------------------------------------------------------------------------"
           << "\nPARKING TICKET:\n" << policeOfficer->getPoliceOfficer()
           << "\n" << parkedCar.getParkedCar() << "\nTime Parked: "
           << parkedCar.getMinParked() << " minutes\nFine: $" << fixed << setprecision(2) << fine
           << "\n-----------------------------------------------------------------------------------------" << endl;

    return ticket.str();
}





