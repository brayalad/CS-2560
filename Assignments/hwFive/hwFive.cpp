#include "Circle.h"
#include "NumDays.h"
#include "ProductionWorker.h"
#include "MilTime.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int getIntInput(){
    int userInput;
    cin >> userInput;
    return userInput;
}

double getDoubleInput(){
    double userInput;
    cin >> userInput;
    return userInput;
}

string getTextInput(){
    string userInput;
    getline(cin, userInput);
    return userInput;
}

void circle(){

    cout << "\nCircle Class Program:\n" << endl;
    cout << "Enter Radius: ";
    double radius = getDoubleInput();

    Circle circle = Circle(radius);

    cout << "\nArea: " << circle.getArea() << endl;
    cout << "Diameter: " << circle.getDiameter() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;


}

void numDays(){

    cout << "\nNumDays Program:\n" << endl;

    cout << "Enter hours for first NumDays object: ";
    NumDays nd1 = NumDays(getDoubleInput());
    cout << "Enter hours for second NumDays object: ";
    NumDays nd2 = NumDays (getDoubleInput());

    NumDays nd3 = nd1 + nd2;
    NumDays nd4 = nd1 - nd2;

    cout << "\nObject 1 has " << nd1.getHours() << " hours, which is " << nd1.getDays() << " days." << endl;
    cout << "Object 2 has " << nd2.getHours() << " hours, which is " << nd2.getDays() << " days." << endl;
    cout << "\nThe sum of both objects is " << nd3.getHours() << " hours, which is " << nd3.getDays() << " days." << endl;
    cout << "The difference of both objects is " << nd4.getHours() << " hours, which is " << nd4.getDays() << " days." << endl;

}


void productionWorker(){

    cout << "Employee and Production Worker Program:\n" << endl;
    cin.ignore();

    cout << "\nEnter name: ";
    string name = getTextInput();
    cout << "Enter ID: ";
    int id = getIntInput();
    cout << "Enter Month: ";
    int month = getIntInput();
    cout << "Enter Day: ";
    int day = getIntInput();
    cout << "Enter Year: ";
    int year = getIntInput();

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

        ProductionWorker productionWorker = ProductionWorker(name, id, hireDate, shift, hourlyPay);

        cout << "\nEmployee Profile has been generated bellow:\n" << endl;
        cout << "   Name: " << productionWorker.getName() << endl;
        cout << "   Employee ID: " << productionWorker.getNumber() << endl;
        cout << "   Hire Date: " << productionWorker.getHireDate() << endl;
        if(productionWorker.getShift() == 1)
            cout << "   You have been assigned the day shift" << endl;
        else
            cout << "   You have been assigned the night shift" << endl;
        cout << "   Your hourly pay will be $" << productionWorker.getHourlyPay() << endl;


    }


}


void milTime(){

    cout << "\nMilitary Time Program:\n" << endl;
    string timeOfDay;
    cout << "Enter hour in military time: ";
    int milHour = getIntInput();
    cout << "Enter seconds in military time: ";
    int milSecond = getIntInput();

    if(milHour < 0 || milHour > 2359 || milSecond < 0 || milSecond > 59 || (milHour%100) < 0 || (milHour%100) > 59){
        cout << "\nError Detected.\n"
                "Hour inputted must be between 0 and 2359.\n"
                "Last two digits of hour inputted can not be greater than 59.\n"
                "Seconds inputted must be between 0 and 59.\n"
                "Please run this option again with valid input." << endl;
    }


    else {

        MilTime milTime = MilTime(milHour, milSecond);

        if (milTime.getHour() < 1200)
            timeOfDay = " A.M.";
        else
            timeOfDay = " P.M.";

        cout << "\n";

        if (milTime.getHour() < 1000 && milTime.getHour() >= 100)
            if (milTime.getSec() < 10)
                cout << "Military Time: 0" << milTime.getHour() << " hours and 0" << milTime.getSec() << " seconds."
                     << endl;
            else
                cout << "Military Time: 0" << milTime.getHour() << " hours and " << milTime.getSec() << " seconds."
                     << endl;
        else if (milTime.getHour() < 100 && milTime.getHour() >= 10)
            if (milTime.getSec() < 10)
                cout << "Military Time: 00" << milTime.getHour() << " hours and 0" << milTime.getSec() << " seconds."
                     << endl;
            else
                cout << "Military Time: 00" << milTime.getHour() << " hours and " << milTime.getSec() << " seconds."
                     << endl;
        else if (milTime.getHour() < 10)
            if (milTime.getSec() < 10)
                cout << "Military Time: 000" << milTime.getHour() << " hours and 0" << milTime.getSec() << " seconds."
                     << endl;
            else
                cout << "Military Time: 000" << milTime.getHour() << " hours and " << milTime.getSec() << " seconds."
                     << endl;
        else if (milTime.getSec() < 10)
            cout << "Military Time: " << milTime.getHour() << " hours and 0" << milTime.getSec() << " seconds." << endl;
        else
            cout << "Military Time: " << milTime.getHour() << " hours and " << milTime.getSec() << " seconds." << endl;


        if (milTime.getStandHr() < 10)
            if (milTime.getMin() < 10)
                if (milTime.getSec() < 10)
                    cout << "Standard Time: 0" << milTime.getStandHr() << ":0" << milTime.getMin() << ":0"
                         << milTime.getSec() << timeOfDay << endl;
                else
                    cout << "Standard Time: 0" << milTime.getStandHr() << ":0" << milTime.getMin() << ":"
                         << milTime.getSec() << timeOfDay << endl;
            else if (milTime.getSec() < 10)
                cout << "Standard Time: 0" << milTime.getStandHr() << ":" << milTime.getMin() << ":0"
                     << milTime.getSec() << timeOfDay << endl;
            else
                cout << "Standard Time: 0" << milTime.getStandHr() << ":" << milTime.getMin() << ":" << milTime.getSec()
                     << timeOfDay << endl;
        else if (milTime.getMin() < 10)
            if (milTime.getSec() < 10)
                cout << "Standard Time: " << milTime.getStandHr() << ":0" << milTime.getMin() << ":0"
                     << milTime.getSec() << timeOfDay << endl;
            else
                cout << "Standard Time: " << milTime.getStandHr() << ":0" << milTime.getMin() << ":" << milTime.getSec()
                     << timeOfDay << endl;
        else if (milTime.getSec() < 10)
            cout << "Standard Time: " << milTime.getStandHr() << ":" << milTime.getMin() << ":0" << milTime.getSec()
                 << timeOfDay << endl;
        else
            cout << "Standard Time: " << milTime.getStandHr() << ":" << milTime.getMin() << ":" << milTime.getSec()
                 << timeOfDay << endl;

    }
}

int main() {

    int userChoice;
    while(true){

        cout << "\nThese are the available programs to run:\n" << endl;
        cout << "   1. Circle Program\n"
                "   2. NumDays Program\n"
                "   3. Employee and Production Worker Program\n"
                "   4. Time Format Program\n"
                "   5. Exit" << endl;
        cout << "\nEnter which program to run: ";
        userChoice = getIntInput();

        cout << "\n----------------------------------------------------------------------------------------" << endl;

        if(userChoice == 1)
            circle();
        else if(userChoice == 2)
            numDays();
        else if(userChoice == 3)
            productionWorker();
        else if(userChoice == 4)
            milTime();
        else if(userChoice == 5)
            break;
        else
            cout << "Invalid Input.\nPlease try again.\n" << endl;

        cout << "\n----------------------------------------------------------------------------------------" << endl;

    }

    return 0;
}