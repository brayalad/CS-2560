/**
 * @file Surgery.cpp
 * @brief Surgery class implementation
 *
 * Implementation for the pharmacy class
 */

#include <cstdlib>
#include <ctime>
#include "Surgery.h"

using namespace std;

/**
 * @brief Constructor
 *
 * Constructor impelemtation takes a list of available surgeries.
 * It then generates a random cost for each surgery type and
 * makes a list contatining that information.
 *
 * @param availableSurgeries list of surgery types
 */
Surgery::Surgery(vector<string> availableSurgeries) {

    srand(time(0));

    unsigned long amountOfSurgeries = availableSurgeries.size();
    surgeries = new SurgeryType[amountOfSurgeries];

    for(unsigned int i=0; i < amountOfSurgeries; ++i) {
        surgeries[i].surgeryType = availableSurgeries.at(i);
        surgeries[i].surgeryCost = (rand() % 1000) + 500;
    }
}

/**
 * @brief Deconstructor
 *
 * Free's up memory allocated for surgery list
 */
Surgery::~Surgery() {
    delete []surgeries;
}

/**
 * @brief patient charges updater
 *
 * updates the current patient's charges
 *
 * @param patient current patient
 * @param newCharge new charge cost
 */
void Surgery::updatePatientCharges(PatientAccount *patient, int newCharge) {
    patient->updatePatientCharges(surgeries[newCharge].surgeryCost);
    patient->addToList(surgeries[newCharge].surgeryType,surgeries[newCharge].surgeryCost);
}

