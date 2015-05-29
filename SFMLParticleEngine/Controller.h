#pragma once
#include <vector>
#include "ParticleEmitter.h"
#include "SFML\Graphics.hpp"
#include <random>

class Controller
{
public:
	Controller(sf::RenderWindow* window);
	sf::RenderWindow* window;
	void update();
	void draw();
	int getRandomNumber(int min, int max);
	sf::Font font;
	void Controller::setText(std::string str);

private:
	std::vector<ParticleEmitter*> emitterList;
	std::random_device rd;
	std::mt19937 rng;
	sf::Text text;
};