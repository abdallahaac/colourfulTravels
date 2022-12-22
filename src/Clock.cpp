

#include "Main.h"

void Clock::setTimer(Player player)
{
    // setting timer to be 100 seconds
     time = START_TIME;
    timer = time;
  
    }
    
    
    

int Clock::getLastPlatformPositionY()
{
     lastPlatformPositionY = LAST_PLATFORM_Y_POSITION;
    
    return lastPlatformPositionY;
}

float Clock::getDecrementValue()
{
     decrementValue = TIMER_DECREMENT_VALUE;
    
    return decrementValue;
}


float Clock::getTimer()
{
    return timer;
}

void Clock::updateTimer(Player player)
{
    int lastPlatformPositionY = getLastPlatformPositionY();
    
    
    if(timer<=0)
    {
        timer=0;
    }
    
    if(timer>1 &&player.getPos().y>=lastPlatformPositionY)
    {
        
        float decrementVal = getDecrementValue();
        timer -=decrementVal;
    }else{
        timer-=0;
    }

}

float Clock::getTimerWhenPlayerWon(Player player)
{
    
    int lastPlatformPositionY = getLastPlatformPositionY();
    if(player.getPos().y<=lastPlatformPositionY)
    {
        timer-=0;
        return timer;
    }
    

    return ;
}



void Clock::increaseTimeOnCollision(Player player,PowerUps fruits)
{
    
    if(fruits.isCollidedWithPlayer(player))
    {
        timer +=TIMER_INCREMENT_VALUE;
        
    }
    
}
