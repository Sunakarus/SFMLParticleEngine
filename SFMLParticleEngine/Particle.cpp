#include "stdafx.h"
#include "Particle.h"
#include <iostream>
#include <random>
#include "Controller.h"
#include "ParticleEmitter.h"
#include <cmath>

Particle::Particle(Controller* controller, ParticleEmitter* emitter)
{
	this->controller = controller;
	this->emitter = emitter;
	ParticleSettings p = emitter->partSettings;
	speed = p.partSpeed + controller->getRandomNumber(-p.partSpeedVariation, p.partSpeedVariation);
	size = p.partSize + controller->getRandomNumber(-p.partSizeVariation, p.partSizeVariation);
	color = sf::Color::Color(255, controller->getRandomNumber(0,255), controller->getRandomNumber(0,255), controller->getRandomNumber(100,150));
	shape = sf::CircleShape(size);
	shape.setFillColor(color);
	shape.setPosition(emitter->position.x + controller->getRandomNumber(-p.emitterRadius, p.emitterRadius-size*2), emitter->position.y + controller->getRandomNumber(-p.emitterRadius, p.emitterRadius-size*2));
	direction = sf::Vector2f(controller->getRandomNumber(-10, 10), -10);
	direction = normalizeVector(direction);
}

sf::Vector2f Particle::normalizeVector(sf::Vector2f vector)
{
	float length = std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
	return sf::Vector2f(vector.x / length, vector.y / length);
}

void Particle::printInfo()
{
	std::cout << "Speed: " << speed << ", Size: " << size << ", dead: "<<isDead<<std::endl;
}

bool Particle::outOfBounds(sf::Vector2f position)
{
	return (position.x > controller->window->getSize().x ||
		position.x < -(size*2) ||
		position.y > controller->window->getSize().y ||
		position.y < -(size*2));
}

void Particle::update()
{
	shape.move(direction.x*speed, direction.y*speed);
	isDead = outOfBounds(shape.getPosition());
}

void Particle::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}