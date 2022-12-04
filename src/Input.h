// Class for handling user input

#pragma once

#define UP_KEY 119									// What key is up in the game (W)
#define RIGHT_KEY 100								// What key is right in the game (D)
#define LEFT_KEY 97									// What key is left in the game (A)
#define MOUSE_BUTTON 0								// What mouse button is used for clicking in the game (left)

class Input
{
	private:
		GameObject buttons[NUM_BUTTONS];			// Array of GameObject objects for buttons

		// Private functions
		bool checkButtonPress(GameObject button, int xClick, int yClick);

	public:
		// Constructors
		Input();

		// Set methods
		void setButtons(GameObject gameButtons[NUM_BUTTONS]);

		// Other functions
		void keyPress(PlayerAction* actions, int key);
		void keyRelease(PlayerAction* actions, int key);
		int mousePress(int x, int y, int button, int gameState);
};
