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
    
  
    
    
    if (action->right)  // right movement
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
        
        if(color!=getPlatformColorUnderPlayer())
        {
            speed = jumpingSpeed;
            
            jumpingCooldown=1000;
        }
        
        jumping = false;
     
    }
    
    
    
    // only doing collision when going down
    if(speed>0)
    {
        Platform* p = head;
        cout <<"Jumping: "<<jumping<<endl;

        while (p != NULL)
        {
       

            if(p->isCollided(this) )
            {

                
                color = getPlatformColorUnderPlayer()  ;
                    speed = 0;
                    jumpingCooldown=0;
                
                
                
                //on ground it should be zero
                cout <<"true"<<endl;
//                cout << "color: "<<p->getColour()<<endl;
                //setting speed to zero
//                speed = 0;
//                jumpingCooldown=0;
                
                cout <<"Platform Y Pos: "<< p->getPos().y<<endl;
                cout <<"Platform X pos: "<<p->getPos().x<<endl;
              
            
                
                
                
//
//                ofPushMatrix();
//                ofTranslate(0, PLAYER_STARTING_Y - getPos().y);
//                      platformImage.grabScreen(getPos().x, p->getPos().y , 1,  1);
//                ofPopMatrix();
//
//                    platformColour = platformImage.getPixels().getColor(0);
              
                
            }else{
                
                
                
    //                    cout <<"false"<<endl;
                
            }


            
            p = p->getNext();
            
        }

    }
    
 
    
    

    setY(getPos().y+speed);
  
}

ofColor Player::getPlatformColorUnderPlayer()
{
    
  
  
    cout <<"Y: "<<getPos().y<<endl;
    cout << "Platform Y: "<<platformImage.getWidth()<<endl;

      platformImage.grabScreen(getPos().x, getPos().y+30 , 100, 100);

    platformColour = platformImage.getPixels().getColor(0);
    cout << "Platform Colour: "<<platformColour<<endl;
   

    return platformColour;

    
}

int Player::getPlatformPosition()
{
    
   
//platformImage.grabScreen(getPos().x+11,getPos().y+30, 1, 1);
//
//  platformColour = platformImage.getPixels().getColor(0);
//
//    if(platformColour!=backgroundCo)
//
//    return
    
}



void Player::setPlayerPositionWhenPassing()
{
    ofColor backgroundColor;
    backgroundColor.set(227, 244, 255);
    
    
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
