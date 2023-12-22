#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
public:

	Game(int w, int h);
	~Game();

	void run();

private:
	sf::RenderWindow* mainWindow;
	int width;
	int height;
	


	void gameLoop();
	void processEvents();
	void update();
	void render();
};

