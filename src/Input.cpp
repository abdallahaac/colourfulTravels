// Function delcarations for Input class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, empty as there are no member variables that need to be initialized
Input::Input()
{

}

// Private functions **************************************************************************************************************************************

// Checks if the user clicked the button, returns true if yes
bool Input::checkButtonPress(GameObject button, int xClick, int yClick)
{
	// Checking xClick by the minimum x value the button can be
	if (xClick >= button.getPos().x)
	{
		// Checking xClick by the maximum x value the button can be
		if (xClick <= (button.getPos().x + button.getWidth()))
		{
			// Checking yClick by the minimum y value the button can be
			if (yClick >= button.getPos().y)
			{
				// Checking yClick by the maximum y value the button can be
				if (yClick <= (button.getPos().y + button.getHeight()))
				{
					// If made it to here, button was clicked on
					return true;
				}
			}
		}
	}

	return false;
}

// Set methods ********************************************************************************************************************************************

// Sets the buttons GameObject array (variable is private)
void Input::setButtons(GameObject gameButtons[NUM_BUTTONS])
{
	for (int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons[i] = gameButtons[i];
	}
}

// Other functions ****************************************************************************************************************************************

// Decides what the player is doing based on the key that was pressed
// Takes a pointer to a PlayerAction struct and updates it accordingly
void Input::keyPress(PlayerAction* actions, int key)
{
	switch (key)
	{
		case UP_KEY:
			actions->jump = true;
			return;

		case RIGHT_KEY:
			actions->right = true;
			return;

		case LEFT_KEY:
			actions->left = true;
			return;
	}
}

// Decides what the player is doing based on the key that was released
// Takes a pointer to a PlayerAction struct and updates it accordingly
void Input::keyRelease(PlayerAction* actions, int key)
{
	// (No JUMP_KEY case because even if the player releases the key, they still may be in the air)

	switch (key)
	{
		case RIGHT_KEY:
			actions->right = false;
			return;

		case LEFT_KEY:
			actions->left = false;
			return;
        case UP_KEY:
            actions->right = false;
            return;


	}
}

// Decides what state the game is in based on what was clicked and returns it
// Refer to section 6.4 of Project Design Document for game state transitions
int Input::mousePress(int x, int y, int button, int gameState)
{
	if (button == MOUSE_BUTTON)
	{
		if (gameState == GAME_STATES::PLAY)
		{
			if (checkButtonPress(buttons[BUTTONS::PAUSE_BUTTON], x, y))
			{
				return GAME_STATES::PAUSE;
			}
			else
			{
				return gameState;
			}
		}
		else if (gameState == GAME_STATES::PAUSE)
		{
			if (checkButtonPress(buttons[BUTTONS::RESUME_BUTTON], x, y))
			{
				return GAME_STATES::PLAY;
			}
			else if (checkButtonPress(buttons[BUTTONS::RESTART_BUTTON], x, y))
			{
				return GAME_STATES::NEW_GAME;
			}
			else if (checkButtonPress(buttons[BUTTONS::MAIN_MENU_BUTTON], x, y))
			{
				return GAME_STATES::MAIN_MENU;
			}
			else
			{
				return gameState;
			}
		}
		else if (gameState == GAME_STATES::MAIN_MENU)
		{
			if (checkButtonPress(buttons[BUTTONS::PLAY_BUTTON], x, y))
			{
				return GAME_STATES::NEW_GAME;
			}
			else
			{
				return gameState;
			}
		}
		else if (gameState == GAME_STATES::FINISHED_GAME)
		{
			if (checkButtonPress(buttons[BUTTONS::PLAY_AGAIN_BUTTON], x, y))
			{
				return GAME_STATES::NEW_GAME;
			}
			else if (checkButtonPress(buttons[BUTTONS::MAIN_MENU_BUTTON], x, y))
			{
				return GAME_STATES::MAIN_MENU;
			}
			else
			{
				return gameState;
			}
		}
	}
}
