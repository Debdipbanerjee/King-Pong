/*
Made By Debdip Banerjee on December 8th,2019- December 15th,2019
*/

/*
Possible Upgrades:
-Collision problem with Right side wall and Bat.(Done)
-Change color of Bat & Ball.
-Make the game 2 Player.
- Change the HUD font Style.
*/

#include <iostream>
#include"Ball.h"
#include"Bat.h"
#include<sstream>
#include<cstdlib>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;
	//making a window 1024 by 768 with title pong
	RenderWindow window(VideoMode(windowWidth, windowHeight),"King Pong");

	//Player score & lives
	int score = 0;
	int lives = 3;

	//Creating a Bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	//creating a Ball
	Ball ball(windowWidth / 2, 1);

	//Creating HUD
	Text hud;
	
	//choosing a font
	Font font;
	font.loadFromFile("coolvetica rg.ttf");

	//Setting the font to hud
	hud.setFont(font);

	//Size
	hud.setCharacterSize(60);

	//color
	hud.setFillColor(sf::Color::White);

//Game Loop

	while (window.isOpen())
	{

		//*******Handle Player Input********
		Event event;
		while (window.pollEvent(event))
		{
			//close the window
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		//move left
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		//move right
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		//eascape key
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//*******update frame*******

		//ball hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			//reverse the ball direction
			ball.hitBottom();

			//remove a life
			lives--;

			//check for 0 lives
			if (lives < 1)
			{
				//reset the score
				score = 0;
				//reset the live
				lives = 3;
			}
		}

		//ball hitting the top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			
		}

		//ball hitting the sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		//ball hitting the bat
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			ball.reboundBatOrTop();

			//add a point to score
			score++;
		}

		//Bat hits sides
		if (bat.getPosition().left < 0 )
		{
			bat.hitSides();
		}
		else if (bat.getPosition().left + 80 > windowWidth )
		{
			bat.hitRight();
			bat.hitSides();
		}

		//********Update frame******
		ball.update();
		bat.update();

		//update the HUD text
		std::stringstream ss;
		ss << "Score:" << score << " Lives:" << lives;
		hud.setString(ss.str());

		//**********Draw the frame**********

		//clear everything from last frame
		window.clear(Color(72, 61, 139, 255));

		//draw the bat
		window.draw(bat.getShape());

		//draw the ball
		window.draw(ball.getShape());

		//draw the score
		window.draw(hud);

		//show everything
		window.display();
	}

	return 0;
}