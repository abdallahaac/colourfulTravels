
#include "Main.h"

void PowerUps::setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage *objectImage)
{
    
    pos.x = startingX;
    pos.y = startingY;

    height = objectHeight;
    width = objectWidth;

    image = objectImage;
    
    
    
}

bool PowerUps::isCollidedWithPlayer(Player object)
{
    
    // Checking playerX by the minimum x value the platform can be
    if ((object.getPos().x + object.getWidth()) >= pos.x)
    {
        // Checking playerX by the maximum x value the platform can be
        if (object.getPos().x <= (pos.x + width))
        {
            // Checking playerY by the minimum y value the platform can be
            if ((object.getPos().y + object.getHeight()) >= pos.y)
            {
                // Checking playerY by the maximum y value the platform can be
                if (object.getPos().y <= (pos.y + height))
                {
                    // If made it to here, platform was collided with
                    return true;
                }
            }
        }
    }

    return false;
    
}



