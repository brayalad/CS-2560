//
// Created by BRYAN on 3/8/2019.
//

#include <sstream>
#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(std::string name, std::string badgeNumber) {
    this->name = name;
    this->badgeNumber = badgeNumber;
}

ParkingTicket PoliceOfficer::makeParkingTicket(ParkedCar parkedCar) {
    return ParkingTicket(parkedCar, *this);
}

void PoliceOfficer::setName(std::string name){
    this->name = name;
}

void PoliceOfficer::setBadgeNumber(std::string badgeNumber){
    this->badgeNumber = badgeNumber;
}

 std::string PoliceOfficer::getPoliceOfficer(){
    std::ostringstream officer;
    officer << "\nOfficer Information:\n   Name: " << name << "\n   Badge Number: " << badgeNumber << std::endl;
     return officer.str();
 }




