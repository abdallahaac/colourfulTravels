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

void Player::playerMovement(PlayerAction* action){
    


    if(action->right)  // right movement
    {
        setX(getPos().x+1  );
        
    }else if (action->left) // left movement
    {
        setX(getPos().x-1 );
        
        if(getPos().x<=0)
        {
            setX(0);
        }
        
        
    }else if (action->jump) //  jump movement
    {
        
    
        
    }

    
}
