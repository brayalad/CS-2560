//
// Created by BRYAN on 3/8/2019.
//

#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die(int numOfSides) {

    srand(time(nullptr));
    sides = numOfSides;
    roll();

}

void Die::roll() {

    const int MIN_VALUE = 1;

    value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;

}

int Die::getSides() {
    return sides;
}

int Die::getValue() {
    return value;
}
