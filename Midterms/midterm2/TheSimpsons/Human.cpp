//Human.cpp
#include "Human.h"

Human::Human()
{
    this->name = "";
    this->age = 0;
    this->sex = ' ';
}

Human::Human(std::string _name, int _age, char _sex)
{
    this->name = std::move(_name);
    this->age = _age;
    this->sex = _sex;
}

Human::~Human() = default;

void Human::setName(std::string _name)
{
    this->name = std::move(_name);
}

void Human::setAge(int _age)
{
    this->age = _age;
}

void Human::setSex(char _sex)
{
    this->sex = _sex;
}

const std::string &Human::getName() const
{
    return name;
}

int Human::getAge() const
{
    return age;
}

char Human::getSex() const
{
    return sex;
}

