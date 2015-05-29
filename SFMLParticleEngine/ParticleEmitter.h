#pragma once
#include <vector>
#include "Particle.h"
#include "SFML\Graphics.hpp"

class Controller;

class ParticleEmitter
{
public:
	ParticleEmitter(Controller* controller);
	void update();
	void draw(sf::RenderWindow* window);
	int radius = 100;
	int partsPerSecond = 10000;
	sf::Vector2f position;
	Controller* controller;

private:
	std::vector<Particle*> particleList;
	sf::Clock clock;

	void printInfo();
	void emitParticle();
};

