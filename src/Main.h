// Header information

#pragma once

#define WINDOW_HEIGHT 800			// Game window height
#define WINDOW_WIDTH 1400			// Game window width
#define CANVAS_HEIGHT				// Game canvas height
#define CANVAS_WIDTH				// Game canvas width
#define FRAME_RATE 60				// Game frame rate
#define NUM_COLOURS 6				// Number of colours in the game
#define NUM_BUTTONS	6				// Number of buttons in the game

// Storing a coordinate position of an object on screen
struct Position
{
	int x;
	int y;

	void initialize()
	{
		x = 0;
		y = 0;
	}
};

// Structure for storing player actions to execute
struct PlayerAction
{
	bool left;
	bool right;
	bool jump;

	void initialize()
	{
		left = false;
		right = false;
		jump = false;
	}
};

// Enum for the number representation of each power up
enum POWERUPS
{
	PEAR,
	BANANA
};

// Enum for the number representation of each platform
enum PLATOFORMS
{
	REGULAR,
	SPECIAL,
	GROUND,
	END
};

// Enum for the number representation of each colour
enum COLOURS
{
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	RAINBOW
};

// Enum for the number representation of each button in the game
enum BUTTONS
{
	PLAY_BUTTON,
	PAUSE_BUTTON,
	RESTART_BUTTON,
	MAIN_MENU_BUTTON,
	PLAY_AGAIN_BUTTON,
	RESUME_BUTTON
};
struct JumpInfo
{
    int y,x,dy,dx,time;
};

#include "ofMain.h"
#include "GameObject.h"
#include "Input.h"
#include "Player.h"
//#include "PowerUps.h"
//#include "Pear.h"
#include "Platform.h"
//#include "Clock.h"

#include "Display.h"

#include "ofApp.h"