// Function delcarations for Platform class

#include "Main.h"

// Constructors *******************************************************************************************************************************************

// Class constructor, initialises members to default values
Platform::Platform()
{

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

// Set methods

// (Overload 1) Sets object to of random type (variable is private)
void Platform::setType()
{

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

// Other functions

// Checks if player has collided with platform object
bool Platform::isCollided()
{
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