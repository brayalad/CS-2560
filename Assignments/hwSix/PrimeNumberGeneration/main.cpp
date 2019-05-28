//main.cpp PrimeNumberGenerator
#include <iostream>
#include <vector>
#include "Prime.h"

std::string getInput(){
    std::string input;
    std::getline(std::cin,input);
    return input;
}

int main(int argc, char *argv[]) {

    std::cout << "\nPrime Number Generation\n" << std::endl;

    std::vector<int> prime;

    std::string choice;
    while(choice!="no") {

        std::cout << "\nDo you want to generate a list of Prime Numbers?(yes/no)" << std::endl;
        choice = getInput();

        if (choice == "yes") {
            int userNumber = 1;
            while (userNumber < 2) {
                std::cout << "\nEnter Number for Prime Generator: ";
                try {
                    userNumber = stoi(getInput());
                }
                catch (std::exception &e) {
                    userNumber = 1;
                }
                if (userNumber < 2) {
                    std::cout << "Number must be greater than 2" << std::endl;
                }
            }

            int count = 2;
            while (count <= userNumber) {
                prime.push_back(count++);
            }

            std::cout << "Prime Numbers between 2 and " << userNumber << ": ";
            for_each(prime.begin(), prime.end(), Prime());
            std::cout << "\n";
            prime.clear();

        }
        else if(choice=="no"){
            std::cout << "\nThank you for using this program!" << std::endl;
        }
        else{
            std::cout << "\nInvalid Input. Please Try Again." << std::endl;
        }
    }


    return 0;
}