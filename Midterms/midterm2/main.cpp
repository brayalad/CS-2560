#include <iostream>
#include <vector>

using namespace std;


class Human {

private:
    string name;
    int age;
    char sex;
    friend class Parent;
    friend class Child;
    Human(){
        setName("");
        setAge(0);
        setSex(' ');
    }

protected:
    Human(string name, int age, char sex){
        setName(name);
        setAge(age);
        setSex(sex);
    }
    virtual ~Human(){}

public:
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setSex(char sex){
        this->sex=sex;
    }

    const string& getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }
    int getSex() const {
        return sex;
    }


};


class Child : public Human{

private:
    string momName;
    string dadName;
    int allowance;
    friend class Parent;
    Child() : Human(){
        momName = "";
        dadName = "";
        allowance = 0;
    }

public:
    Child(string name, int age, char sex, string momName, string dadName) : Human(name,age,sex){
        this->momName = momName;
        this->dadName=dadName;
        allowance = 0;
    }
    int getAllowance() const{
        return allowance;
    }
    void printParents(){
        cout<< "Mom: " << momName << endl;
        cout<< "Dad: " << dadName << endl;
    }

};

class Parent : public Human{

private:
    vector<string> children;
    Parent() : Human(){}

public:
    Parent(string name, int age, char sex) : Human(name,age,sex){}
    void printChild(){
        for(int i=0;i<children.size();i++){
            cout<<children[i]<<endl;
        }
    }
    void setChild(Child child){
        children.push_back(child.getName());
    }
    void setChildAllowance(int allowance, Child *child){
        child->allowance = allowance;
    }


};


void printInfo(Human *human){
    cout << "\nName: " << human->getName()
         << "\nAge: " << human->getAge()
         << "\nSex: " << human->getSex() << endl;
}


int main(int argc, char **argv) {

    Parent homer("Homer",36,'M');
    Parent marge("Marge",34,'F');

    Child bart("Bart",12,'M',homer.getName(),marge.getName());
    Child lisa("Lisa",10,'F',homer.getName(),marge.getName());
    Child maggie("Maggie",2,'F',homer.getName(),marge.getName());

    homer.setChild(bart);
    homer.setChild(lisa);
    homer.setChild(maggie);

    marge.setChild(bart);
    marge.setChild(lisa);
    marge.setChild(maggie);

    cout << "Bart Allowance: " <<  bart.getAllowance() << endl;
    homer.setChildAllowance(5,&bart);
    cout << "Bart Allowance: " <<  bart.getAllowance() << "\n" << endl;

    bart.printParents();

    printInfo(&marge);
    printInfo(&lisa);


    return 0;
}