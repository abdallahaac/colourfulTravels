// Class that stores information about platforms (child class of GameObject)

#pragma once

class Platform : public GameObject
{
	private:
		int type;					// Type of power up the object is (Takes a value from PLATFORMS)
		bool landedOn;				// If player has landed on the object
		int colour;					// Colour of platform (Takes a value from COLOURS)

	public:
		// Constructors
		Platform();

		// Get methods
		int getType();
		int getColour();

		// Set methods
		void setType();
		void setType(int newType);
		void setColour(int newColour);

		// Other functions
		bool isCollided();
		bool isLandedOn();
		void landed();
};
