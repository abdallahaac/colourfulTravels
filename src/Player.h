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


struct JumpInfo
{
    int y, x, dy, dx, time;

    void initialize()
    {
        y, x, dy, dx, time = 0;
    }
};

class Player: public GameObject
{
    private:
    
    public:
    
        Player();
    
        int getScore();
        void increaseScore();
        void playerMovement(PlayerAction* action);
};
