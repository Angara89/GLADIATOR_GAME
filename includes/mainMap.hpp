#pragma once
#include "../includes/game.hpp"
#include "../includes/cell.hpp"
struct Coord
{
	int x;
	int y;
};
class MainMap {
public:
	friend class InitObjects;
	MainMap() = default;
	void update();

	inline void set_game(Game* g) {
		myGame = g;
		int side = std::max(g->get_size().x, g->get_size().y);
		mapSize = sf::Vector2i(side, side);
	}
	inline void set_count_in_w_h(int w, int h) {
		cellCountInWidth = w;
		cellCountInHeight = h;
	}
	inline int get_count_in_w() {
		return cellCountInWidth;
	}
	inline int get_count_in_h() {
		return cellCountInHeight;
	}
private:
	int cellCountInWidth;
	int cellCountInHeight;
	//sf::Vector2i cellSize;
	sf::Vector2i mapSize;
	Game* myGame;
	std::vector<std::vector<Cell*>> cells;
	sf::Sprite* sprite;
	Coord viewCenter;
	int countWidthInCells;


};