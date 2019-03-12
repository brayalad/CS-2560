//
// Created by BRYAN on 3/8/2019.
//

#ifndef GAMEOF21_PLAYER_H
#define GAMEOF21_PLAYER_H


class Player {

private:
    int score;

public:
    explicit Player(int = 0);
    void increaseScore(int rollVaule);
    int getScore();

};


#endif //GAMEOF21_PLAYER_H
