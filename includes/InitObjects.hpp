#pragma once
#include "../includes/game.hpp"
#include "../includes/mainMap.hpp"
#include "../includes/cell.hpp"
#include "../includes/Ui.hpp"
#include "../lib/tinyxml2-master/tinyxml2.h"
#include <iostream>

class InitObjects
{
public:
	Game* init_game() {
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLError eResult = doc.LoadFile("../assets/config.xml");
		if (eResult != tinyxml2::XML_SUCCESS) {
			std::cout << "Ошибка загрузки файла" << std::endl;
			return nullptr;
		}

		tinyxml2::XMLNode* pRoot = doc.FirstChildElement("config");
		if (pRoot == nullptr) {
			std::cout << "Ошибка нахождения корневого элемента" << std::endl;
			return nullptr;
		}
		int w, h;

		tinyxml2::XMLElement* pRes = pRoot->FirstChildElement("resolution");
		w = pRes->IntAttribute("width");
		h = pRes->IntAttribute("height");
		Game* game = new Game(w, h);
		return game;
	}
	//int delete_game();
	int init_level(std::string s, Game* game) {
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLError eResult = doc.LoadFile("../assets/levels.xml");
		if (eResult != tinyxml2::XML_SUCCESS) {
			std::cout << "Ошибка загрузки файла" << std::endl;
			return -1;
		}

		tinyxml2::XMLNode* pRoot = doc.FirstChildElement("levels_");
		if (pRoot == nullptr) {
			std::cout << "Ошибка нахождения корневого элемента" << std::endl;
			return -1;
		}

		tinyxml2::XMLElement* pLevelElement = pRoot->FirstChildElement("levels")->FirstChildElement(s.c_str());
		
		MainMap* map = new MainMap();
		map->set_game(game);
		map->set_count_in_w_h((int)pLevelElement->FirstChildElement("size")->Attribute("cells_in_width"),
							  (int)pLevelElement->FirstChildElement("size")->Attribute("cells_in_height"));
		
		tinyxml2::XMLElement* pRowElement = pLevelElement->FirstChildElement("cells")->FirstChildElement("row");
		map->cells = std::vector<std::vector<Cell*>>(map->cellCountInHeight, std::vector<Cell*>(map->cellCountInWidth, nullptr));
		
		for (int i = 0; i != map->cellCountInHeight; ++i) {
			std::string row = pRowElement->Attribute("s");
			int k = 0;
			for (int j = 0; j != map->cellCountInWidth; ++j) {
				char ch = row[k];
				k += 2;
				sf::Texture texture;
				if (ch == 'w')
					texture.loadFromFile("../assets/texture/water_simple_1.png");
				else if (ch == 'r')
					texture.loadFromFile("../assets/texture/rock_simple_1.png");
				else if (ch == 'g')
					texture.loadFromFile("../assets/texture/grass_simple_1.png");
				else if (ch == 's')
					texture.loadFromFile("../assets/texture/sand_simple_1.png");
				else 
					texture.loadFromFile("../assets/texture/noTexture_simple_1.png");

				sf::RenderTexture* renderTexture = new sf::RenderTexture();
				if (!renderTexture->create(texture.getSize().x, texture.getSize().y)) {
					return -3;
				}
				sf::Sprite sprite(texture);
				renderTexture->clear();
				renderTexture->draw(sprite);
				renderTexture->display();

				map->cells[i][j] = new Cell();
				map->cells[i][j]->set_render_texture(renderTexture);
			}
		}

	}
	//int delete_level();
private:





};
