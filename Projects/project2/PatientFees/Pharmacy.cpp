/**
 * @file Pharmacy.cpp
 * @brief Pharmacy class implementation
 *
 * Implementation for the pharmacy class
 */
#include <cstdlib>
#include <ctime>
#include "Pharmacy.h"

using namespace std;

/**
 * @brief Constructor
 *
 * Constructor impelemtation takes a list of available medications.
 * It then generates a random cost for each medication type and
 * makes a list contatining that information.
 *
 * @param availableMedications list of medication types
 */
Pharmacy::Pharmacy(vector<string> availableMedications) {

    srand(time(0));

    unsigned long amountOfMeds = availableMedications.size();
    medications = new Medication[amountOfMeds];

    for(unsigned int i=0; i < amountOfMeds; ++i) {
        medications[i].type = availableMedications.at(i);
        medications[i].cost = (rand() % 300) + 50;
    }

}

/**
 * @brief Deconstructor
 *
 * Free's up memory allocated for medication list
 */
Pharmacy::~Pharmacy() {
    delete []medications;
}

/**
 * @brief patient charges updater
 *
 * updates the current patient's charges
 *
 * @param patient current patient
 * @param newCharge new charge cost
 */
void Pharmacy::updatePatientCharges(PatientAccount *patient, int newCharge) {
    patient->updatePatientCharges(medications[newCharge].cost);
    patient->addToList(medications[newCharge].type, medications[newCharge].cost);
}


