#ifndef SIMPSONS_CHILD_H
#define SIMPSONS_CHILD_H

#include <string>
#include "Human.h"


class Child : public Human{

private:
    std::string momName;
    std::string dadName;
    int allowance;
    friend class Parent;
    Child();

public:
    Child(std::string _name, int _age, char _sex, std::string _momName, std::string _dadName);
    int getAllowance() const;
    void printParents() const;



};


#endif //SIMPSONS_CHILD_H
