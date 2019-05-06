//Human.h
#pragma once

#include <string>

class Human
{
private:
    std::string name;
    int age;
    char sex;
    Human();

protected:
    Human(std::string _name, int _age, char _sex);
    virtual ~Human();

public:
    void setName(std::string _name);
    void setAge(int _age);
    void setSex(char _sex);

    const std::string& getName() const;
    int getAge() const;
    char getSex() const;
};


