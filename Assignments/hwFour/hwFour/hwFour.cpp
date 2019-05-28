#include <iostream>
#include <string>
#include "GameOf21.h"
#include "ParkingTicketSimulator.h"


int main(int argc, char **argv){

    if(argc==1){
        string choice;
        cout << "Available Programs To Run:\n"
                "   1.  Game Of 21\n"
                "   2.  Parking Ticket Simulator\n"
                "\nEnter Choice: ";
        getline(cin,choice);

        if(choice=="1")
            gameOf21();
        else if(choice=="2")
            parkingTicketSimulator();
    }
    else if(argc==2 && strcmp(argv[1],"--GameOf21")==0)
        gameOf21();
    else if(argc==2 && strcmp(argv[1],"--ParkingTicketSimulator")==0)
        parkingTicketSimulator();
    else if(argc==2 && strcmp(argv[1],"--help")==0)
        cout << "Available Arguments:\n\n   --GameOf21\n   --ParkingTicketSimulator\n   --help\n" << endl;
    else
        cout << "Invalid Arguments\nRun --help for options" << endl; 
    
    
    return 0;

}