//GameState.h
#pragma once

class GameState
{
public:
    virtual void initialize(){};
    virtual void handleInput(){};
    virtual void update(float frameRate){};
    virtual void draw(){};

};
