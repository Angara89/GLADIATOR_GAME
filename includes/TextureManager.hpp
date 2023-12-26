#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class TextureManager {
public:
    sf::Texture& getTexture(const std::string& filename) {
        // Проверяем, есть ли текстура уже в кеше
        auto it = textures.find(filename);
        if (it != textures.end()) {
            return it->second;
        }

        // Загрузка и сохранение текстуры
        sf::Texture texture;
        if (texture.loadFromFile(filename)) {
            textures[filename] = texture;
        }

        return textures[filename];
    }

private:
    std::map<std::string, sf::Texture> textures;
};
