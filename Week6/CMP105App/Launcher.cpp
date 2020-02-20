#include "Launcher.h"

Launcher::Launcher()
{
	scale = 200;
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
		startPos = getPosition();
		mouseDown = true;
	}
	else if ((input->isMouseLDown()==false) && (mouseDown == true))
	{
		endPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		displacement = Vector::normalise(endPos - startPos);
		mouseDown = false;
	}

}

void Launcher::update(float dt)
{
	isOnGround = false;
	coord = velocity * dt + (0.5f * gravity * dt * dt) + displacement;
	velocity += gravity * dt;
	setPosition(getPosition() + coord);

	if (getPosition().y >= 625)
	{
		setPosition(getPosition().x, 625);
		setVelocity(0, 0);
		isOnGround = true;
	}
}