#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ProductionWorker.h"

using namespace std;

string getInput(){
    string input;
    getline(cin,input);
    return input;
}

int main() {

    ProductionWorker *productionWorker;

    cout << "Employee and Production Worker Program:\n" << endl;
    //cin.ignore();

    cout << "\nEnter name: ";
    string name =  getInput();
    cout << "Enter ID: ";
    int id =  stoi(getInput());
    cout << "Enter Month: ";
    int month =  stoi(getInput());
    cout << "Enter Day: ";
    int day = stoi(getInput());
    cout << "Enter Year: ";
    int year =  stoi(getInput());

    if(month <= 0 || month > 12 ||
       year <= 0 || year > 2019 ||
       day <= 0 ||
       (month == 1 && day > 31) ||
       (month == 2 && day > 28) ||
       (month == 3 && day > 31) ||
       (month == 4 && day > 30) ||
       (month == 5 && day > 31) ||
       (month == 6 && day > 30) ||
       (month == 7 && day > 31) ||
       (month == 8 && day > 31) ||
       (month == 9 && day > 30) ||
       (month == 10 && day > 31) ||
       (month == 11 && day > 30) ||
       (month == 12 && day > 31) ){
        cout << "Error detected.\nInput must be a valid date.\nPlease run this option again with valid input." << endl;
    }
    else{

        string hireDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

        srand(time(NULL));
        int shift = (rand() % 2) + 1;
        double randomNumber = (rand() % 100);
        double hourlyPay = ((rand() % 5) + 11) + (randomNumber / 100);

        try {
            productionWorker = new ProductionWorker(name, id, hireDate, shift, hourlyPay);
        }
        catch(char* e){
            cout << e << endl;
        }
        cout << "\nEmployee Profile has been generated bellow:\n" << endl;
        cout << "   Name: " << productionWorker->getName() << endl;
        cout << "   Employee ID: " << productionWorker->getNumber() << endl;
        cout << "   Hire Date: " << productionWorker->getHireDate() << endl;
        if(productionWorker->getShift() == 1)
            cout << "   You have been assigned the day shift" << endl;
        else
            cout << "   You have been assigned the night shift" << endl;
        cout << "   Your hourly pay will be $" << productionWorker->getHourlyPay() << endl;


    }

    return 0;
}