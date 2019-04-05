//main.cpp Exception Projects
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ProductionWorker.h"

using namespace std;

int main() {

    cout << "\nExceptions Project\n" << endl;

    ProductionWorker *productionWorker;
    string choice;

    while(choice!="no") {

        cout << "\nRun driver code?(yes/no)" << endl;
        getline(cin,choice);

        if(choice=="yes") {
            string name = "Bryan Ayala";
            string hireDate = "07/29/2008";
            int id;
            int shift;
            double hourlyPay;
            bool valid = false;

            while (!valid) {
                for (int i = 1; i <= 2; ++i) {
                    if (i == 1) {
                        id = 12345;
                    } else if (i == 2) {
                        id = 1234;
                    }
                    for (int j = 1; j <= 2; ++j) {
                        if (j == 1) {
                            shift = 3;
                        } else if (j == 2) {
                            shift = 1;
                        }
                        for (int k = 1; k <= 2; ++k) {
                            if (k == 1) {
                                hourlyPay = -14.50;
                            } else if (k == 2) {
                                hourlyPay = 14.50;
                            }
                            cout << "\nData Entered:"
                                    "\nName: " << name <<
                                 "\nHire Date: " << hireDate <<
                                 "\nID: " << id <<
                                 "\nShift: " << shift <<
                                 "\nHourly Pay: " << hourlyPay << endl;
                            try {
                                productionWorker = new ProductionWorker(name, id, hireDate, shift, hourlyPay);
                                valid = true;
                            }
                            catch (Employee::InvalidEmployeeNumber) {
                                cout << "Exception Caught: Invalid Employee Number" << endl;
                            }
                            catch (ProductionWorker::InvalidShift) {
                                cout << "Exception Caught: Invalid Shift" << endl;
                            }
                            catch (ProductionWorker::InvalidPayRate) {
                                cout << "Exception Caught: Invalid Pay Rate" << endl;
                            }
                        }
                    }
                }
            }

            cout << "\nEmployee Profile has been generated bellow:\n" << endl;
            cout << "   Name: " << productionWorker->getName() << endl;
            cout << "   Employee ID: " << productionWorker->getNumber() << endl;
            cout << "   Hire Date: " << productionWorker->getHireDate() << endl;
            if (productionWorker->getShift() == 1)
                cout << "   You have been assigned the day shift" << endl;
            else
                cout << "   You have been assigned the night shift" << endl;
            cout << "   Your hourly pay will be $" << productionWorker->getHourlyPay() << endl;

        }
        else if(choice=="no"){
            cout << "\nThank you for using this program!" << endl;
        }
        else{
            cout << "\nInvalid Input.Please Try Again." << endl;
        }
    }


    return 0;
}