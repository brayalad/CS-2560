/**
 * @file Surgery.h
 * @brief Surgery class
 *
 * This is the definition for the Surgery class.
 * This encasulates the information about what is
 * available in the Surgery.
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */
#ifndef PATIENTFEES_SURGERY_H
#define PATIENTFEES_SURGERY_H

#include <string>
#include "PatientAccount.h"

/**
 * @brief Surgery Class Definition
 *
 * Class holds a list of available surgeries to buy.
 * It then updates the charges of the patient that buys
 * a surgery.
 */
class Surgery {

private:
    /**
     * @brief Surgery Structure
     *
     * Structure that holds the surgery type and its price
     */
    struct SurgeryType{
        std::string surgeryType; /**<type of surgery*/
        int surgeryCost; /**<cost of surgery*/
    };
    SurgeryType *surgeries; /**<Surgery List*/

public:

    /**
     * @brief Constructor
     *
     * Constructor for the surgery
     *
     * @param availableSurgeries list of surgeries available to buy
     */
    explicit Surgery(std::vector<std::string> availableSurgeries);

    /**
     * @brief Destructor
     *
     * Destructor for the surgery
     */
    ~Surgery();

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


#endif //PATIENTFEES_SURGERY_H
