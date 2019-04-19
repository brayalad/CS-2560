
#include "Human.h"

using namespace std;

Human::Human() {
    setName("");
    setAge(0);
    setSex(' ');
}

Human::Human(string _name, int _age, char _sex) {
    setName(_name);
    setAge(_age);
    setSex(_sex);
}

Human::~Human() {

}

void Human::setName(std::string _name) {
    name = _name;
}

void Human::setAge(int _age) {
    age = _age;
}

void Human::setSex(char _sex) {
    sex = _sex;
}
