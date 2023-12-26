#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class TextureManager {
public:
    sf::Texture& getTexture(const std::string& filename) {
        // ���������, ���� �� �������� ��� � ����
        auto it = textures.find(filename);
        if (it != textures.end()) {
            return it->second;
        }

        // �������� � ���������� ��������
        sf::Texture texture;
        if (texture.loadFromFile(filename)) {
            textures[filename] = texture;
        }

        return textures[filename];
    }

private:
    std::map<std::string, sf::Texture> textures;
};
