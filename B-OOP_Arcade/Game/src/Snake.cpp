/*
** EPITECH PROJECT, 2021
** Game.cpp
** File description:
** functions of Game class.
*/

#include "Snake.hpp"

game::Snake::Snake()
{
    _over = false;
    _map = 
    {"**************************************", \
    "*       o           o           o    *", \
    "*                                    *", \
    "*o                      o           o*", \
    "*  o       o       o                o*", \
    "*o  o            o               o   *", \
    "* o        o                    o    *", \
    "*  o           o      o           o  *", \
    "*   o         o       o             o*", \
    "*                                    *", \
    "*  o           o      o           o  *", \
    "*o          P           o           o*", \
    "*                                    *", \
    "*       o           o           o    *", \
    "*o  o            o               o   *", \
    "*                                    *", \
    "*   o         o       o             o*", \
    "*o  o            o               o   *", \
    "*                                    *", \
    "**************************************"};
    _size_L = _map[0].length();
    _size_l = _map.size();
    _score = 0;
}

void game::Snake::reset(void) noexcept
{
    _over = false;
    _map = 
    {"**************************************", \
    "*       o           o           o    *", \
    "*                                    *", \
    "*o                      o           o*", \
    "*  o       o       o                o*", \
    "*o  o            o               o   *", \
    "* o        o                    o    *", \
    "*  o           o      o           o  *", \
    "*   o         o       o             o*", \
    "*                                    *", \
    "*  o           o      o           o  *", \
    "*o          P           o           o*", \
    "*                                    *", \
    "*       o           o           o    *", \
    "*o  o            o               o   *", \
    "*                                    *", \
    "*   o         o       o             o*", \
    "*o  o            o               o   *", \
    "*                                    *", \
    "**************************************"};
    _size_L = _map[0].length();
    _size_l = _map.size();
    _score = 0;
    _snake.clear();
}

std::vector<std::string> game::Snake::getMap() const noexcept
{
    return _map;
}

int game::Snake::getOver() const noexcept
{
    return _over;
}

int game::Snake::getScore() const noexcept
{
    return _score;
}

bool game::Snake::checkDirection(std::string direction, int i, int y) noexcept
{
    if (direction == "right" && _map[i][y + 1] != '*'
    && _map[i][y + 1] != 'F')
        return true;
    if (direction == "left" && _map[i][y - 1] != '*'
    && _map[i][y - 1] != 'F')
        return true;
    if (direction == "up" && _map[i - 1][y] != '*'
    && _map[i - 1][y] != 'F')
        return true;
    if (direction == "down" && _map[i + 1][y] != '*'
    && _map[i + 1][y] != 'F')
        return true;
    return false;
}

void game::Snake::moveF(std::string direction, int i, int y) noexcept
{
    if (direction == "right") {
        _map[i][y + 1] = 'F';
        _map[i][y] = ' ';
    }
    if (direction == "left") {
        _map[i][y - 1] = 'F';
        _map[i][y] = ' ';
    }
    if (direction == "up") {
        _map[i - 1][y] = 'F';
        _map[i][y] = ' ';
    }
    if (direction == "down") {
        _map[i + 1][y] = 'F';
        _map[i][y] = ' ';
    }
}

void game::Snake::enemy() noexcept
{
    std::vector<int> positions;
    std::string direction;
    std::string tmp;
    std::list<SnakeList>::iterator it = _snake.begin();
    std::list<SnakeList>::iterator it2 = _snake.begin();

    it++;
    for (size_t i = 1; i < _snake.size(); i++ ,it++, it2++) {
        positions = it->getPositions();
        direction = it->getDirection();
        moveF(direction, positions[0], positions[1]);
        if (direction == "right")
            it->setPositions(positions[0], (positions[1] + 1));
        if (direction == "left")
            it->setPositions(positions[0], (positions[1] - 1));
        if (direction == "up")
            it->setPositions((positions[0] - 1), positions[1]);
        if (direction == "down")
            it->setPositions((positions[0] + 1), positions[1]);
    }
    it = _snake.end();
    it2 = it;
    it2--;
    it2--;
    it--;
    while (it != _snake.begin()) {
        it->setDirection(it2->getDirection());
        it2--;
        it--;
    }
}

void game::Snake::play(std::string direction) noexcept
{
    int i = 0;
    int y = 0;
    int score = _score;
    std::list<SnakeList>::iterator it;

    while (i < _size_l && _map[i][y] != 'P') {
        while (y < _size_L && _map[i][y] != 'P')
            y++;
        if (_map[i][y] != 'P') {
            y = 0;
            i ++;
        }
    }
    if (_snake.size() == 0) {
        SnakeList player(direction, i, y);
        _snake.push_back(player);
    }
    it = _snake.begin();
    if (direction == "right") {
        if (_map[i][y + 1] == 'F' || _map[i][y + 1] == '*')
            _over = true;
        if (_map[i][y + 1] != '*') {
            if (_map[i][y + 1] == 'o') {
                _score++;
                _map[i][y] = 'F';
                SnakeList F(direction, i, y);
                it++;
                _snake.insert(it, F);
            } else
                _map[i][y] = ' ';
            _map[i][y + 1] = 'P';
        }
    }
    if (direction == "left") {
        if (_map[i][y - 1] == 'F' || _map[i][y - 1] == '*')
            _over = true;
        if (_map[i][y - 1] != '*') {
            if (_map[i][y - 1] == 'o') {
                _score++;
                _map[i][y] = 'F';
                SnakeList F(direction, i, y);
                it++;
                _snake.insert(it, F);
            } else
                _map[i][y] = ' ';
            _map[i][y - 1] = 'P';
        }
    }
    if (direction == "up") {
        if (_map[i - 1][y] == 'F' || _map[i - 1][y] == '*')
            _over = true;
        if (_map[i - 1][y] != '*') {
            if (_map[i - 1][y] == 'o') {
                _score++;
                _map[i][y] = 'F';
                SnakeList F(direction, i, y);
                it++;
                _snake.insert(it, F);
            } else
                _map[i][y] = ' ';
            _map[i - 1][y] = 'P';
        }
    }
    if (direction == "down") {
        if (_map[i + 1][y] == 'F' || _map[i + 1][y] == '*')
            _over = true;
        if (_map[i + 1][y] != '*') {
            if (_map[i + 1][y] == 'o') {
                _score++;
                _map[i][y] = 'F';
                SnakeList F(direction, i, y);
                it++;
                _snake.insert(it, F);
            } else
                _map[i][y] = ' ';
            _map[i + 1][y] = 'P';
        }
    }
    it = _snake.begin();
    it->setPositions(i, y);
    it->setDirection(direction);
    if (score == _score)
        enemy();
}