//pure virtual example
//#include "stdafx.h"
#include <cstdio>
#include <string>
using namespace std;

// Base class
class Animal {
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal() {};
protected:
    // protected constructor for use by derived classes
    Animal(const string & n, const string & t, const string & s)
            : _name(n), _type(t), _sound(s) {
        printf("Animal Constructed\n");
    }
public:
    void speak() const;
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
    virtual string snap() { return "Animal_Snap"; }     //redefine same signature
    virtual string move() = 0;  //pure virtual function
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// Dog class - derived from Animal
class Dog : public Animal {
    int walked;
public:
    Dog(string n) : Animal(n, "dog", "woof"), walked(0) {
        printf("Dog Constructed\n");
    };
    int walk() { return ++walked; }
    string snap() { return "Dog_Snap"; }    //redefine same signature but, I can still call as it was statically linked
    string move() { return "Dog_Move"; }
};

// Cat class - derived from Animal
class Cat : public Animal {
    int petted;
public:
    Cat(string n) : Animal(n, "cat", "meow"), petted(0) {
        printf("Cat Constructed\n");
    };
    int pet() { return ++petted; }
    string move() { return "Cat_Move"; }
};

class Donkey :public Animal {
    int carried;
public:
    Donkey(string n) : Animal(n, "donkey", "hee-haw"), carried(0) {
        printf("Donkey constructed\n");
    };
    int carry() { return ++carried; }
    string move() { return "Donkey_Move"; }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int fed;
public:
    Pig(string n) : Animal(n, "pig", "oink"), fed(0) {
        printf("Pig Constructed\n");
    };
    int feed() { return ++fed; }
    string move() { return "Pig_Move"; }
};

//Poly
string displayName(const Animal &A) {
    return A.name();
}


int main(int argc, char ** argv) {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    Donkey donk("Eeyore");

    //Poly
    //calling a specific ANIMAL -> a derived class of base
    printf("%s\n", displayName(d).c_str() );
    printf("%s\n", displayName(c).c_str());
    printf("%s\n", displayName(p).c_str());

    //d.snap()  //who get called?
    printf("%s\n", d.snap().c_str());
    printf("%s\n", d.Animal::snap().c_str());

    //virtual function calls
    printf("%s\n", d.move().c_str());
    printf("%s\n", c.move().c_str());
    printf("%s\n", p.move().c_str());


    d.speak();
    c.speak();
    p.speak();
    donk.speak();

    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the pig has been fed %d times\n", p.feed());
    printf("the Donkey has been carried %d times\n", donk.carry());

    return 0;
}