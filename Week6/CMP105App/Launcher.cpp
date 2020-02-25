#include "Launcher.h"
#include <iostream>

Launcher::Launcher()
{
	scale = 100;
	speed = 20;
	gravity = sf::Vector2f(0, 9.8) * scale;
	displacement == sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
}
#
Launcher::~Launcher()
{

}

void Launcher::handleInput(float dt)
{
	if ((input->isMouseLDown()) && (mouseDown == false)) {
		startPos = sf::Vector2f(input->getMouseX(),input->getMouseY());
		//std::cout << startPos.x << ", " << startPos.y << "\n";
		mouseDown = true;
	}
	else if ((input->isMouseLDown()==false) && (mouseDown == true))
	{
		endPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		//std::cout << endPos.x << ", " << endPos.y << "\n";
		displacement = -(endPos - startPos);
		velocity += (displacement * 3.f);
		std::cout << velocity.x << ", " << velocity.y;
		//std::cout << displacement.x << ", " << displacement.y << "\n";
		mouseDown = false;
	}

}

void Launcher::update(float dt)
{
	isOnGround = false;
	coord = velocity * dt + (0.5f * gravity * dt * dt);
	//std::cout << coord.x << ", " << coord.y << "\n";
	velocity.x -= 250 * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + coord);

	if (getPosition().y >= 625)
	{
		setPosition(getPosition().x, 625);
		velocity = sf::Vector2f(0, 0);
		isOnGround = true;
	}
}