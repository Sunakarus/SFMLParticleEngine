#include "stdafx.h"
#include "Controller.h"
#include <random>

Controller::Controller(sf::RenderWindow* window)
{
	font.loadFromFile("OpenSans-Regular.ttf");
	this->window = window;
	emitterList.push_back(new ParticleEmitter(this));
	std::random_device rd;
	std::mt19937 rng(rd());

	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(16);
	text.setString("");
}

int Controller::getRandomNumber(int min, int max)
{
	std::uniform_int_distribution<int> uni(min, max);

	return uni(rng);
}

void Controller::update()
{
	if (!emitterList.empty()){
		for (int i = 0; i < emitterList.size(); i++)
		{
			emitterList[i]->update();
		}
	}
}

void Controller::setText(std::string str)
{
	text.setString(str);
}

void Controller::draw()
{
	

	if (!emitterList.empty()){
		for (int i = 0; i < emitterList.size(); i++)
		{
			emitterList[i]->draw(window);
		}
	}

	window->draw(text);
}