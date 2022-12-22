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
    
   
    cout <<"Player X: "<<getPos().x<<endl;
    cout <<"Player Y: "<<getPos().y<<endl;
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
                
                
               cout <<"get colour: "<< p->getColour()<<endl;
                cout <<"get type: "<< p->getType()<<endl;
                
                
                
                ofTranslate(500, 500);
                
                color = getPlatformColorUnderPlayer() ;
                
               
                // only do it if the player color and platform color are the same
                
                if(pos.y + getHeight()>=p->getPos().y)
                {
                    //
                    setY(p->getPos().y - getHeight());
                    
                    
                }
                    
                // standing on top of platform
              
                    speed = 0;
                    jumpingCooldown=0;
                
            }
            p = p->getNext();
        }

    }
    setY(getPos().y+speed);
  
}

ofColor Player::getPlatformColorUnderPlayer()
{
    
  

//    ofTranslate(getPos().x, getPos().y);
    
    ofTranslate(0, 749 - getPos().y);

    platformImage.grabScreen(getPos().x,getPos().y, 500, 500);
    
//    platformColour = platformImage.getPixels().getColor(0);
    

    platformImage.draw(getPos().x, getPos().y+40);
   
    platformImage.save("image.png");
    
    
//    cout << "Platform Colour: "<<platformColour<<endl;
   

    return platformColour;

    
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
