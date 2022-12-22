
#pragma once

class PowerUps:public GameObject
{
private:
    
public:
    void setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage);
//    void powerUpMovement();
    bool isCollidedWithPlayer(Player player);
    void hidePowerUp();
    bool isPowerUpHidden();

    
};
