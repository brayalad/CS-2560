#include <iostream>
#include <vector>

class Human
{
private:
    std::string name;
    int age;
    char sex;
    
    Human()
    {
        name = "";
        age = 0;
        sex = ' ';
    }

protected:
    Human(std::string _name, int _age, char _sex)
    {
        name = _name;
        age = _age;
        sex = _sex;
    }
    virtual ~Human(){}

public:
    void setName(std::string _name)
    {
        name = _name;
    }
    void setAge(int _age){
        age = _age;
    }
    void setSex(char _sex){
        sex = _sex;
    }

    const std::string& getName() const
    {
        return name;
    }
    int getAge() const
    {
        return age;
    }
    int getSex() const
    {
        return sex;
    }
};


class Child : public Human
{
private:
    std::string momName;
    std::string dadName;
    int allowance;
    friend class Parent;
    
    Child() : Human("", 0, ' ')
    {
        momName = "";
        dadName = "";
        allowance = 0;
    }

public:
    Child(std::string _name, int _age, char _sex, std::string _momName, std::string _dadName) : Human(_name, _age, _sex)
    {
        momName = _momName;
        dadName=_dadName;
        allowance = 0;
    }
    int getAllowance() const
    {
        return allowance;
    }
    void printParents()
    {
        std::cout << "Mom: " << momName << std::endl;
        std::cout << "Dad: " << dadName << std::endl;
    }
};


class Parent : public Human
{
private:
    std::vector<std::string> children;
    
    Parent() : Human("", 0, ' ')
    {

    }

public:
    Parent(std::string _name, int _age, char _sex) : Human(_name, _age, _sex)
    {

    }
    void printChild()
    {
        for (int i = 0; i < children.size() ; ++i)
        {
            std::cout << children[i] << std::endl;
        }
    }
    void setChild(Child _child)
    {
        children.push_back(_child.getName());
    }
    void setChildAllowance(int allowance, Child *_child)
    {
        _child->allowance = allowance;
    }
};


void printInfo(Human *_human)
{
    std::cout << "\nName: " << _human->getName()
              << "\nAge: " << _human->getAge()
              << "\nSex: " << _human->getSex() << std::endl;
}


int main(int argc, char **argv) {

    Parent homer = Parent("Homer",36,'M');
    Parent marge = Parent("Marge",34,'F');

    Child bart = Child("Bart",12,'M',homer.getName(),marge.getName());
    Child lisa = Child("Lisa",10,'F',homer.getName(),marge.getName());
    Child maggie = Child("Maggie",2,'F',homer.getName(),marge.getName());

    homer.setChild(bart);
    homer.setChild(lisa);
    homer.setChild(maggie);

    marge.setChild(bart);
    marge.setChild(lisa);
    marge.setChild(maggie);

    std::cout << "Bart Allowance: " <<  bart.getAllowance() << std::endl;
    homer.setChildAllowance(5,&bart);
    std::cout << "Bart Allowance: " <<  bart.getAllowance() << "\n" << std::endl;

    bart.printParents();

    printInfo(&marge);
    printInfo(&lisa);


    return 0;
}