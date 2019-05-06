//Parent.h
#pragma once

#include "Human.h"
#include "Child.h"
#include <string>
#include <vector>

class Parent : public Human
{
private:
    std::vector<std::string> children;
    Parent();

public:
    Parent(std::string _name, int _age, char _sex);
    void setChild(Child *_child);
    void printChild() const;
    void setChildAllowance(int _allowance, Child *_child);
};