//main.cpp Exception Projects
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ProductionWorker.h"

int main() {

    std::cout << "\nExceptions Project\n" << std::endl;

    ProductionWorker *productionWorker;
    std::string choice;

    while(choice!="no") {

        std::cout << "\nRun driver code?(yes/no)" << std::endl;
        std::getline(std::cin,choice);

        if(choice=="yes") {
            std::string name = "Bryan Ayala";
            std::string hireDate = "07/29/2008";
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
                            std::cout << "\nData Entered:"
                                    "\nName: " << name <<
                                 "\nHire Date: " << hireDate <<
                                 "\nID: " << id <<
                                 "\nShift: " << shift <<
                                 "\nHourly Pay: " << hourlyPay << std::endl;
                            try {
                                productionWorker = new ProductionWorker(name, id, hireDate, shift, hourlyPay);
                                valid = true;
                            }
                            catch (Employee::InvalidEmployeeNumber) {
                                std::cout << "Exception Caught: Invalid Employee Number" << std::endl;
                            }
                            catch (ProductionWorker::InvalidShift) {
                                std::cout << "Exception Caught: Invalid Shift" << std::endl;
                            }
                            catch (ProductionWorker::InvalidPayRate) {
                                std::cout << "Exception Caught: Invalid Pay Rate" << std::endl;
                            }
                        }
                    }
                }
            }

            std::cout << "\nEmployee Profile has been generated bellow:\n" << std::endl;
            std::cout << "   Name: " << productionWorker->getName() << std::endl;
            std::cout << "   Employee ID: " << productionWorker->getNumber() << std::endl;
            std::cout << "   Hire Date: " << productionWorker->getHireDate() << std::endl;
            if (productionWorker->getShift() == 1)
                std::cout << "   You have been assigned the day shift" << std::endl;
            else
                std::cout << "   You have been assigned the night shift" << std::endl;
            std::cout << "   Your hourly pay will be $" << productionWorker->getHourlyPay() << std::endl;

        }
        else if(choice=="no"){
            std::cout << "\nThank you for using this program!" << std::endl;
        }
        else{
            std::cout << "\nInvalid Input.Please Try Again." << std::endl;
        }
    }


    return 0;
}