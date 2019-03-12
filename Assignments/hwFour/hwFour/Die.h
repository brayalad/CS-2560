//
// Created by BRYAN on 3/8/2019.
//

#ifndef GAMEOF21_DIE_H
#define GAMEOF21_DIE_H


class Die {

private:
    int sides;
    int value;

public:
    explicit Die(int = 6);
    void roll();
    int getSides();
    int getValue();

};


#endif //GAMEOF21_DIE_H
