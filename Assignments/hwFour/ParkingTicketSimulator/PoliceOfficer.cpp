//
// Created by BRYAN on 3/8/2019.
//

#include <string>
#include <sstream>
#include "PoliceOfficer.h"

using namespace std;

PoliceOfficer::PoliceOfficer(string name, string badgeNumber) {
    this->name = name;
    this->badgeNumber = badgeNumber;
}

ParkingTicket PoliceOfficer::makeParkingTicket(ParkedCar parkedCar) {
    return ParkingTicket(parkedCar, *this);
}

void PoliceOfficer::setName(string name){
    this->name = name;
}

void PoliceOfficer::setBadgeNumber(string badgeNumber){
    this->badgeNumber = badgeNumber;
}

string PoliceOfficer::getName(){
    return name;
}

string PoliceOfficer::getBadgeNumber(){
    return badgeNumber;
}
 string PoliceOfficer::getPoliceOfficer(){
    ostringstream officer;
    officer << "\nOfficer Information:\n   Name: " << name << "\n   Badge Number: " << badgeNumber << endl;
     return officer.str();
 }




