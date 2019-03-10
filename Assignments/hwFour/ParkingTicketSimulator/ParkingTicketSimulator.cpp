#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

const static int parkingTimeLimit = 60;
const static int amountOfMeters = 20;
static bool initiailized = false;
static ParkingMeter meters[amountOfMeters];
static PoliceOfficer officer;

string getInput(){
    string userInput;
    getline(cin,userInput);
    return userInput;
}

void seeAllMeters(){

    srand(time(0));

    int sizeOfMeters = *(&meters+1) - meters;

    if(!initiailized) {
        for (int i=0;i<sizeOfMeters;++i) {
            int chance = rand() % 100;

            if (chance <= 35)
                meters[i] = ParkingMeter(rand() % 60);
            else if (chance > 35 && chance <= 55)
                meters[i] = ParkingMeter(rand() % 120);
            else if (chance > 55 && chance <= 80)
                meters[i] = ParkingMeter(rand() % 180);
            else if (chance > 80 && chance <= 90)
                meters[i] = ParkingMeter(rand() % 240);
            else if (chance > 90 && chance < 97)
                meters[i] = ParkingMeter(rand() % 300);
            else if (chance >= 97)
                meters[i] = ParkingMeter(rand() % 420);
        }
    }
    else{
        for(int i=0;i<sizeOfMeters;++i){
            int chance = rand() % 100;

            if (chance <= 35)
                meters[i].setParkedTime(rand() % 60);
            else if (chance > 35 && chance <= 55)
                meters[i].setParkedTime(rand() % 120);
            else if (chance > 55 && chance <= 80)
                meters[i].setParkedTime(rand() % 180);
            else if (chance > 80 && chance <= 90)
                meters[i].setParkedTime(rand() % 240);
            else if (chance > 90 && chance < 97)
                meters[i].setParkedTime(rand() % 300);
            else if (chance >= 97)
                meters[i].setParkedTime(rand() % 420);
        }
    }

    cout << "\n----------------------------------------------------------------------------------\n"
            "\nThis parking lot has " << sizeOfMeters << " parking spots:\n" << endl;
    for(int i=0; i<sizeOfMeters; ++i){
        cout << "Time on Meter " + to_string(i+1) + ": " + to_string(meters[i].getParkedTime()) + " minute(s)";
        if(meters[i].getParkedTime() > parkingTimeLimit)
            cout << " (EXPIRED)" << endl;
        else
            cout << "\n";
    }
    cout << "\n----------------------------------------------------------------------------------\n" << endl;
}

void makePoliceOfficer(){

    cout << "\nThis is a Parking Ticket Simulator\n"
         << "-------------------------------------\n" << endl;
    cout << "Please enter your name: ";
    string name = getInput();
    cout << "Please enter your assigned badge number: ";
    string badge = getInput();

    officer = PoliceOfficer(name, badge);

    cout << "\nHello " + officer.getName() + ". Welcome to your first day as a police officer.\n"
             "Your job is to save lives, and you will be doing that by giving out parking tickets.\n"
             "You will check the meters and see if a car's time has expired. If it has, write them a parking ticket.\n"
             "Make sure to include your name and badge number as well as the vehicles make, model, color, and licence plate number.\n"
             "Check the meter time to calculate how much the fine will be. Do this for every parked car who's time has expired.\n"
             "Good luck, stay safe, and go out there and protect the world.\n" << endl;

}

ParkedCar getParkedCar(int minParked){

    cout << "Enter Car Make: ";
    string make = getInput();
    cout << "Enter Car Model: ";
    string model = getInput();
    cout << "Enter Car Color: " ;
    string color = getInput();
    cout << "Enter Licence Plate Number: ";
    string licence = getInput();

    return ParkedCar(make, model, color, licence, minParked);
}

ParkingTicket writeParkingTicket(int meterNumber){

    int minParked = meters[meterNumber].getParkedTime();

    ParkedCar carAtMeter = getParkedCar(minParked);
    ParkingTicket ticket = officer.makeParkingTicket(carAtMeter);

    return ticket;
}

void patrolMeters(){

    seeAllMeters();

    string userInput;
    while(true) {
        cout << "Do you want to issue a ticket to an expired meter? (yes/no)" << endl;
        userInput = getInput();
        if (userInput == "yes" && userInput != "no") {
            cout << "Enter which meter to write ticket for: ";
            int meterNumber = stoi(getInput()) - 1;
            if(meterNumber>=0 && meterNumber<amountOfMeters) {
                if (meters[meterNumber].getParkedTime() > parkingTimeLimit) {
                    cout << writeParkingTicket(meterNumber).getParkingTicket() << endl;
                    break;
                }
                else
                    cout << "\nParking meter chosen is not expired.\nMake sure meter is expired next time out on patrol.\n" << endl;
            }
            else
                cout << "\nParking meter chosen does not exist.\nPlease input a valid meter number.\n" << endl;
        }
        else if (userInput!="yes" && userInput=="no")
            break;
        else
            cout << "\nInvalid Input.\nPlease Try Again.\n" << endl;
    }
}

int main() {

    makePoliceOfficer();

    int userInput;
    while(true){

        cout << "\nWhat would you like to do?\n"
                "   1.  Go out on patrol\n"
                "   2.  Go home\n"
                "\nEnter your choice: ";

        try {
            userInput = stoi(getInput());

            if (userInput == 1)
                patrolMeters();
            else if (userInput == 2) {
                cout << "\nThank You for using using this simulation" << endl;
                break;
            } else
                cout << "\nInvalid Input.\nPlease Try Again.\n" << endl;
        }
        catch (exception& e){
            cout << "\nInvalid Input.\nInput must be a number.\nPlease Try Again.\n" << endl;
        }

    }


    return 0;
}