#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	//giving the PUBLIC start position values to PRIVATE position
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(10, 10)); //Selecting the size of the ball
	ballShape.setPosition(position); //initializing the start position.
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();//returns a floatrect that gives co-ordinates of four corners
}

RectangleShape Ball::getShape()
{
	return ballShape; //to use in main func to draw the Bat
}

float Ball::getXVelocity()
{
	return xVelocity; //return the xVelocity.
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity; //changeing the horizontal velocity so that ball will go to opposite direction
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30); //alter the y position to prevent ball to stuck on the Bat.
	yVelocity = -yVelocity; // reverse the direction of the ball
}

void Ball::hitBottom()
{
	position.y = 1; //sets the ball at the top of the screen
	position.x = 500; //sets the ball at the middle of the screen
}

void Ball::update()
{
	//updating the ball position in each frame according to the ball speed
	position.y += yVelocity;
	position.x += xVelocity;

	//move the ball
	ballShape.setPosition(position);
}








