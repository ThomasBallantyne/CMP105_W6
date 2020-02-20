#include "Player.h"

Player::Player()
{
	scale = 20;
	gravity = sf::Vector2f(0,9.8) * scale;
	velocity = sf::Vector2f(0, 0);
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space) && isOnGround)
	{
		velocity = sf::Vector2f(0, -10) * scale;
	}

	if (input->isMouseLDown())
	{
		velocity = sf::Vector2f(0, 0);
		setPosition(input->getMouseX(), input->getMouseY());
	}
}

void Player::update(float dt)
{
	isOnGround = false;
	coord = velocity * dt + (0.5f * gravity * dt * dt);
	velocity += gravity * dt;
	setPosition(getPosition() + coord);

	if (getPosition().y >= 625)
	{
		setPosition(getPosition().x, 625);
		setVelocity(0, 0);
		isOnGround = true;
	}
}