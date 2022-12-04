//
//  Player.h
//  ColourfulTravels
//
//  Created by Abdallah AC on 2022-12-02.
//

#ifndef Player_h
#define Player_h


#endif /* Player_h */


#define PLAYER_SPEED                                    // Y position the ground starts

class Player: public GameObject{
    
    
public:
    
    Player();
    
 
    struct JumpInfo
    {
        int y,x,dy,dx,time;
    };
    
    int getScore();
    void increaseScore();
    void playerMovement(PlayerAction* action);
    
    
};
