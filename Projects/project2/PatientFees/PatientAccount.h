/**
 * @file PatientAccount.h
 * @brief The account layout for a patient.
 *
 * This contains the layout of a standard account for a patient.
 * The class encapsulates data about the patient so that it may
 * be used in other parts of the program.
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */
#ifndef PATIENTFEES_PATIENTACCOUNT_H
#define PATIENTFEES_PATIENTACCOUNT_H

#include <string>
#include <vector>

/**
 * @brief The class representing patient account
 *
 * The class that reresents the layout of a typical
 * patient account. Holds all its fields, as well as
 * defines member function including setter and getter functions.
 */
class PatientAccount {

private:
    std::string name; /**<Patient Name*/
    int daysSpent;/**<Days patient spent in hospital*/
    int dailyRate;/**<Daily Rate of the hospital*/
    int charges;/**<The Patients total charges*/
    std::vector<std::string> chargeList;/**<List of the patients charges*/

public:
    /**
     * Constructor takes in name and daysSpent and initalizes an instance
     * of the PatientClass
     * @param name inputted patient name
     * @param daysSpent inputted days spent in hospital
     */
    explicit PatientAccount(std::string name,int daysSpent);

    /**
     * @brief name setter
     *
     * Sets the name of the patient to the inputted string
     *
     * @param name inputted patient name
     */
    void setName(std::string name);

    /**
     * @brief daysSpent setter
     *
     * Sets the amount of days patient spent in hospital
     *
     * @param daysSpent amount of days spent in hospital
     */
    void setDaysSpent(int daysSpent);

    /**
     * @brief dailyRate setter
     *
     * Sets the daily rate for the hospital
     *
     * @param dailyRate daily rate of the hospital
     */
    void setDailyRate(int dailyRate);

    /**
     * @brief patientCharges setter
     *
     * Sets the initial charges of the patient
     *
     * @param daysSpent days spent in hospital by patient
     * @param dailyRate daily rate of the hospital
     */
    void setPatientCharges(int daysSpent, int dailyRate);

    /**
     * @brief updates patient charges
     *
     * Updates the total charges for the patient
     *
     * @param newCharges amount to be added to total
     */
    void updatePatientCharges(int newCharges);

    /**
     * @brief add to list of charges
     *
     * Adds the type of the new charge to list
     *
     * @param chargeItem type of charge
     * @param charge amount charged
     */
    void addToList(const std::string& chargeItem, int charge);

    /**
     * @brief name getter
     *
     * Returns name of the patient
     *
     * @return patient's name
     */
    const std::string& getName() const{ return name; }

    /**
     * @brief daysSpent getter
     *
     * Returns the amount of days spent in hospital
     * @return days spent in hospital
     */
    int getDaysSpent() const{ return daysSpent; }

    /**
     * @brief dailyRate getter
     *
     * Returns the daily rate of the hospital
     *
     * @return daily rate of the hospital
     */
    int getDailyRate() const{ return dailyRate; }

    /**
     * @brief charges getter
     *
     * Returns the patients total charges made
     *
     * @return total charges
     */
    int getPatientCharges() const{ return charges; }

    /**
     * @brief chargeList getter
     *
     * Returns a list of all charges made
     *
     * @return list of charges
     */
    const std::vector<std::string>& getChargeList() const{ return chargeList; }
};


#endif //PATIENTFEES_PATIENTACCOUNT_H
