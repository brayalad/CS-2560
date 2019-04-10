/**
 * @file PatientAccount.cpp
 * @brief Account implementation
 *
 * This is the implementation of the class PatientAccount.
 * This file contains all the logic that the class is able
 * to operate.
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */

#include <utility>
#include <cstdlib>
#include <ctime>
#include "PatientAccount.h"

using namespace std;

/**
 * @brief Constructor
 *
 * Constructor takes in its parameters and sets the values. It does
 * this by first computing the daily rate of the hospital at random.
 * It then calls on the class's setter functions to set each field,
 * passing the appropriate value as a parameter.
 *
 * @param inputtedName name of patient
 * @param inputtedDaysSpent days spent in hospital
 */
PatientAccount::PatientAccount(string inputtedName, int inputtedDaysSpent) {
    srand(time(0));
    int calculatedDailyRate = (rand()%100)+25;

    setName(std::move(inputtedName));
    setDaysSpent(inputtedDaysSpent);
    setDailyRate(calculatedDailyRate);
    setPatientCharges(inputtedDaysSpent, calculatedDailyRate);
}

/**
 * @brief name setter
 *
 * Sets the name of the patient to the inputted string
 *
 * @param inputtedName inputted patient name
 */
void PatientAccount::setName(string inputtedName) {
    name = std::move(inputtedName);
}

/**
 * @brief daysSpent setter
 *
 * Sets the amount of days patient spent in hospital
 *
 * @param inputtedDaysSpent amount of days spent in hospital
 */
void PatientAccount::setDaysSpent(int inputtedDaysSpent) {
    daysSpent = inputtedDaysSpent;
}

/**
 * @brief dailyRate setter
 *
 * Sets the daily rate for the hospital
 *
 * @param inputtedDailyRate daily rate of the hospital
 */
void PatientAccount::setDailyRate(int inputtedDailyRate) {
    dailyRate = inputtedDailyRate;
}

/**
 * @brief patientCharges setter
 *
 * Sets the initial charges of the patient
 *
 * @param inputtedDaysSpent days spent in hospital by patient
 * @param inputtedDailyRate daily rate of the hospital
 */
void PatientAccount::setPatientCharges(int inputtedDaysSpent, int inputtedDailyRate) {
    charges = inputtedDaysSpent * inputtedDailyRate;
}

/**
 * @brief updates patient charges
 *
 * Updates the total charges for the patient
 *
 * @param newCharges amount to be added to total
 */
void PatientAccount::updatePatientCharges(int newCharges) {
    charges += newCharges;
}

/**
 * @brief add to list of charges
 *
 * Adds the type of the new charge to list
 *
 * @param chargeItem type of charge
 * @param charge amount charged
 */
void PatientAccount::addToList(const string& chargeItem, int charge) {

    chargeList.push_back(chargeItem + ": $" + to_string(charge) + ".00");
}

