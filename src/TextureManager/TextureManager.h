#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paths.h"
#include "Direction/Direction.h"

class TextureManager
{
private:
        std::unordered_map<Direction, sf::Texture> textures;

public:
        TextureManager(){
                std::cout << "Initializing textures ... " << '\n';

                loadTexture(Direction::Left, Paths::leftArrowPath);
                loadTexture(Direction::Right, Paths::rightArrowPath);
                loadTexture(Direction::Up, Paths::topArrowPath);
                loadTexture(Direction::Bottom, Paths::bottomArrowPath);

                std::cout << "Finished initializing textures." << '\n';
        }

        ~TextureManager(){
                std::cout << "Texture Manager destroyed." << '\n';
        }

        void loadTexture(Direction direction, const std::string &fileName)
        {
                auto it = textures.find(direction);

                if (it != textures.end())
                {
                        return;
                }

                sf::Texture texture;

                if (!texture.loadFromFile(fileName))
                {
                        std::cerr << "Error loading texture: " << fileName << '\n';
                        throw std::runtime_error("Failed to load texture");
                }

                textures[direction] = texture;
        }

        const sf::Texture &GetTextureByDirection(Direction direction)
        {
                auto it = textures.find(direction);
                if (it != textures.end())
                {
                        return it->second;
                }
                else
                {
                        std::cerr << "Texture not found. Direction -> " << direction << '\n';
                        throw std::runtime_error("Texture not found for the given direction");
                }
        }
};