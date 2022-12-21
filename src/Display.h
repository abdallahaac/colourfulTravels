// Class for drawing to user

#pragma once

class Display
{
	private:
		ofImage gameBackground = ofImage("gameBackground.png");
		ofImage mainMenuBackground = ofImage("mainMenuBackground.png");
		ofImage pausedMenuBackground = ofImage("pausedBackground.png");
		ofImage wonBackground = ofImage("wonBackground.png");
		ofImage lostBackground = ofImage("lostBackground.png");
		
		// Private functions
		void displayGameObject(GameObject toDisplay);

	public:
		// Constructors
		Display();
    
		// Other Functions
		void displayCanvasView(Player player, Platform* firstPlatform, /*PowerUp fruit[],*/ int numPowerUps, /*Clock timer,*/ GameObject pauseButton);
		void displayMainMenu(GameObject playButton, int highscore);
		void displayPausedMenu(GameObject resumeButton, GameObject restartButton, GameObject mainMenuButton);
		void displayEndGame(GameObject mainMenuButton, GameObject playAgainButton, bool won, int score);
};
