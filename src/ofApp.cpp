#include "Main.h"

// Built-in functions

// Initialises member variables
void ofApp::setup()
{
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
	ofSetFrameRate(FRAME_RATE);

	// Setting up buttons
	buttonSetUp();

	// Sending values to Input object to handle when one was clicked on
	userInput.setButtons(buttons);

    
 
    
    
    image.load("greenLoop.png");


    player.setUp(ofGetWindowWidth()/2,ofGetWindowHeight()/2 , 10, 10,&image );

    
    
    
    
	// Setting default variable values
	currentState = GAME_STATES::MAIN_MENU;
	highscore = 0;
	won = false;
	//currentJump.initialize();

	groundLevel = 0;

	numPowerUps = 0;
	currentPowerUp = 0;

	actions.initialize();
}

// Main program loop
void ofApp::update()
{


    
    
    
    // listens to user keyboard inputs and moves the player corresponsdingly
    player.playerMovement(&actions);

	switch (currentState)
	{
		case GAME_STATES::PLAY:
			return;

		case GAME_STATES::NEW_GAME:

			generateGame();
			currentState = GAME_STATES::PLAY;

			return;

		case GAME_STATES::FINISHED_GAME:
			return;
	}
}

// Calls renderer object functions to draw game to screen
void ofApp::draw()
{
    
    


	switch (currentState)
	{
		case GAME_STATES::PLAY:
			renderer.displayCanvasView();
            renderer.displayGameObject(player);
			return;

		case GAME_STATES::PAUSE:
			renderer.displayPausedMenu();
			return;

		case GAME_STATES::MAIN_MENU:
			renderer.displayMainMenu(buttons[BUTTONS::PLAY_BUTTON], highscore);
			return;

		case GAME_STATES::FINISHED_GAME:
			renderer.displayEndGame();
			return;
	}
}

// If a key, d key, w key, or left mouse button is pressed, update userInputand gameState accordingly
void ofApp::keyPressed(int key)
{
	userInput.keyPress(&actions, key);
    
    
    
}

// If a key or d key is released, update userInput accordingly
void ofApp::keyReleased(int key)
{
	userInput.keyRelease(&actions, key);
}

// If the mouse have been clicked, call checkButtonPress()
void ofApp::mousePressed(int x, int y, int button)
{
	currentState = userInput.mousePress(x, y, button, currentState);
}

// Other functions

// Initilizes the GameObject objects for buttons in the game
void ofApp::buttonSetUp()
{
	// Play button
	buttons[BUTTONS::PLAY_BUTTON].setUp(850, 469, 69, 363, &PLAY_BUTTON);
}

// Generates player information, platforms, power ups, and timer for a game round
// Refer to section 6.6 for game round generation logic
void ofApp::generateGame()
{
	//gamePlayer.setUp();

	//timer.setUp();

	generateWinningPath();

	generateExtraPlatforms();

	generatePowerUps();
}

// Generates the platforms for the winning path with their colour, type (regular or special), and position
int ofApp::generateWinningPath()
{
	return 0;
}

// Generates the random extra platforms with their colour, type(regular or special), and position
void ofApp::generateExtraPlatforms()
{

}

// Generates a random y position for the platform based on JUMP_HEIGHT, and a random x position for the platform based on JUMP_WIDTH
void ofApp::generatePlatforms()
{

}

// Generates the power ups with their type (banana or pear) and what platform they are on
void ofApp::generatePowerUps()
{

}

// One loop of game round loop
void ofApp::gameRound()
{

}

// Sets the high score if the parameter high score is higher than the current one
int ofApp::setHighScore()
{
	return 0;
}

// Picks and returns a random colour from COLOURS
int ofApp::randomColour()
{
	return 0;
}

// Destroys all platform objects at the end of a game round
void ofApp::destroyPlatforms()
{

}
