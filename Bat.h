#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f position; //Holding the position of the bat
	RectangleShape batShape; //To draw the bat

	//Bat speed per frame
	float batSpeed = 0.3f; //number of pixels per frame that bat can move at

public:
	//constructor
	Bat(float startX, float startY); //Where bat object will first appear at start

	FloatRect getPosition(); //Four points which defines a rectangle
	RectangleShape getShape();//returns to batshape in main so it could be drawn.


	void hitSides(); //what if bat hit sides.
	void hitRight();
	
	void moveLeft();
	void moveRight();
	void update(); //once per frame to update the position
};