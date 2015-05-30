#pragma once
#include <vector>
#include "Particle.h"
#include "SFML\Graphics.hpp"
#include "ParticleSettings.h"

class Controller;
struct ParticleSettings;

class ParticleEmitter
{
public:
	ParticleEmitter(Controller* controller);
	void update();
	void draw(sf::RenderWindow* window);
	sf::Vector2f position;
	Controller* controller;
	ParticleSettings partSettings;

private:
	std::vector<Particle*> particleList;
	sf::Clock clock;

	void printInfo();
	void emitParticle();
};

