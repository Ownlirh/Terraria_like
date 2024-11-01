#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <unordered_map>
#include "Direction/Direction.h"
#include "Paths.h"
#include "TextureManager/TextureManager.h";


float getSpritePositionX(float backgroundX, int index)
{
    return backgroundX + 25 + 90 * index;
}

float getSpritePositionY(float backgroundY, int index, float backgroundBoundHeight, float spriteBoundHeight)
{
    return backgroundY + (backgroundBoundHeight - spriteBoundHeight) / 2;
}

int main()
{
    TextureManager textureManager;

    sf::RenderWindow window(sf::VideoMode(768, 600), "My window");

    sf::Texture backgroundTexture;

    if (!backgroundTexture.loadFromFile("src\\images\\arrows_background.png"))
    {
        std::cout << "Cannot load arroz_background.png image." << '\n';
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    float backgroundX = (window.getSize().x - backgroundSprite.getGlobalBounds().width) / 2;
    float backgroundY = (window.getSize().y - backgroundSprite.getGlobalBounds().height) / 2;
    backgroundSprite.setPosition(backgroundX, backgroundY);

    int currentLevel = 0;
    bool finishedCurrentLevel = false;

    std::vector<Direction> directions;
    std::vector<Direction> savedDirections;

    for (int i = 0; i <= currentLevel; i++)
    {
        Direction currentDirection = DirectionUtils::getRandomDirection();

        directions.push_back(currentDirection);
    }

    savedDirections = directions;

    bool completedLevel = false;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left && !completedLevel) {
                std::cout << "Se presiono la tecla de la izquierda" << '\n';
                if (!directions.empty() && directions.front() == Direction::Left) {
                    directions.erase(directions.begin());
                }
                else {
                    // Renegerate
                    directions = savedDirections;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right && !completedLevel) {
                std::cout << "Se presiono la tecla de la Derecha" << '\n';
                if (!directions.empty() && directions.front() == Direction::Right) {
                    directions.erase(directions.begin());
                }
                else {
                    // Renegerate
                    directions = savedDirections;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && !completedLevel) {
                std::cout << "Se presiono la tecla de la Derecha" << '\n';
                if (!directions.empty() && directions.front() == Direction::Up) {
                    directions.erase(directions.begin());
                }
                else {
                    // Renegerate
                    directions = savedDirections;
                }
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !completedLevel) {
                std::cout << "Se presiono la tecla de la Derecha" << '\n';
                if (!directions.empty() && directions.front() == Direction::Bottom) {
                    directions.erase(directions.begin());
                }
                else {
                    // Renegerate
                    directions = savedDirections;
                }
            } 

            if (directions.empty()) {
                completedLevel = true;

                if (currentLevel < 7) {
                    currentLevel++;
                }

                for (int i = 0; i <= currentLevel; i++)
                {
                    Direction currentDirection = DirectionUtils::getRandomDirection();

                    directions.push_back(currentDirection);
                }

                savedDirections = directions;

                completedLevel = false;
            }           
        }

        window.clear();

        window.draw(backgroundSprite);
        int index = 0;
        for (const auto &direction : directions)
        {
            sf::Sprite sprite(textureManager.GetTextureByDirection(direction));

            sprite.setPosition(
                getSpritePositionX(backgroundX, index),
                getSpritePositionY(backgroundY, index, backgroundSprite.getGlobalBounds().height, sprite.getGlobalBounds().height));
            window.draw(sprite);
            index++;
        }

        window.display();
    }

    return 0;
}
