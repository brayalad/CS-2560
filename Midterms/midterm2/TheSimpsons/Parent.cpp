//Parent.cpp
#include "Parent.h"
#include <iostream>

Parent::Parent() : Human("",0,' ')
{

}

Parent::Parent(std::string _name, int _age, char _sex) : Human(std::move(_name), _age, _sex)
{

}

void Parent::setChild(Child *_child)
{
    children.push_back(_child->getName());
}

void Parent::printChild() const
{
    std::cout << getName() << "'s child(ren): " << std::endl;
    for(const auto & i : children)
        std::cout << i << std::endl;
}

void Parent::setChildAllowance(int _allowance, Child *_child)
{
    _child->allowance = _allowance;
}
