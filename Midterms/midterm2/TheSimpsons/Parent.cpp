
#include "Parent.h"
#include <iostream>

using namespace std;

Parent::Parent() : Human("",0,' ') {}

Parent::Parent(std::string _name, int _age, char _sex) : Human(_name, _age, _sex) {}

void Parent::setChild(Child *_child) {
    children.push_back(_child->getName());
}

void Parent::printChild() const{
    cout << getName() << "'s child(ren): " << endl;
    for(const auto & i : children)
        cout << i << endl;
}

void Parent::setChildAllowance(int _allowance, Child *_child) {
    _child->allowance = _allowance;
}
