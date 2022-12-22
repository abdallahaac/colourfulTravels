#include <stdio.h>
#include "Main.h"
#pragma once


Player::Player()
{
    speed = 0;
}

int Player::getScore()
{
    return 0;
}

void Player::playerMovement(PlayerAction* action,Platform* head)
{
    
   
 
    jumpingCooldown-=1;

    int gravity = 1;
    int jumpingSpeed = -30;
    
    speed += gravity ;
    
    
    if (action->right )  // right movement
    {
        setX(getPos().x+5  );
       
        cout <<"d\n";
    }
    else if (action->left) // left movement
    {
        
  
        setX(getPos().x-5 );
        
        if(getPos().x<=0)
        {
            setX(0);
        }
        cout <<"a\n";
    }
    else if (jumping&&jumpingCooldown<=0) //  jump movement
    {


        // moving up (negative)
        speed = jumpingSpeed;
        
        jumpingCooldown=1000;

        jumping = false;
     
    }
    
    // only doing collision when going down
    if(speed>0)
    {
        Platform* p = head;
//        cout <<"Jumping: "<<jumping<<endl;

        while (p != NULL)
        {
       
            //check for collisoon
            if(p->isCollided(this) )
            {
                
                //if statement check if we collided with a normal platform or rainbow platform
                if(p->getType()==PLATFORMS::SPECIAL)
                {
                    // moving up (negative)
                    color = getPlatformColorUnderPlayer(p->getColour());
                    speed = 0;
                    jumpingCooldown=0;
                    
                    if(pos.y + getHeight()>=p->getPos().y)
                    {
                        //
                        setY(p->getPos().y - getHeight());
                    }
                        
                    
                }else if(p->getType()!=PLATFORMS::SPECIAL&&color==getPlatformColorUnderPlayer(p->getColour())||p->getType()==PLATFORMS::END)
                {
                    speed = 0;
                    jumpingCooldown=0;
                    if(pos.y + getHeight()>=p->getPos().y)
                    {
                        //
                        setY(p->getPos().y - getHeight());
                    }
                }
                
                
            }
            p = p->getNext();
        }

    }
    setY(getPos().y+speed);
  
}

ofColor Player::getPlatformColorUnderPlayer(int colour)
{
    

    
    
    switch (colour) {
        case 0:
            platformColour.set(254, 73, 80);
            return platformColour;

            break;
        case 1:
            platformColour.set(242, 121, 63);
            return platformColour;

            break;
        case 2:
            platformColour.set(243, 206, 63);
            return platformColour;

            break;
        case 3:
            platformColour.set(74, 204, 89);
            return platformColour;

            break;
        case 4:
            platformColour.set(75, 141, 248);
            return platformColour;

            break;
        case 5:
            platformColour.set(183, 83, 248);
            return platformColour;

            break;
            
        default:
            break;
    }
    
//    cout << "Platform Colour: "<<platformColour<<endl;
   

   
    
    }

 

    






void Player::setPlayerColor()
{
//    playerColor = getPlatformColorUnderPlayer();
}

void Player::setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage)
{
    pos.x = startingX;
    pos.y = startingY;

    height = objectHeight;
    width = objectWidth;

    image = objectImage;
    
    //setting speed
    speed = 0;

    jumpingCooldown = 0;
    
}
