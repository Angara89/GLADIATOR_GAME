#include "../includes/game.hpp"

Game::Game(int w, int h)
	: size(w, h)
{
	this->mainWindow = new sf::RenderWindow(sf::VideoMode(w, h), "Gladiator");
}

Game::~Game()
{
	delete this->mainWindow;
}

void Game::run()
{
	gameLoop();
}

void Game::gameLoop()
{
	while (mainWindow->isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mainWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mainWindow->close();
		}
	}
}

void Game::update()
{
	return;
}

void Game::render()
{
	mainWindow->clear();
	for (auto pS : this->layers) {
		mainWindow->draw(*pS);
	}
	mainWindow->display();
}
