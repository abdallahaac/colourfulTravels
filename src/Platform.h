// Class that stores information about platforms (child class of GameObject)

#pragma once


class Platform : public GameObject
{
	private:
		int type;					// Type of power up the object is (Takes a value from PLATFORMS)
		bool landedOn;				// If player has landed on the object
		int colour;					// Colour of platform (Takes a value from COLOURS)
		Platform* next;				// Pointer to the platform object in front of the current one
		Platform* previous;			// Pointer to the platform object behind of the current one

	public:
		// Constructors
		Platform();

		// Get methods
		int getType();
		int getColour();
		Platform* getNext();
		Platform* getPrevious();
    
    
       

		// Set methods
		void setType();
		void setType(int newType);
		void setColour(int newColour);
		void setNext(Platform* nextPlatform);
		void setPrevious(Platform* previousPlatform);
        
    
		// Other functions
		bool isCollided(GameObject* object);
		bool isLandedOn();
		void landed();
    

};
