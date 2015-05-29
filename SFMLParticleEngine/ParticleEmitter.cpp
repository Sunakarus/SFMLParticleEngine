#include "stdafx.h"
#include "ParticleEmitter.h"
#include "Controller.h"
#include <iostream>
#include <cmath>

ParticleEmitter::ParticleEmitter(Controller* controller)
{
	this->controller = controller;
	position = sf::Vector2f(controller->window->getSize().x / 2, controller->window->getSize().y / 2);
	for (int i = 0; i < 5; i++)
	{
		emitParticle();
	}
}

void ParticleEmitter::emitParticle()
{
	particleList.push_back(new Particle(controller, this));
}

void ParticleEmitter::printInfo()
{
	if (!particleList.empty()){
		for (int i = 0; i < particleList.size(); i++)
		{
			std::cout << i+1 << ") ";
			particleList[i]->printInfo();
		}
		std::cout << "------------------------\n";
	}
}

void ParticleEmitter::update()
{
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() >= 1.0 / partsPerSecond)
	{
		int partsToSpawn = std::round(partsPerSecond / 60); //60 = FPS
		for (int i = 0; i < partsToSpawn; i++)
		{
			emitParticle();
		}
		clock.restart();
	}


	if (!particleList.empty()){
		for (int i = particleList.size()-1; i > -1; i--)
		{
			particleList[i]->update();
			if (particleList[i]->isDead)
			{
				delete particleList[i];
				particleList.erase(particleList.begin()+i);
			}
		}
	}

	controller->setText("Particle count: " + std::to_string(particleList.size()) + "\nParticles per frame: " + std::to_string(std::round(partsPerSecond / 60)));
}

void ParticleEmitter::draw(sf::RenderWindow* window)
{
	if (!particleList.empty()){
		for (int i = 0; i < particleList.size(); i++)
		{
			particleList[i]->draw(window);
		}
	}

}