//main.cpp PrimeNumberGenerator
#include <iostream>
#include <vector>
#include "Prime.h"

using namespace std;

string getInput(){
    string input;
    getline(cin,input);
    return input;
}

int main() {

    cout << "\nPrime Number Generation\n" << endl;

    vector<int> prime;

    string choice;
    while(choice!="no") {

        cout << "\nDo you want to generate a list of Prime Numbers?(yes/no)" << endl;
        choice = getInput();

        if (choice == "yes") {
            int userNumber = 1;
            while (userNumber < 2) {
                cout << "\nEnter Number for Prime Generator: ";
                try {
                    userNumber = stoi(getInput());
                }
                catch (exception &e) {
                    userNumber = 1;
                }
                if (userNumber < 2) {
                    cout << "Number must be greater than 2" << endl;
                }
            }

            int count = 2;
            while (count <= userNumber) {
                prime.push_back(count++);
            }

            cout << "Prime Numbers between 2 and " << userNumber << ": ";
            for_each(prime.begin(), prime.end(), Prime());
            cout << "\n";
            prime.clear();

        }
        else if(choice=="no"){
            cout << "\nThank you for using this program!" << endl;
        }
        else{
            cout << "\nInvalid Input. Please Try Again." << endl;
        }
    }


    return 0;
}