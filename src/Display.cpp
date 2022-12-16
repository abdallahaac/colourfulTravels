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
void Display::displayCanvasView(Player player, Platform* firstPlatform, /*PowerUp fruit[],*/ int numPowerUps, /*Clock timer,*/ GameObject pauseButton)
{
	// Drawing background 
	gameBackground.draw(0, 0);

	ofPushMatrix();
	
		// Camera movements
		ofTranslate(0, PLAYER_STARTING_Y - player.getPos().y);

		// Drawing platfroms 
		Platform* p = firstPlatform;

		while (p != NULL)
		{
			displayGameObject(*p);

			p = p->getNext();
		}

		// Drawing player
		displayGameObject(player);

	ofPopMatrix();
}

//	Draws the main menu to screen with instructions, play button, and highscore
void Display::displayMainMenu(GameObject playButton, int highscore)
{
	mainMenuBackground.draw(0, 0);

	playButton.getImage()->draw(playButton.getPos().x, playButton.getPos().y);

	ofDrawBitmapString(ofToString(highscore), 1127, 585);
}

// Draws the pause menu to screen with unpause button, restart button, and main menu button
void Display::displayPausedMenu()
{
	gameBackground.draw(0, 0);

//    playButton.getImage()->draw(playButton.getPos().x, playButton.getPos().y);
//
//    ofDrawBitmapString(ofToString(highscore), 1127, 585);
    
}

// Draws the finished game menu to screen with the player’s score, if they have won or not, play again button, and main menu button
void Display::displayEndGame()
{

}
