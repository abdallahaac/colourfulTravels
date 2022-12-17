//
//  Player.cpp
//  ColourfulTravels
//
//  Created by Abdallah AC on 2022-12-02.
//

#include <stdio.h>
#include "Main.h"


Player::Player(){
    
}

int Player::getScore()
{
    return 0;
}

void Player::playerMovement(PlayerAction* action)
{
    if (action->right)  // right movement
    {
        setX(getPos().x+1  );
    }
    else if (action->left) // left movement
    {
        setX(getPos().x-1 );
        
        if(getPos().x<=0)
        {
            setX(0);
        }  
    }
    else if (action->jump) //  jump movement
    {
        setY(getPos().y - 10); // <-- TEMP FOR TESTING CAMERA
    }
}
