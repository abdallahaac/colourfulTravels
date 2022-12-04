// Class for drawing to user

#pragma once

class Display
{
	private:
		ofImage gameBackground = ofImage("gameBackground.png");
		ofImage mainMenuBackground = ofImage("mainMenuBackground.png");
		ofImage pausedMenuBackground = ofImage("");
		ofImage endGameBackground = ofImage("");
		
		// Private functions
		void displayGameObject();

	public:
		// Constructors
		Display();

		// Other Functions
		void displayCanvasView();
		void displayMainMenu(GameObject playButton, int highscore);
		void displayPausedMenu();
		void displayEndGame();
        void displayGameObject(GameObject gameObject);
};
