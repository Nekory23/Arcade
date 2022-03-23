/*
** EPITECH PROJECT, 2021
** Game.hpp
** File description:
** Game class.
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

//Includes
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstddef>
#include <list>
#include <iterator>
#include "IGame.hpp"

class SnakeList {
    public:
        SnakeList(std::string direction, int x, int y);
        ~SnakeList(){}
        void setPositions(int x, int y);
        std::vector<int> getPositions();
        void setDirection(std::string direction);
        std::string getDirection();
    
    private:
        std::string _direction;
        std::vector<int> _positions;
};

namespace game {
    class Snake : public IGame{
    public:
        Snake();
        ~Snake() = default;
        void play(std::string direction) noexcept;
        bool checkDirection(std::string direction, int i, int y) noexcept;
        void moveF(std::string direction, int i, int y) noexcept;
        void enemy() noexcept;
        std::vector<std::string> getMap() const noexcept;
        int getScore() const noexcept;
        int getOver() const noexcept;
        void reset(void) noexcept;
    
    private:
        std::vector<std::string> _map;
        int _size_L;
        int _size_l;
        bool _over;
        int _score;
        std::list<SnakeList> _snake;
    };
}
#endif /* !GAME_HPP_ */
