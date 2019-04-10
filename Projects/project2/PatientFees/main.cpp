/**
 * @file main.cpp
 * @brief Patient Fees Project
 *
 * This program allows the user to checkout a patient from the
 * hospital. First the user inpus information about the patient,
 * including the amoung of days spent. While checking out, the user
 * can also buy medications and/or surgeries. Every time something is
 * bought, the cost of the item is added to the patients total charges.
 * When ready to checkout, the program will display to the user all the
 * charges accumulated and the total cost of the hospital stay.
 *
 * @author Bryan Ayala
 * @date April 2019
 * @bug No known bugs
 */

#include <utility>
#include <iostream>
#include <sstream>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

vector<string> availableSurgeries; /**< list of available surgeries*/
vector<string> availableMedications; /**< list of available medications*/
Surgery *surgery; /**< Surgery class global pointer*/
Pharmacy *pharmacy; /**< Pharmacy class global pointer*/

/**
 * @brief Read user input
 *
 * returns a string representing the input of the user
 *
 * @return user input
 */
string getInput(){
    string userInput;
    getline(cin, userInput);
    return userInput;
}

/**
 * @brief Buy a surgery
 *
 * This method allows the user to choose which surgery they would like to buy.
 * The cost of the surgery chosen will be added to patient's total charges.
 *
 * @param patient current patient
 */
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

/**
 * @brief Buy a Medication
 *
 * This method allows the user to choose which medication they would like to buy.
 * The cost of the medication chosen will be added to patient's total charges.
 *
 * @param patient current patient
 */
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

/**
 * @brief Create new Patient
 *
 * User is asked to input data pertaining to the new patient.
 * Once data is inputed, a new instance of the PatientAccount class
 * is made.
 *
 * @param argc command line argument amount
 * @param argv command line argument value
 */
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

    ostringstream patientAccountInfo;
    patientAccountInfo << "\nAccount Information for: " << patient.getName()
                   << "\nDays spend in hospital: " << patient.getDaysSpent()
                   <<"\nHospital daily rate: $" << patient.getDailyRate()
                   << ".00\n\nList of Charges:" << endl;
    for (const auto &i : patient.getChargeList())
        patientAccountInfo << "    " << i << endl;
    patientAccountInfo << "    Hospital stay: $" << (patient.getDailyRate()*patient.getDaysSpent()) << ".00\n"
                   << "\nTotal Charges: $" << patient.getPatientCharges() << ".00" << endl;

    cout << patientAccountInfo.str() << endl;

}

/**
 * @brief Program main entry
 *
 * Main method of the program. Program begins here.
 *
 * @param argc command line arguments amount
 * @param argv command line argument values
 * @return program exit code
 */
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
        else if (userChoice=="no") {
            cout << "\nThank you for using this program!" << endl;
        } else {
            cout << "\nInvalid Input\nPlease Try Again\n" << endl;
        }
    }


    delete(surgery);
    delete(pharmacy);

    return 0;
}