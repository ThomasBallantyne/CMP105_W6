#include "Glider.h"

Glider::Glider()
{
	target = sf::Vector2f(1150, 625);
	speed = 200;
	scale = 20;
}

Glider::~Glider()
{

}

void Glider::update(float dt)
{
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity = (direction * speed);
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}