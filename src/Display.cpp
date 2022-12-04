// Function delcarations for Display class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, empty as there are no member variables
Display::Display()
{

}

// Private functions **************************************************************************************************************************************

// Draws the object to screen at specified location (takes game object)
void Display::displayGameObject()
{

}

// Other Functions ****************************************************************************************************************************************

// Draws the game canvas view to screen
void Display::displayCanvasView()
{
	gameBackground.draw(0, 0);
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
 
    mainMenuBackground.draw(0, 0);

//    playButton.getImage()->draw(playButton.getPos().x, playButton.getPos().y);
//
//    ofDrawBitmapString(ofToString(highscore), 1127, 585);
    
}

// Draws the finished game menu to screen with the player’s score, if they have won or not, play again button, and main menu button
void Display::displayEndGame()
{

}

// Draws the GameObject to the screen
void Display::displayGameObject(GameObject gameObject)
{
    gameObject.getImage()->draw(gameObject.getPos().x, gameObject.getPos().y);
    
}
