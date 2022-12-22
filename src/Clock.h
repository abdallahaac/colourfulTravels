
#pragma once


class Clock:public GameObject
{
private:
    float timer;
    int lastPlatformPositionY ;
    float decrementValue;
public:
    float time;
    int getLastPlatformPositionY();
    float getDecrementValue();

//    void setUp(int startingX, int startingY, int objectHeight, int objectWidth);
    void setTimer(Player player);
    float getTimer();
    void updateTimer(Player player);

    float getTimerWhenPlayerWon(Player player);
    
    void increaseTimeOnCollision(Player player,PowerUps fruit);
};
