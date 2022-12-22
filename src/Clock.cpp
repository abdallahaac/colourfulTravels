

#include "Main.h"

void Clock::setTimer()
{
    // setting timer to be 60 seconds
    
    
    float time = 100000.0f;
    timer = time;
}

float Clock::getTimer()
{
    return timer;
}

void Clock::updateTimer(Player player)
{
    int lastPlatformPositionY = -3200;
    
    
    if(timer<=0)
    {
        timer=0;
    }
    
    if(timer>1 &&player.getPos().y>=lastPlatformPositionY)
    {
        
//        timer -=0.015f;
        timer -=0.09f;
    }else{
        timer-=0;
    }

}

float Clock::getTimerWhenPlayerWon(Player player)
{
    
    int lastPlatformPositionY = -3200;
    if(player.getPos().y<=lastPlatformPositionY)
    {
        timer-=0;
        cout << "end timer: "<<timer<<endl;
        return timer;
    }
    

    return ;
}

