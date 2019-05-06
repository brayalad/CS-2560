//Child.cpp
#include "Child.h"
#include <iostream>

Child::Child() : Human(" ",0,' ')
{
    momName = "";
    dadName = "";
    allowance = 0;
}

Child::Child(std::string _name, int _age, char _sex, std::string _momName, std::string _dadName) : Human(std::move(_name), _age, _sex)
{
    momName = std::move(_momName);
    dadName = std::move(_dadName);
    allowance = 0;
}

int Child::getAllowance() const
{
    return allowance;
}

void Child::printParents() const
{
    std::cout << getName() << "'s Mother: " << momName << std::endl;
    std::cout << getName() << "'s Father: " << dadName << std::endl;
}