//
//  Player.h
//  ColourfulTravels
//
//  Created by Abdallah AC on 2022-12-02.
//

#ifndef Player_h
#define Player_h


#endif /* Player_h */


#define PLAYER_SPEED                            // Player movement speed

#pragma once
#include "Platform.h"



class Player: public GameObject
{
    private:
    
    public:
    
    int gravity;
    int  jumpingSpeed;
    int horizontalSpeed;
    float playerGroundLevel;
    
    
        Player();
        float jumpTime;
        bool jumping;
        ofColor playerColor;
        int speed ;
        int jumpingCooldown;
       
    
    
    
    
        int getScore();
        void increaseScore();
        void playerMovement(PlayerAction* action,Platform* head);
        void setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage);
    
        
    // platform color
    ofColor color;
    ofColor platformColour;
    ofImage platformImage;
    
    //platform image
    ofColor getPlatformColorUnderPlayer(int color);
    
    };
