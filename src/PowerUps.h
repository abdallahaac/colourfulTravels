
#pragma once

class PowerUps:public GameObject
{

    
public:
    void setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage);

    bool isCollidedWithPlayer(Player player);

    
};
