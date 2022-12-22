// Function delcarations for Display class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, empty as there are no member variables
Display::Display()
{

}

// Private functions **************************************************************************************************************************************

// Draws the object to screen at specified location (takes game object)
void Display::displayGameObject(GameObject toDisplay)
{
	toDisplay.getImage()->draw(toDisplay.getPos().x, toDisplay.getPos().y);
}

// Other Functions ****************************************************************************************************************************************

// Draws the game canvas view to screen
// Refer to section 6.11.7 for algorithm
void Display::displayCanvasView(Player player, Platform* firstPlatform, PowerUps fruit[3], int numPowerUps, Clock timer, GameObject pauseButton)
{
	// Drawing background 
	gameBackground.draw(0, 0);
    



	ofPushMatrix();
	
		// Camera movements
    
        ofTranslate(0, PLAYER_STARTING_Y - player.getPos().y);
//        ofTranslate(0,0);
    

 

		// Drawing platfroms 
		Platform* p = firstPlatform;

		while (p != NULL)
		{
            
          
			displayGameObject(*p);
            

			p = p->getNext();
		}

//drawing power ups
    for (int i =0; i<3; i++) {
        
        
        displayGameObject(fruit[i]);
    }


		// Drawing player
    

    
        ofPushMatrix();
            ofFill();

            ofSetColor(player.color);
        
            displayGameObject(player);

        
        ofPopMatrix();
    
    
    
    ofSetColor(255, 255, 255);

    ofPopMatrix();
	// Drawing pause button

	displayGameObject(pauseButton);
    

 
    //Drawing timer
    displayTimer(timer);

}

//	Draws the main menu to screen with instructions, play button, and highscore
void Display::displayMainMenu(GameObject playButton, int highscore)
{
	// Drawing background
	mainMenuBackground.draw(0, 0);

	// Drawing play button
	displayGameObject(playButton);

	// Drawing highscore
    clockFont.load( "franklinGothic.otf", 30 );
	clockFont.drawString(ofToString(highscore), 1127, 592);
}

// Draws the pause menu to screen with unpause button, restart button, and main menu button
void Display::displayPausedMenu(GameObject resumeButton, GameObject restartButton, GameObject mainMenuButton)
{
	// Drawing background
	pausedMenuBackground.draw(0, 0);   

	// Drawing resume button
	displayGameObject(resumeButton);

	// Drawing restart button
	displayGameObject(restartButton);

	// Drawing main menu button
	displayGameObject(mainMenuButton);
}

// Draws the finished game menu to screen with the player’s score, if they have won or not, play again button, and main menu button
void Display::displayEndGame(GameObject mainMenuButton, GameObject playAgainButton, bool won, int score)
{
	if (won == true)
	{
		// Drawing won background
		wonBackground.draw(0, 0);
	}
	else
	{
		// Drawing lost button
		lostBackground.draw(0, 0);
	}

	// Drawing main menu button
	displayGameObject(mainMenuButton);

	// Drawing play again button
	displayGameObject(playAgainButton);

	// Drawing score
	ofDrawBitmapString(ofToString(score), 735, 435);
}

void Display::displayTimer(Clock timer)
{
    
    clockFont.load( "franklinGothic.otf", 30 );
    clockFont.drawString(ofToString( floorf(timer.getTimer()) ), 20, 100);
    
}
