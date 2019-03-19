//
// Created by BRYAN on 3/12/2019.
//
#include <cstdlib>
#include <ctime>
#include "Surgery.h"

using namespace std;


Surgery::Surgery(vector<string> availableSurgeries) {

    srand(time(0));

    unsigned long amountOfSurgeries = availableSurgeries.size();
    surgeries = new SurgeryType[amountOfSurgeries];

    for(unsigned int i=0; i < amountOfSurgeries; ++i) {
        surgeries[i].surgeryType = availableSurgeries.at(i);
        surgeries[i].surgeryCost = (rand() % 1000) + 500;
    }
}

Surgery::~Surgery() {
    delete []surgeries;
}

void Surgery::updatePatientCharges(PatientAccount *patient, int newCharge) {
    patient->updatePatientCharges(surgeries[newCharge].surgeryCost);
    patient->addToList(surgeries[newCharge].surgeryType,surgeries[newCharge].surgeryCost);
}

