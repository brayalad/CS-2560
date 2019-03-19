//
// Created by BRYAN on 3/12/2019.
//

#ifndef PATIENTFEES_SURGERY_H
#define PATIENTFEES_SURGERY_H

#include <string>
#include "PatientAccount.h"

class Surgery {

private:
    struct SurgeryType{
        std::string surgeryType;
        int surgeryCost;
    };
    SurgeryType *surgeries;

public:
    explicit Surgery(std::vector<std::string> availableSurgeries);
    ~Surgery();

    void updatePatientCharges(PatientAccount *patient, int newCharge);



};


#endif //PATIENTFEES_SURGERY_H
