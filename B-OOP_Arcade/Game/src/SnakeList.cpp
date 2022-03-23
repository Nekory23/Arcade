/*
** EPITECH PROJECT, 2021
** Snake.cpp
** File description:
** functions of Snake class.
*/

#include "Snake.hpp"

SnakeList::SnakeList(std::string direction, int x, int y)
{
    this->_direction = direction;
    this->_positions.push_back(x);
    this->_positions.push_back(y);
}

void SnakeList::setPositions(int x, int y)
{
    this->_positions[0] = x;
    this->_positions[1] = y;
}

std::vector<int> SnakeList::getPositions()
{
    return (this->_positions);
}

void SnakeList::setDirection(std::string direction)
{
    this->_direction = direction;
}

std::string SnakeList::getDirection()
{
    return (this->_direction);
}
