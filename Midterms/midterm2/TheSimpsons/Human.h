
#ifndef SIMPSONS_HUMAN_H
#define SIMPSONS_HUMAN_H

#include <string>

class Human {

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

    const std::string& getName() const{ return name; };
    int getAge() const{ return age; };
    char getSex() const{ return sex; };


};


#endif //SIMPSONS_HUMAN_H
