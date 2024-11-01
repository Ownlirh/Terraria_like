#pragma once

#include <random>

enum Direction
{
        Up,
        Bottom,
        Left,
        Right
};

namespace DirectionUtils
{
        Direction getRandomDirection()
        {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dist(0, 3);
                return static_cast<Direction>(dist(gen));
        }
}