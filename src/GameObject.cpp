// Function delcarations for GameObject class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, initialises members to default values
GameObject::GameObject()
{
	pos.initialize();
	width = 0;;
	height = 0;
	image = NULL;
}

// Get methods ********************************************************************************************************************************************

// Returns the position of the object (variable is private)
Position GameObject::getPos()
{
	return pos;
}


// Returns the height of the object (variable is private)
int GameObject::getHeight()
{
	return height;
}

// Returns the width of the object (variable is private)
int GameObject::getWidth()
{
	return width;
}


// Returns the pointer to ofImage object of the object (variable is private)
ofImage* GameObject::getImage()
{
	return image;
}

// Set methods

// Sets the x position of the object (variable is private)
void GameObject::setX(int x)
{
	pos.x = x;
}

// Sets the y position of the object (variable is private)
void GameObject::setY(int y)
{
	pos.y = y;
}

// Other functions ****************************************************************************************************************************************

// Takes parameters to initialise member variables
void GameObject::setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage)
{
	pos.x = startingX;
	pos.y = startingY;

	height = objectHeight;
	width = objectWidth;

	image = objectImage;
}
