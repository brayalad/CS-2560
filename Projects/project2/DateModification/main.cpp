#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

extern const int current_year(2019);

string getInput(){
    string input;
    getline(cin,input);
    return input;
}

void printDate(Date *date){
    int choice=0;
    while(choice<1 || choice>3) {
        cout << "\nIn what format do you want to print the date?\n"
                "   1 -> 12/25/2018\n"
                "   2 -> December 25, 2018\n"
                "   3 -> 25 December 2018\n"
                "Enter choice: ";
        try {
            choice = stoi(getInput());
            if (choice >= 1 && choice <= 3) {
                cout << "\nDate: ";
                date->print(choice);
            } else {
                cout << "Invalid Input\nPlease Try Again." << endl;
            }
        }
        catch(exception& e){
            cout << "Invalid Input\nPlease Try Again." << endl;
            choice=0;
        }
    }
}

void subtractDates(Date *date){
    Date otherDate;
    cout << "\nEnter new date bellow:\n " << endl;
    cin >> otherDate;
    cout << "\nThere are " << *date-otherDate << " days between "
         << date->getMonth() << "/" << date->getDay() << "/" << date->getYear() << " and "
         << otherDate.getMonth() << "/" << otherDate.getDay() << "/" << otherDate.getYear() << endl;
    cin.ignore();
}

void dateMenu(Date *date){

    string choice;
    while (choice!="7"){

        cout << "\nWhat would you like to with this date?\n"
                "   1. Prefix Increment\n"
                "   2. Postfix Increment\n"
                "   3. Prefix Decrement\n"
                "   4. Postfix Decrement\n"
                "   5. Print Date\n"
                "   6. Find Days Between Another Date\n"
                "   7. Make A New Date\n"
                "Enter choice: ";
        choice=getInput();
        if(choice=="1"){
            ++*date;
            cout << "\nDate Incremented to ";
            date->print(1);
        }
        else if(choice=="2"){
            (*date)++;
            cout << "\nDate Incremented to ";
            date->print(1);
        }
        else if(choice=="3"){
            --*date;
            cout << "\nDate Decremented to ";
            date->print(1);
        }
        else if(choice=="4"){
            (*date)--;
            cout << "\nDate Decremented to ";
            date->print(1);
        }
        else if(choice=="5"){
            printDate(date);
        }
        else if(choice=="6"){
            subtractDates(date);
        }
        else if(choice=="7"){
            break;
        }
        else{
            cout << "\nInvalid Input\nPlease Try Again." << endl;
        }

    }

}

int main(int argc, char **argv) {

    cout << "Date Modification Program\n" << endl;
    Date date;

    string choice;
    while(true) {
        cout << "Do you want to create a new date? (yes/no)" << endl;
        choice = getInput();
        if (choice == "yes") {
            cin >> date;
            cout << "\nDate Generated: ";
            cout << date;
            cin.ignore();
            dateMenu(&date);
        }
        else if(choice == "no"){
            cout << "Thank you for using this program" << endl;
            break;
        }
        else{
            cout << "\nInvalid Input\nPlease Try Again." << endl;
        }
    }

    return 0;
}