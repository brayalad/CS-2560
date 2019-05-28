#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "ParkingTicketSimulator.h"

static std::string getInput(){
    std::string userInput;
    getline(std::cin,userInput);
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

    std::cout << "\n----------------------------------------------------------------------------------\n"
            "\nThis parking lot has " << sizeOfMeters << " parking spots:\n" << std::endl;
    for(int i=0; i<sizeOfMeters; ++i){
        std::cout << "Time on Meter " + std::to_string(i+1) + ": " + std::to_string(meters[i].getParkedTime()) + " minute(s)";
        if(meters[i].getParkedTime() > parkingTimeLimit)
            std::cout << " (EXPIRED)" << std::endl;
        else
            std::cout << "\n";
    }
    std::cout << "\n----------------------------------------------------------------------------------\n" << std::endl;
}

void makePoliceOfficer(){

    std::cout << "\nThis is a Parking Ticket Simulator\n"
         << "-------------------------------------\n" << std::endl;
    std::cout << "Please enter your name: ";
    std::string name = getInput();
    std::cout << "Please enter your assigned badge number: ";
    std::string badge = getInput();

    officer = PoliceOfficer(name, badge);

    std::cout << "\nHello " + officer.getName() + ". Welcome to your first day as a police officer.\n"
             "Your job is to save lives, and you will be doing that by giving out parking tickets.\n"
             "You will check the meters and see if a car's time has expired. If it has, write them a parking ticket.\n"
             "Make sure to include your name and badge number as well as the vehicles make, model, color, and licence plate number.\n"
             "Check the meter time to calculate how much the fine will be. Do this for every parked car who's time has expired.\n"
             "Good luck, stay safe, and go out there and protect the world.\n" << std::endl;

}

ParkedCar getParkedCar(int minParked){

    std::cout << "Enter Car Make: ";
    std::string make = getInput();
    std::cout << "Enter Car Model: ";
    std::string model = getInput();
    std::cout << "Enter Car Color: " ;
    std::string color = getInput();
    std::cout << "Enter Licence Plate Number: ";
    std::string licence = getInput();

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

    std::string userInput;
    while(true) {
        std::cout << "Do you want to issue a ticket to an expired meter? (yes/no)" << std::endl;
        userInput = getInput();
        if (userInput == "yes" && userInput != "no") {
            std::cout << "Enter which meter to write ticket for: ";
            int meterNumber = stoi(getInput()) - 1;
            if(meterNumber>=0 && meterNumber<amountOfMeters) {
                if (meters[meterNumber].getParkedTime() > parkingTimeLimit) {
                    std::cout << writeParkingTicket(meterNumber).getParkingTicket() << std::endl;
                    break;
                }
                else
                    std::cout << "\nParking meter chosen is not expired.\nMake sure meter is expired next time out on patrol.\n" << std::endl;
            }
            else
                std::cout << "\nParking meter chosen does not exist.\nPlease input a valid meter number.\n" << std::endl;
        }
        else if (userInput!="yes" && userInput=="no")
            break;
        else
            std::cout << "\nInvalid Input.\nPlease Try Again.\n" << std::endl;
    }
}

int parkingTicketSimulator() {

    makePoliceOfficer();

    int userInput;
    while(true){

        std::cout << "\nWhat would you like to do?\n"
                "   1.  Go out on patrol\n"
                "   2.  Go home\n"
                "\nEnter your choice: ";

        try {
            userInput = stoi(getInput());

            if (userInput == 1)
                patrolMeters();
            else if (userInput == 2) {
                std::cout << "\nThank You for using using this simulation" << std::endl;
                break;
            } else
                std::cout << "\nInvalid Input.\nPlease Try Again.\n" << std::endl;
        }
        catch (std::exception& e){
            std::cout << "\nInvalid Input.\nInput must be a number.\nPlease Try Again.\n" << std::endl;
        }

    }


    return 0;
}