/*
** EPITECH PROJECT, 2021
** Game.cpp
** File description:
** functions of Game class.
*/

#include "Pacman.hpp"

game::Pacman::Pacman() noexcept
{
    _over = false;
    _map = 
    {"**************************************", \
    "*Pooooooooo****************oooooooooo*", \
    "*o***o****o****************o****o***o*", \
    "*o***oooooooooooooooooooooooooooo***o*", \
    "*o***o**o********************o**o***o*", \
    "*ooooo**ooo****************ooo**ooooo*", \
    "***o*o****o****************o****o*o***", \
    "***o*oooooooooooooooooooooooooooo*o***", \
    "***ooo***o******************o***ooo***", \
    "***o*ooo*o******************o*ooo*o***", \
    "***o***ooooooooooFFFooooooooooo***o***", \
    "*ooooo*o**********************o*ooooo*", \
    "*o***o*oooo****************oooo*o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*oooooooooooooooooooooooooooooooooooo*", \
    "**************************************"};
    _size_L = _map[0].length();
    _size_l = _map.size();
    _score = 0;
    _directionF = {"left", "right", "right"};
}

void game::Pacman::reset(void) noexcept
{
    _over = false;
    _map = 
    {"**************************************", \
    "*Pooooooooo****************oooooooooo*", \
    "*o***o****o****************o****o***o*", \
    "*o***oooooooooooooooooooooooooooo***o*", \
    "*o***o**o********************o**o***o*", \
    "*ooooo**ooo****************ooo**ooooo*", \
    "***o*o****o****************o****o*o***", \
    "***o*oooooooooooooooooooooooooooo*o***", \
    "***ooo***o******************o***ooo***", \
    "***o*ooo*o******************o*ooo*o***", \
    "***o***ooooooooooFFFooooooooooo***o***", \
    "*ooooo*o**********************o*ooooo*", \
    "*o***o*oooo****************oooo*o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*o***o****o****************o****o***o*", \
    "*oooooooooooooooooooooooooooooooooooo*", \
    "**************************************"};
    _size_L = _map[0].length();
    _size_l = _map.size();
    _score = 0;
    _directionF = {"left", "right", "right"};
}

std::vector<std::string> game::Pacman::getMap() const noexcept
{
    return _map;
}

int game::Pacman::getOver() const noexcept
{
    return _over;
}

int game::Pacman::getScore() const noexcept
{
    return _score;
}

bool game::Pacman::checkDirection(std::string direction, int i, int y) noexcept
{
    if (direction == "right" && _map[i][y + 1] != '*'
    && _map[i][y + 1] != 'F' && _map[i][y + 1] != 'f')
        return true;
    if (direction == "left" && _map[i][y - 1] != '*'
    && _map[i][y - 1] != 'F' && _map[i][y - 1] != 'f')
        return true;
    if (direction == "up" && _map[i - 1][y] != '*'
    && _map[i - 1][y] != 'F' && _map[i - 1][y] != 'f')
        return true;
    if (direction == "down" && _map[i + 1][y] != '*'
    && _map[i + 1][y] != 'F' && _map[i + 1][y] != 'f')
        return true;
    return false;
}

void game::Pacman::moveF(std::string direction, int i, int y) noexcept
{
    char tmp;

    if (direction == "right") {
        tmp = _map[i][y + 1];
        if (tmp == 'P')
            _over = true;
        _map[i][y + 1] = 'f';
        _map[i][y] = tmp;
    }
    if (direction == "left") {
        tmp = _map[i][y - 1];
        if (tmp == 'P')
            _over = true;
        _map[i][y - 1] = 'f';
        _map[i][y] = tmp;
    }
    if (direction == "up") {
        tmp = _map[i - 1][y];
        if (tmp == 'P')
            _over = true;
        _map[i - 1][y] = 'f';
        _map[i][y] = tmp;
    }
    if (direction == "down") {
        tmp = _map[i + 1][y];
        if (tmp == 'P')
            _over = true;
        _map[i + 1][y] = 'f';
        _map[i][y] = tmp;
    }
}

void game::Pacman::enemy() noexcept
{
    int i = 0;
    int y = 0;
    int nb = 0;
    int nbbis = 0;
    int direction = 0;

    while(nb < 3 && _over != true) {
        i = 0;
        y = 0;
        while (i < _size_l && _map[i][y] != 'F') {
            while (y < _size_L && _map[i][y] != 'F')
                y++;
            if (_map[i][y] != 'F') {
                i++;
                y = 0;
            }
        }
        nbbis = nb;
        if (checkDirection(_directionF[nb], i, y) == true) {
            moveF(_directionF[nb], i, y);
            nb++;
        }
        while (nbbis == nb) {
            direction = rand() % 4;
            if (direction == 0 && checkDirection("right", i, y) == true)
                _directionF[nb] = "right";
            if (direction == 1 && checkDirection("left", i, y) == true)
                _directionF[nb] = "left";
            if (direction == 2 && checkDirection("up", i, y) == true)
                _directionF[nb] = "up";
            if (direction == 3 && checkDirection("down", i, y) == true)
                _directionF[nb] = "down";
            if (checkDirection(_directionF[nb], i, y) == true) {
                moveF(_directionF[nb], i, y);
                nb++;
            }
        }
    }
    i = 0;
    y = 0;
    while (i < _size_l && _map[i][y] != 'F') {
        while (y < _size_L && _map[i][y] != 'F') {
            if (_map[i][y] == 'f')
                _map[i][y] = 'F';
            y++;
        }
        i++;
        y = 0;
    }
}

void game::Pacman::play(std::string direction) noexcept
{
    int i = 0;
    int y = 0;

    while (i < _size_l && _map[i][y] != 'P') {
        while (y < _size_L && _map[i][y] != 'P')
            y++;
        if (_map[i][y] != 'P') {
            y = 0;
            i ++;
        }
    }
    if (direction == "right") {
        if (_map[i][y + 1] == 'F')
            _over = true;
        if (_map[i][y + 1] != '*') {
            if (_map[i][y + 1] == 'o')
                _score++;
            _map[i][y] = ' ';
            _map[i][y + 1] = 'P';
        }
    }
    if (direction == "left") {
        if (_map[i][y - 1] == 'F')
            _over = true;
        if (_map[i][y - 1] != '*') {
            if (_map[i][y - 1] == 'o')
                _score++;
            _map[i][y] = ' ';
            _map[i][y - 1] = 'P';
        }
    }
    if (direction == "up") {
        if (_map[i - 1][y] == 'F')
            _over = true;
        if (_map[i - 1][y] != '*') {
            if (_map[i - 1][y] == 'o')
                _score++;
            _map[i][y] = ' ';
            _map[i - 1][y] = 'P';
        }
    }
    if (direction == "down") {
        if (_map[i + 1][y] == 'F')
            _over = true;
        if (_map[i + 1][y] != '*') {
            if (_map[i + 1][y] == 'o')
                _score++;
            _map[i][y] = ' ';
            _map[i + 1][y] = 'P';
        }
    }
    enemy();
}