// Class that stores information about a general game object

#pragma once

class GameObject
{
	protected:
		Position pos;				// Coordinate position of object
		int width;					// Width of object
		int height;					// Height of object
		ofImage* image;				// Pointer to image of object

	public:
		// Constructors
		GameObject();

		// Get methods
		Position getPos();
		int getHeight();
		int getWidth();
		ofImage* getImage();

		// Set methods
		void setX(int x);
		void setY(int y);
        virtual void setUp(int startingX, int startingY, int objectHeight, int objectWidth, ofImage* objectImage);
};
