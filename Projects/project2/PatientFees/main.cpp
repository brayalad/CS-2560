#include <utility>
#include <iostream>
#include <sstream>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

vector<string> availableSurgeries;
vector<string> availableMedications;
Surgery *surgery;
Pharmacy *pharmacy;


string getInput(){
    string userInput;
    getline(cin, userInput);
    return userInput;
}

void paySurgery(PatientAccount *patient){

    ostringstream surgeryOptions;
    surgeryOptions << "\nHere are the available surgeries:\n";
    for(unsigned int i=0; i < availableSurgeries.size(); ++i)
        surgeryOptions << (i+1) << ". " << availableSurgeries.at(i) << endl;

    int choice=-1;
    while((choice-1)<0 || (choice-1)>=availableSurgeries.size()) {
        bool valid;
        do {
            cout << surgeryOptions.str() << "\nEnter your choice: ";
            try {
                choice = stoi(getInput());
                valid=true;
            }
            catch(exception& e){
                cout << "\nInput must be an integer.\nPlease try again.\n" << endl;
                valid=false;
            }
        }while(!valid);

        if((choice-1) >= 0 && (choice-1) < availableSurgeries.size()){
            surgery->updatePatientCharges(patient, (choice-1));
            break;
        }
        else{
            cout << "\nInvalid Input\nPlease Try Again\n" << endl;
        }

    }

}

void buyMedication(PatientAccount *patient){

    ostringstream medicationOptions;
    medicationOptions << "\nHere are the available surgeries:\n";
    for(unsigned int i=0; i < availableMedications.size(); ++i)
        medicationOptions << (i+1) << ". " << availableMedications.at(i) << endl;

    int choice=-1;
    while((choice-1)<0 || (choice-1)>=availableMedications.size()) {
        bool valid;
        do {
            cout << medicationOptions.str() << "\nEnter your choice: ";
            try {
                choice = stoi(getInput());
                valid = true;
            }
            catch(exception& e){
                cout << "\nInput must be an integer.\nPlease try again.\n" << endl;
                valid=false;
            }
        }while(!valid);

        if((choice-1)>=0 && (choice-1)<availableMedications.size()){
            pharmacy->updatePatientCharges(patient, (choice-1));
            break;
        }
        else{
            cout << "\nInvalid Input\nPlease Try Again\n" << endl;
        }

    }

}

void newPatient(int argc=0,string argv=""){

    string name;
    if(argc==0) {
        cout << "Enter Patient Name: ";
        name = getInput();
    }
    else{
        name = move(argv);
    }
    bool valid;
    int daysSpent = 0;
    do {
        cout << "Enter Days Spent In Hospital: ";
        try {
            daysSpent = stoi(getInput());
            valid=true;
        }
        catch(exception& e){
            cout << "\nInput must be an integer.\nPlease try again.\n" << endl;
            valid=false;
        }

    }while(!valid);
    PatientAccount patient = PatientAccount(name, daysSpent);

    string userChoice;
    while(userChoice!="3"){
        cout << "\nChoose an option from bellow:\n"
             << "   1.  Pay for a Surgery\n"
                "   2.  Buy a medication from the pharmacy\n"
                "   3.  Check patient out of hospital\n"<< endl;
        cout << "Enter Choice: ";
        userChoice = getInput();

        if(userChoice=="1")
            paySurgery(&patient);
        else if(userChoice=="2")
            buyMedication(&patient);
        else if(userChoice=="3")
            break;
        else
            cout << "\nInvalid Input\nPlease Try Again\n" << endl;
    }

    cout << patient.getPatientAccount() << endl;

}

int main(int argc, char **argv) {

    availableSurgeries = {"Coronary Artery Bypass",
                          "Low Back Pain Surgery",
                          "Partial Colectomy",
                          "Hernia Repair",
                          "Open Heart Surgery"};
    availableMedications = {"Stimulants",
                            "Inhalants",
                            "Depressants",
                            "Pain Killers",
                            "Steroids"};

    surgery = new Surgery(availableSurgeries);
    pharmacy = new Pharmacy(availableMedications);



    cout << "Patient Fees Program\n" << endl;

    if(argc>1) {
        string cmdLineArg;
        for(int i=1;i<argc;++i)
            cmdLineArg.append(string(argv[i]).append(" "));
        newPatient(argc, cmdLineArg);
    }

    string userChoice;
    while(userChoice!="no"){
        cout << "Would you like make checkout a new patient? (yes/no)" << endl;
        userChoice=getInput();
        if(userChoice=="yes")
            newPatient();
        else if(userChoice!="no")
            break;
        else
            cout << "\nInvalid Input\nPlease Try Again\n" << endl;
    }

    cout << "Thank you for using this program!" << endl;

    delete(surgery);
    delete(pharmacy);

    return 0;
}