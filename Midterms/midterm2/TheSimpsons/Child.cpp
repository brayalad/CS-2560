#include <iostream>
#include "Child.h"

using namespace std;

Child::Child() : Human(" ",0,' ') {
    momName = "";
    dadName = "";
    allowance = 0;
}

Child::Child(string _name, int _age, char _sex, string _momName, string _dadName) : Human(_name, _age, _sex) {
    momName = _momName;
    dadName = _dadName;
    allowance = 0;
}

int Child::getAllowance() const {
    return allowance;
}

void Child::printParents() const{
    cout << getName() << "'s Mother: " << momName << endl;
    cout << getName() << "'s Father: " << dadName << endl;
}
