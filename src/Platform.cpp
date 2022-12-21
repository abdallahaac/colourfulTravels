// Function delcarations for Platform class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, initialises members to default values
Platform::Platform()
{
	type = 0;
	landedOn = false;
	colour = 0;
	next = NULL;
	previous = NULL;
}

// Get methods

// Returns the platform type (variable is private)
int Platform::getType()
{
	return type;
}

// Returns the colour of the object (variable is private)
int Platform::getColour()
{
	return colour;
}

// Returns a pointer to the platform object in front of the current one (variable is private)
Platform* Platform::getNext()
{
	return next;
}

// Returns a pointer to the platform object behind of the current one (variable is private)
Platform* Platform::getPrevious()
{
	return previous;
}

// Set methods

// (Overload 1) Sets object to of random type (variable is private)
void Platform::setType()
{
	// Choosing the type by randomizing a colour to create a 6/7 chance of regular type and 1/6 chance of special type
	type = (int)ofRandom(COLOURS::RED, COLOURS::RAINBOW + 1);

	if (type >= COLOURS::RED && type <= COLOURS::PURPLE)
	{
		type = PLATFORMS::REGULAR;
	}
	else
	{
		type = PLATFORMS::SPECIAL;
	}
}


// (Overload 2) Sets object to of inputted type (variable is private)
void Platform::setType(int newType)
{
	type = newType;
}

// Sets the colour of the object (variable is private)
void Platform::setColour(int newColour)
{
	colour = newColour;
}

// Sets the pointer to the platform object in front of the current one
void Platform::setNext(Platform* nextPlatform)
{
	next = nextPlatform;
}

// Sets the pointer to the platform object behind of the current one
void Platform::setPrevious(Platform* previousPlatform)
{
	previous = previousPlatform;
}

// Other functions

// Checks if player has collided with platform object
bool Platform::isCollided(GameObject* object)
{
	// Checking playerX by the minimum x value the platform can be
	if ((object->getPos().x + object->getWidth()) >= pos.x)
	{
		// Checking playerX by the maximum x value the platform can be
		if (object->getPos().x <= (pos.x + width))
		{
			// Checking playerY by the minimum y value the platform can be
			if ((object->getPos().y + object->getHeight()) >= pos.y)
			{
				// Checking playerY by the maximum y value the platform can be
				if (object->getPos().y <= (pos.y + height))
				{
					// If made it to here, platform was collided with
					return true;
				}
			}
		}
	}

	return false;
}

// Checks if player has already landed on platform object
bool Platform::isLandedOn()
{
	return landedOn;
}

// Sets isLandedOn to true
void Platform::landed()
{
	landedOn = true;
}
