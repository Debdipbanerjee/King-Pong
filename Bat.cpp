#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	//giving the PUBLIC start position values to PRIVATE position
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(80, 10)); //Selecting the size of the bat
	batShape.setPosition(position); //initializing the start position.
}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds(); //returns a floatrect that gives co-ordinates of four corners
}

RectangleShape Bat::getShape()
{
	return batShape; //to use in main func to draw the Bat
}

void Bat::moveLeft()
{
	position.x -= batSpeed; // going left; 
}

void Bat::moveRight()
{
	position.x += batSpeed; // going Right; 
}

void Bat::update()
{
	batShape.setPosition(position); //set the bat at initial positions.
}

void Bat::hitSides()
{
	position.x = -position.x;
}

void Bat::hitRight()
{
	for (int i = 1024; i > 1022; i--)
	{
		position.y;
		position.x--;
	}
}


