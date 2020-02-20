#include "Glider.h"

Glider::Glider()
{
	target = sf::Vector2f(1150, 625);
	acceleration = 2;
	scale = 20;
}

Glider::~Glider()
{

}

void Glider::handleInput(float dt)
{
	target = sf::Vector2f(input->getMouseX(), input->getMouseY());
}

void Glider::update(float dt)
{
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration);
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}