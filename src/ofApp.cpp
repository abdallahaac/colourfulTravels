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
    
	// Setting default variable values
	currentState = GAME_STATES::MAIN_MENU;
	highscore = 0;
	won = false;

	currentJump.initialize();

	// Ground
	firstPlatform = new Platform();
	firstPlatform->setUp(0, WINDOW_HEIGHT - PLATFORM_HEIGHT, PLATFORM_HEIGHT, WINDOW_WIDTH, &GROUND_IMG);
	groundLevel = firstPlatform;

	numPowerUps = 0;
	currentPowerUp = -1;

	actions.initialize();
}

// Main program loop
void ofApp::update()
{
	switch (currentState)
	{
		case GAME_STATES::PLAY:

			gameRound();

			return;

		case GAME_STATES::NEW_GAME:

			generateGame();
			currentState = GAME_STATES::PLAY;

			return;

		case GAME_STATES::FINISHED_GAME:

			setHighScore();
			destroyPlatforms();

			return;
	}
}

// Calls renderer object functions to draw game to screen
void ofApp::draw()
{
	switch (currentState)
	{
		case GAME_STATES::PLAY:
			renderer.displayCanvasView(gamePlayer, firstPlatform, POWER_UP_NUM, buttons[BUTTONS::PAUSE_BUTTON]);
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

// Called when program is exited, deletes dynamic memory that was allocated
void ofApp::exit()
{
	destroyPlatforms();
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
	buttons[BUTTONS::PLAY_BUTTON].setUp(850, 469, 69, 363, &PLAY_BUTTON_IMG);
}

// Generates player information, platforms, power ups, and timer for a game round
// Refer to section 6.6 for game round generation logic
void ofApp::generateGame()
{
	gamePlayer.setUp(PLAYER_STARTING_X, PLAYER_STARTING_Y, PLAYER_HEIGHT, PLAYER_WIDTH, &PLAYER_IMG);

	//timer.setUp();

	generateWinningPath();

	generateExtraPlatforms();

	//generatePowerUps();
}

// Generates the platforms for the winning path with their colour, type (regular or special), and position
// Refer to section 6.11.2 for algorithm
void ofApp::generateWinningPath()
{
	int sectionColours[WINNING_SECTIONS_NUM];
	bool sectionComplete = false;
	int numGenerated = 0;

	Platform* lastGenerated = firstPlatform;

	for (int i = 0; i < WINNING_SECTIONS_NUM - 1; i++)
	{
		sectionColours[i] = randomColour();

		sectionComplete = false;

		while(sectionComplete == false)
		{
			Platform* p = new Platform();

			lastGenerated->setNext(p);
			p->setPrevious(lastGenerated);

			generatePlatforms(p);

			if (p->getPos().y <= WINNING_SECTIONS[i])
			{
				if (i != WINNING_SECTIONS_NUM - 2)
				{
					p->setType(PLATFORMS::SPECIAL);
					p->setUp(p->getPos().x, p->getPos().y, PLATFORM_HEIGHT, PLATFORM_WIDTH, &PLATFORM_IMGS[COLOURS::RAINBOW]);
				}
				else
				{
					p->setType(PLATFORMS::END);
					p->setUp(0, p->getPos().y, PLATFORM_HEIGHT, CANVAS_WIDTH, &GROUND_IMG);
				}
				sectionComplete = true;
			}
			else
			{
				p->setType(PLATFORMS::REGULAR);
				p->setUp(p->getPos().x, p->getPos().y, PLATFORM_HEIGHT, PLATFORM_WIDTH, &PLATFORM_IMGS[sectionColours[i]]);
			}

			lastGenerated = p;
			numGenerated++;
		}
	}
}

// Generates the random extra platforms with their colour, type(regular or special), and position
// Refer to section 6.11.3 for algorithm
void ofApp::generateExtraPlatforms()
{
	bool generationComplete = false;
	Platform* currentPlatform = firstPlatform;

	while (currentPlatform->getNext()->getType() != PLATFORMS::END)
	{
		Platform* p = new Platform();

		p->setNext(currentPlatform->getNext());
		currentPlatform->getNext()->setPrevious(p);

		currentPlatform->setNext(p);
		p->setPrevious(currentPlatform);

		generationComplete = false;

		while (generationComplete == false)
		{
			generatePlatforms(p);
			p->setUp(p->getPos().x, p->getPos().y, PLATFORM_HEIGHT, PLATFORM_WIDTH, NULL);

			if (p->getNext()->isCollided(p) == false)
			{
				generationComplete = true;
			}
		}

		p->setType();

		if (p->getType() == PLATFORMS::REGULAR)
		{
			p->setUp(p->getPos().x, p->getPos().y, PLATFORM_HEIGHT, PLATFORM_WIDTH, &PLATFORM_IMGS[randomColour()]);
		}
		else
		{
			p->setUp(p->getPos().x, p->getPos().y, PLATFORM_HEIGHT, PLATFORM_WIDTH, &PLATFORM_IMGS[COLOURS::RAINBOW]);
		}

		currentPlatform = currentPlatform->getNext()->getNext();
	}
}

// Generates a random y position for the platform based on JUMP_HEIGHT, and a random x position for the platform based on JUMP_WIDTH
// Refer to section 6.11.5 for algorithm
void ofApp::generatePlatforms(Platform* currentPlatform)
{
	Position tempPos; 
	tempPos.initialize();

	// Generating y
	tempPos.y = (int)ofRandom(MIN_PLATFORM_DISTANCE, JUMP_HEIGHT);
	currentPlatform->setY(currentPlatform->getPrevious()->getPos().y - tempPos.y);

	// Generating x
	currentPlatform->setX(-1);

	while (!(currentPlatform->getPos().x >= 0 && currentPlatform->getPos().x <= (CANVAS_WIDTH - PLATFORM_WIDTH)))
	{
		tempPos.x = ofRandom(-JUMP_WIDTH, JUMP_WIDTH);
		currentPlatform->setX(currentPlatform->getPrevious()->getPos().x + tempPos.x);
	}
}

// Generates the power ups with their type (banana or pear) and what platform they are on
void ofApp::generatePowerUps()
{

}

// One loop of game round loop
void ofApp::gameRound()
{
	// listens to user keyboard inputs and moves the player corresponsdingly
	gamePlayer.playerMovement(&actions);
}

// Sets the high score if the parameter high score is higher than the current one
int ofApp::setHighScore()
{
	return 0;
}

// Picks and returns a random colour from COLOURS (RED, ORANGE, YELLOW, GREEN, BLUE, or PURPLE)
int ofApp::randomColour()
{
	return (int)ofRandom(COLOURS::RED, COLOURS::PURPLE + 1);
}

// Destroys all platform objects at the end of a game round
void ofApp::destroyPlatforms()
{
	Platform* p = firstPlatform;
	Platform* temp;

	while (p != NULL)
	{
		temp = p->getNext();

		delete p;

		p = temp;
	}
}
