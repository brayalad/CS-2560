//
// Created by BRYAN on 3/12/2019.
//

#ifndef PATIENTFEES_PHARMACY_H
#define PATIENTFEES_PHARMACY_H

#include <string>
#include "PatientAccount.h"

class Pharmacy {

private:
   struct Medication{
       std::string type;
       int cost;
   };
   Medication *medications;

public:
    explicit Pharmacy(std::vector<std::string> availableMedications);
    ~Pharmacy();

    void updatePatientCharges(PatientAccount *patient, int newCharge);

};


#endif //PATIENTFEES_PHARMACY_H
