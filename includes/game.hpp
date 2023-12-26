#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <list>
#include "../includes/InitObjects.hpp"

class Game
{
public:

	Game(int w, int h);
	~Game();

	void run();
	inline void add_layer(sf::Sprite* s) {
		layers.push_back(s);
	}
	inline const sf::Vector2i& get_size() {
		return size;
	}
private:
	sf::RenderWindow* mainWindow;
	std::list<sf::Sprite*> layers;
	sf::Vector2i size;
	

	void gameLoop();
	void processEvents();
	void update();
	void render();
};

