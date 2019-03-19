//
// Created by BRYAN on 3/12/2019.
//

#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "PatientAccount.h"

using namespace std;

PatientAccount::PatientAccount(string name, int daysSpent) {
    srand(time(0));
    int dailyRate = (rand()%100)+25;

    setName(name);
    setDaysSpent(daysSpent);
    setDailyRate(dailyRate);
    setPatientCharges(daysSpent, dailyRate);
}

void PatientAccount::setName(string name) {
    this->name = name;
}

void PatientAccount::setDaysSpent(int daysSpent) {
    this->daysSpent = daysSpent;
}

void PatientAccount::setDailyRate(int dailyRate) {
    this->dailyRate = dailyRate;
}

void PatientAccount::setPatientCharges(int daysSpent, int dailyRate) {
    charges = daysSpent * dailyRate;
}

void PatientAccount::updatePatientCharges(int newCharges) {
    charges += newCharges;
}

void PatientAccount::addToList(string chargeItem, int charge) {

    chargeList.push_back(chargeItem + ": $" + to_string(charge) + ".00");
}

string PatientAccount::getName() {
    return name;
}

int PatientAccount::getDaysSpent() {
    return daysSpent;
}

int PatientAccount::getDailyRate() {
    return dailyRate;
}

int PatientAccount::getPatientCharges() {
    return charges;
}

string PatientAccount::getPatientAccount() {
    ostringstream patientAccount;
    patientAccount << "\nAccount Information for: " << name
                   << "\nDays spend in hospital: " << daysSpent
                   <<"\nHospital daily rate: $" << dailyRate
                   << ".00\n\nList of Charges:" << endl;
    for (const auto &i : chargeList)
        patientAccount << "    " << i << endl;
    patientAccount << "    Hospital stay: $" << (dailyRate*daysSpent) << ".00\n"
                   << "\nTotal Charges: $" << charges << ".00" << endl;

    return patientAccount.str();
}

vector<string> PatientAccount::getchargeList() {
    return chargeList;
}
