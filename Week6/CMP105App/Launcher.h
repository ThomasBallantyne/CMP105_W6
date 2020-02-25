#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Launcher: public GameObject
{
public:
	Launcher();
	~Launcher();

	void handleInput(float dt) override;
	void update(float dt) override;

protected:

	float scale;
	float speed;
	bool mouseDown;
	bool isOnGround;
	sf::Vector2f coord;
	sf::Vector2f startPos;
	sf::Vector2f endPos;
	sf::Vector2f displacement;
	sf::Vector2f direction;
	sf::Vector2f velocity;
	sf::Vector2f gravity;
};