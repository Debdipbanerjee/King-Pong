#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Ball 
{
private:
	Vector2f position; //Holding the position of the ball
	RectangleShape ballShape; //To draw the ball

	//To represent Horizontal & Vertical Speeds of the ball
	float xVelocity = 0.2f;
	float yVelocity = 0.2f;

public:
	//constructor
	Ball(float startX, float startY); //Where ball object will first appear at start

	FloatRect getPosition(); //Four points which defines a rectangle object
	RectangleShape getShape();//returns to ballshape in main so it could be drawn.

	float getXVelocity(); //getter function which will return the value of some private data to the calling code.

	void reboundSides(); //What happens when the ball hits the side of the screen?
	void reboundBatOrTop(); //What happens when the ball hits the bat or the top of the screen?
	void hitBottom(); //What happens when the ball hits the bottom of the screen?

	void update(); //once per frame to update the position
};