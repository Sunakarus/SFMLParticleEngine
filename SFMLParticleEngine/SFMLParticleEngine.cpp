// SFMLParticleEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include <string>
#include <cmath>

const double FPS = 60.0;

void update(Controller* controller)
{
	controller->update();
}

void draw(Controller* controller)
{
	controller->draw();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Particle Engine");
	Controller controller(&window);
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() >= 1.0 / FPS)
		{
			update(&controller);
			window.setTitle("FPS: " + std::to_string(std::round(1.0 / elapsed.asSeconds())));
			clock.restart();
		}

		window.clear();
		draw(&controller);
		window.display();
	}

	return 0;
}