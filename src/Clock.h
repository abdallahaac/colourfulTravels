
#pragma once


class Clock:public GameObject
{
private:
    float timer;
public:

//    void setUp(int startingX, int startingY, int objectHeight, int objectWidth);
    void setTimer();
    float getTimer();
    void updateTimer(Player player);

    float getTimerWhenPlayerWon(Player player);
    
    
};
