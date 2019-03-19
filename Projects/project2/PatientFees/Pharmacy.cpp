//
// Created by BRYAN on 3/12/2019.
//

#include <cstdlib>
#include <ctime>
#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy(vector<string> availableMedications) {

    srand(time(0));

    unsigned long amountOfMeds = availableMedications.size();
    medications = new Medication[amountOfMeds];

    for(unsigned int i=0; i < amountOfMeds; ++i) {
        medications[i].type = availableMedications.at(i);
        medications[i].cost = (rand() % 300) + 50;
    }

}

Pharmacy::~Pharmacy() {
    delete []medications;
}

void Pharmacy::updatePatientCharges(PatientAccount *patient, int newCharge) {
    patient->updatePatientCharges(medications[newCharge].cost);
    patient->addToList(medications[newCharge].type, medications[newCharge].cost);
}


