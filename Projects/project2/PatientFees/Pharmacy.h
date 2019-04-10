/**
 * @file Pharmacy.h
 * @brief Pharmacy class
 *
 * This is the definition for the Pharmacy class.
 * This encasulates the information about what is
 * available in the pharmacy.
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */
#ifndef PATIENTFEES_PHARMACY_H
#define PATIENTFEES_PHARMACY_H

#include <string>
#include "PatientAccount.h"

/**
 * @brief Pharmacy Class Definition
 *
 * Class holds a list of available medications to buy.
 * It then updates the charges of the patient that buys
 * a medication.
 */
class Pharmacy {

private:
    /**
     * @brief Medication Structure
     *
     * Structure that holds the medication type and its price
     */
    struct Medication{
        std::string type; /**<type of medication*/
        int cost; /**<cost of medicationy*/
    };
    Medication *medications; /**< Medication List*/

public:
    /**
     * @brief Constructor
     *
     * Constructor for the pharmacy
     *
     * @param availableMedications list of medications available to buy
     */
    explicit Pharmacy(std::vector<std::string> availableMedications);

    /**
     * @brief Destructor
     *
     * Destructor for the pharmacy
     */
    ~Pharmacy();

    /**
     * @brief update patient charges
     *
     * Updates the total charges of the patient by adding the new charge
     *
     * @param patient current patient
     * @param newCharge cost of the new charge
     */
    void updatePatientCharges(PatientAccount *patient, int newCharge);

};


#endif //PATIENTFEES_PHARMACY_H
