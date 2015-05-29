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
	speed = controller->getRandomNumber(4,6);
	size = controller->getRandomNumber(30,50);
	color = sf::Color::Color(255, controller->getRandomNumber(0,255), controller->getRandomNumber(0,255), controller->getRandomNumber(100,150));
	shape = sf::CircleShape(size);
	shape.setFillColor(color);
	shape.setPosition(emitter->position.x + controller->getRandomNumber(-emitter->radius, emitter->radius), emitter->position.y + controller->getRandomNumber(-emitter->radius, emitter->radius));
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
	return (position.x > controller->window->getSize().x + size ||
		position.x < -size ||
		position.y > controller->window->getSize().y + size ||
		position.y < -size);
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