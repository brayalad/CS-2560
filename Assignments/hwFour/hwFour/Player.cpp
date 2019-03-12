//
// Created by BRYAN on 3/8/2019.
//

#include "Player.h"

Player::Player(int initialScore) {
    score = initialScore;
}

void Player::increaseScore(int rollVaule) {
    score += rollVaule;
}

int Player::getScore() {
    return score;
}
