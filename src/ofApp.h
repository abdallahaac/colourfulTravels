#pragma once

#define GROUND									// Y position the ground starts
#define POWER_UP_NUM							// Number of power ups in a game round
#define WINNING_SECTIONS_NUM					// Number of colour section the winning path will be split up in
#define MIN_PLATFORM_DISTANCE					// Minimum distance platforms have to be apart
#define PLATFORM_HEIGHT							// Platform’s height
#define PLATFORM_WIDTH							// Platform’s width
#define JUMP_HEIGHT								// Maximum height the player can jump
#define JUMP_WIDTH								// Maximum width the player can jump
#define MAX_TIME								// Amount of time the player has to reach the top

const int WINNING_SECTIONS = {};				// Ending y value of each colour section in the winning path (from bottom to top)

// Enum for the number representation of each state the game can be in
enum GAME_STATES
{
	PAUSE,
	PLAY,
	MAIN_MENU,
	NEW_GAME,
	FINISHED_GAME
};

class ofApp : public ofBaseApp
{
	private:

		// ofImage objects for flyweight design pattern
		ofImage PEAR_IMG = ofImage("");		
		ofImage BANANA_IMG = ofImage("");	
		ofImage PLATFORM_IMGS[7] = { ofImage(""),
									 ofImage(""), 
									 ofImage(""), 
									 ofImage(""), 
									 ofImage(""), 
									 ofImage(""), 
									 ofImage("") };
		ofImage PLAY_BUTTON = ofImage("playButton.png");

		// Program variables
		int currentState;						// Current state of game (takes a value of GAME_STATES)
		int highscore;							// Player highscore of session
		bool won;								// If the player won the current game round
		//Player gamePlayer;					// Player object
		//JumpInfo currentJump;					// JumpInfo structure for storing information about the current player’s jump

		
		Platform* firstPlatform;				// Pointer to first platform in the linked list
		Platform* lastPlatform;					// Pointer to last platform in the linked list
		Platform* finalPlatform;				// Pointer to the last platform in the game round
		Platform* groundLevel;					// Pointer to the platform the player is currently on
		
		//PowerUp* fruits;						// Array of PowerUp object pointers
		int numPowerUps;						// Number of power ups in a game round
		int currentPowerUp;						// If player is currently powered up, will store the index value of the power up, otherwise will store - 1

		GameObject buttons[NUM_BUTTONS];		// Array of GameObject objects for buttons
        Player player;
        JumpInfo* jumpInfo;
        ofImage image;

		//Clock timer;							// Clock object
		Display renderer;						// Display object for drawing to screen
		PlayerAction actions;					// PlayerAction structure for storing player actions to be executed
		Input userInput;						// Input object for handling user input
        

	public:

		// Built-in functions
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
    int dy = 2;

		// Other functions
		void buttonSetUp();
		void generateGame();
		int generateWinningPath();
		void generateExtraPlatforms();
		void generatePlatforms();
		void generatePowerUps();
		void gameRound();
		int setHighScore();
		int randomColour();
		void destroyPlatforms();
};
