//
// Created by BRYAN on 3/12/2019.
//

#ifndef PATIENTFEES_PATIENTACCOUNT_H
#define PATIENTFEES_PATIENTACCOUNT_H

#include <string>
#include <vector>


class PatientAccount {

private:
    std::string name;
    int daysSpent;
    int dailyRate;
    int charges;
    std::vector<std::string> chargeList;

public:
    explicit PatientAccount(std::string="",int=0);

    void setName(std::string name);
    void setDaysSpent(int daysSpent);
    void setDailyRate(int dailyRate);
    void setPatientCharges(int daysSpent, int dailyRate);
    void updatePatientCharges(int newCharges);
    void addToList(std::string chargeItem, int charge);

    std::string getName();
    int getDaysSpent();
    int getDailyRate();
    int getPatientCharges();
    std::string getPatientAccount();
    std::vector<std::string> getchargeList();
};


#endif //PATIENTFEES_PATIENTACCOUNT_H
