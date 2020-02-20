#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Glider: public GameObject
{
public:
	Glider();
	~Glider();

	void update(float dt) override;

protected:

	float acceleration;
	float scale;
	sf::Vector2f velocity;
	sf::Vector2f direction;
	sf::Vector2f target;
};

