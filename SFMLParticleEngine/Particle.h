#pragma once
#include "SFML\Graphics.hpp"

class Controller;
class ParticleEmitter;

class Particle
{
public:
	Particle(Controller* controller, ParticleEmitter* emitter);
	void update();
	void draw(sf::RenderWindow* window);
	void printInfo();
	bool isDead = false;
	Controller* controller;
	ParticleEmitter* emitter;
	
private:
	int speed;
	float size;
	sf::Color color;
	sf::CircleShape shape;
	sf::Vector2f direction;
	sf::Vector2f normalizeVector(sf::Vector2f vector);
	bool outOfBounds(sf::Vector2f position);
};