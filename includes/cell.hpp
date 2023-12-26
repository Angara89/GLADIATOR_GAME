#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <list>
#include "../includes/Object.hpp"

class Cell {
public:
	void update();
	Cell();
	inline void set_render_texture(sf::RenderTexture* rt)
	{
		background = rt;
	}
private:
	static sf::Vector2i size;
	std::list<Object*> objects;
	sf::Sprite* sprite;
	sf::RenderTexture* background;
	bool isChange;
	void draw();
};