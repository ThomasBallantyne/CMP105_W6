#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture1.loadFromFile("gfx/Goomba.png");

	player1.setTexture(&texture1);
	player1.setSize(sf::Vector2f(50, 50));
	player1.setPosition(sf::Vector2f(200, 100));
	player1.setInput(input);

	glider1.setTexture(&texture1);
	glider1.setSize(sf::Vector2f(50, 50));
	glider1.setPosition(sf::Vector2f(0, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player1.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player1.update(dt);
	glider1.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player1);
	window->draw(glider1);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}