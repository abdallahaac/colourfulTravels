#pragma once


#define POWER_UP_NUM 20							// Number of power ups in a game round
#define WINNING_SECTIONS_NUM 6					// Number of colour section the winning path will be split up in
#define MIN_PLATFORM_DISTANCE 90				// Minimum distance platforms have to be apart (y)
#define PLATFORM_WIDTH 150						// Platform’s width
#define JUMP_HEIGHT	200							// Maximum height the player can jump
#define JUMP_WIDTH 450							// Maximum width the player can jump
#define MAX_TIME								// Amount of time the player has to reach the top


// Ending y value of each colour section in the winning path (from bottom to top)
const int WINNING_SECTIONS[WINNING_SECTIONS_NUM] = {0, -800, -1600, -2400, -3200, -4000};

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
		ofImage PLATFORM_IMGS[7] = { ofImage("redPlatform.png"),
									 ofImage("orangePlatform.png"), 
									 ofImage("yellowPlatform.png"), 
									 ofImage("greenPlatform.png"), 
									 ofImage("bluePlatform.png"), 
									 ofImage("purplePlatform.png"), 
									 ofImage("specialPlatform.png") };
		ofImage GROUND_IMG = ofImage("ground.png");
		ofImage PLAYER_IMG = ofImage("loop.png");	
		ofImage PLAY_BUTTON_IMG = ofImage("playButton.png");
		ofImage PAUSE_BUTTON_IMG = ofImage("pauseButton.png");
		ofImage RESTART_BUTTON_IMG = ofImage("restartButton.png");
		ofImage MAIN_MENU_BUTTON_IMG = ofImage("mainMenuButton.png");
		ofImage PLAY_AGAIN_BUTTON_IMG = ofImage("playAgainButton.png");
		ofImage RESUME_BUTTON_IMG = ofImage("resumeButton.png");
    
     
    
        float previousTime, currentTime;
        ofColor backgroundColour;
          

		// Program variables
		int currentState;						// Current state of game (takes a value of GAME_STATES)
		int highscore;							// Player highscore of session
		bool won;								// If the player won the current game round
		Player gamePlayer;						// Player object
		JumpInfo currentJump;					// JumpInfo structure for storing information about the current player’s jump

		
		Platform* firstPlatform;				// Pointer to first platform in the linked list
		Platform* groundLevel;					// Pointer to the platform the player is currently on
		
		//PowerUp* fruits;						// Array of PowerUp object pointers
		int numPowerUps;						// Number of power ups in a game round
		int currentPowerUp;						// If player is currently powered up, will store the index value of the power up, otherwise will store - 1

		GameObject buttons[NUM_BUTTONS];		// Array of GameObject objects for buttons

		Clock timer;							// Clock object
		Display renderer;						// Display object for drawing to screen
		PlayerAction actions;					// PlayerAction structure for storing player actions to be executed
		Input userInput;						// Input object for handling user input
     

	public:

    
		// Built-in functions
		void setup();
		void update();
		void draw();
		void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);

		// Other functions
		void buttonSetUp();
		void generateGame();
		void generateWinningPath();
		void generateExtraPlatforms();
		void generatePlatforms(Platform* currentPlatform);
		void generatePowerUps();
		void gameRound();
		int setHighScore();
		int randomColour();
		void destroyPlatforms();
    
    
    // added function abdallah
    void timerSetUp();
};
