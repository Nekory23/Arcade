/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** NcursesFunction
*/

#include <ncurses.h>
#include <iostream>
#include "Ncurses.hpp"

lib::Ncurses::Ncurses()
{
    _name = "";
    _game = -1;
    _stop = true;
    initscr();
}

bool lib::Ncurses::GetStatus() const noexcept
{
    return _stop;
}

int lib::Ncurses::Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept
{
    int key = 0;
    std::string select = "-->";

    keypad(stdscr, TRUE);
    clear();
    mvprintw((LINES / 3) - 1, (COLS / 4), _games.c_str());
    for (std::size_t i = 0; i != game.size(); i++)
        mvprintw((LINES / 3) + i, (COLS / 4), game[i].c_str());
    if (_game != -1)
        mvprintw((LINES / 3) + _game, (COLS / 4) - 4, select.c_str());
    mvprintw((LINES / 3) - 1, (COLS / 3) * 2, _lib.c_str());
    for (std::size_t i = 0; i != lib.size(); i++)
        mvprintw((LINES / 3) + i, (COLS / 3) * 2, lib[i].c_str());
    mvprintw((LINES / 3) * 2 - 1, (COLS / 3), _score.c_str());
    for (std::size_t i = 0; i != score.size(); i++) {
        if (i == 10)
            break;
        mvprintw((LINES / 3) * 2 + i, (COLS / 3), score[i].c_str());
    }
    mvprintw((LINES / 5) - 1, (COLS / 2), _names.c_str());
    mvprintw((LINES / 5) - 1, (COLS / 2) + _names.length() + 2, _name.c_str());
    refresh();
    key = getch();
    GetKeyName(key);
    if (key == '\n')
        return _game;
    return -1;
}

void lib::Ncurses::Game(std::vector<std::string> map) noexcept
{
    int halfLine = (COLS / 2) - map[0].length() / 2;
    int halfHeight = (LINES / 2) - map.size() / 2;
    clear();
    for (std::size_t i = 0; i != map.size(); i++)
        mvprintw(halfHeight + i, halfLine, map[i].c_str());
    refresh();
}

void lib::Ncurses::DisplayScore(int score) noexcept
{
    std::string scoreText = "Score : " + std::to_string(score);

    mvprintw((LINES / 2) - 13, (COLS / 2) - (scoreText.length() / 2), scoreText.c_str());
    timeout(100);
    refresh();
}

void lib::Ncurses::GetKeyName(int key) noexcept
{
    switch (key) {
        case 'z' :
            _name.insert(_name.end(), 'Z');
            break;
        case 'q' :
            _name.insert(_name.end(), 'Q');
            break;
        case 's' :
            _name.insert(_name.end(), 'S');
            break;
        case 'd' :
            _name.insert(_name.end(), 'D');
            break;
        case 'a' :
            _name.insert(_name.end(), 'A');
            break;
        case 'b' :
            _name.insert(_name.end(), 'B');
            break;
        case 'c' :
            _name.insert(_name.end(), 'C');
            break;
        case 'e' :
            _name.insert(_name.end(), 'E');
            break;
        case 'f' :
            _name.insert(_name.end(), 'F');
            break;
        case 'g' :
            _name.insert(_name.end(), 'G');
            break;
        case 'h' :
            _name.insert(_name.end(), 'H');
            break;
        case 'i' :
            _name.insert(_name.end(), 'I');
            break;
        case 'k' :
            _name.insert(_name.end(), 'K');
            break;
        case 'l' :
            _name.insert(_name.end(), 'L');
            break;
        case 'm' :
            _name.insert(_name.end(), 'M');
            break;
        case 'n' :
            _name.insert(_name.end(), 'N');
            break;
        case 'o' :
            _name.insert(_name.end(), 'O');
            break;
        case 'p' :
            _name.insert(_name.end(), 'P');
            break;
        case 'r' :
            _name.insert(_name.end(), 'R');
            break;
        case 't' :
            _name.insert(_name.end(), 'T');
            break;
        case 'u' :
            _name.insert(_name.end(), 'U');
            break;
        case 'v' :
            _name.insert(_name.end(), 'V');
            break;
        case 'w' :
            _name.insert(_name.end(), 'W');
            break;
        case 'x' :
            _name.insert(_name.end(), 'X');
            break;
        case 'y' :
            _name.insert(_name.end(), 'Y');
            break;
        case lib::escape :
            _stop = false;
            endwin();
            break;
        case ' ' :
            _name.insert(_name.end(), ' ');
            break;
        case KEY_BACKSPACE :
            if (_name.size() != 0)
                _name.erase(_name.size() - 1);
            break;
        case KEY_RIGHT :
            _game = 0;
            break;
        case KEY_LEFT :
            _game = 1;
            break;
        default:
            break;
    }
}

int lib::Ncurses::GetKey() noexcept
{
    keypad(stdscr, TRUE);
    switch (getch()) {
        case 'z' :
            return lib::Z;
        case 'q' :
            return lib::Q;
        case 's' :
            return lib::S;
        case 'd' :
            return lib::D;
        case lib::escape :
            _stop = false;
            endwin();
            return lib::escape;
        case ' ' :
            return lib::space;
        case KEY_BACKSPACE :
            _game = -1;
            return lib::backspace;
        case KEY_UP :
            endwin();
            return lib::arrowUp;
        case KEY_LEFT :
            return lib::arrowLeft;
        case KEY_DOWN :
            endwin();
            return lib::arrowDown;
        case KEY_RIGHT :
            return lib::arrowRight;
        default :
            return null;
    }
}

std::string lib::Ncurses::GetName() const noexcept
{
    return _name;
}