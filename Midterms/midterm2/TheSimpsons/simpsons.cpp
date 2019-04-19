
#include "Parent.h"
#include "Child.h"
#include <iostream>

using namespace std;

void printInfo(Human *human) {
    cout << "\nName: " << human->getName()
         << "\nAge: " << human->getAge()
         << "\nSex: " << human->getSex() << endl;
}

int main(int argc, char **argv) {

    Parent homer = Parent("Homer",36,'M');
    Parent marge = Parent("Marge",34,'F');

    Child bart = Child("Bart",12,'M',homer.getName(),marge.getName());
    Child lisa = Child("Lisa",10,'F',homer.getName(),marge.getName());
    Child maggie = Child("Maggie",2,'F',homer.getName(),marge.getName());

    homer.setChild(&bart);
    homer.setChild(&lisa);
    homer.setChild(&maggie);

    marge.setChild(&bart);
    marge.setChild(&lisa);
    marge.setChild(&maggie);

    cout << bart.getName() << "'s Allowance: " <<  bart.getAllowance() << endl;
    homer.setChildAllowance(5,&bart);
    cout << bart.getName() << "'s Allowance: " <<  bart.getAllowance() << "\n" << endl;

    bart.printParents();


    printInfo(&marge);
    printInfo(&lisa);


    return 0;
}