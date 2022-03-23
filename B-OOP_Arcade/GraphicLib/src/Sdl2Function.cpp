/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Sdl2Function
*/

#include <iostream>
#include "Sdl2.hpp"

lib::Sdl2::Sdl2()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _win = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    _rend = SDL_CreateRenderer(_win, -1, render_flags);
    _font = TTF_OpenFont("./GraphicLib/res/font.ttf", 80);
    _textgame = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, _games.c_str(), SDL_Color{255, 255, 255, 255}));
    _textlib = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, _lib.c_str(), SDL_Color{255, 255, 255, 255}));
    _textscore = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, _score.c_str(), SDL_Color{255, 255, 255, 255}));
    _textname = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, _names.c_str(), SDL_Color{255, 255, 255, 255}));
    _name = "";
    _game = 0;
    _isOpen = true;
}

lib::Sdl2::~Sdl2()
{
    TTF_CloseFont(_font);
    SDL_DestroyTexture(_textgame);
    SDL_DestroyTexture(_textlib);
    SDL_DestroyTexture(_textscore);
    SDL_DestroyTexture(_textname);
    SDL_DestroyRenderer(_rend);
    SDL_DestroyWindow(_win);
    TTF_Quit();
    SDL_Quit();
}

bool lib::Sdl2::GetStatus() const noexcept
{
    return _isOpen;
}

int lib::Sdl2::Menu(std::vector<std::string> games, std::vector<std::string> libs, std::vector<std::string> scores) noexcept
{
    SDL_Rect pos = {320, 170, 200, 75};
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _isOpen = false;
        }
        if (_event.type == SDL_KEYDOWN) {
            if (_event.key.keysym.scancode == SDL_SCANCODE_RETURN)
                return _game;
            GetKeyName();
        }
    }
    SDL_Delay(1000 / 60);
    SDL_SetRenderDrawColor(_rend, 0, 0, 0, 255);
    SDL_RenderClear(_rend);
    SDL_RenderCopy(_rend, _textgame, nullptr, &pos);
    pos.y += 80;
    for (std::size_t i = 0; i != games.size(); i++) {
        _tmp = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, games[i].c_str(), SDL_Color{255, 255, 255, 255}));
        pos.w = 100;
        pos.h = 50;
        SDL_RenderCopy(_rend, _tmp, nullptr, &pos);
        pos.y += 30;
    }
    pos = {1280, 170, 200, 75};
    SDL_RenderCopy(_rend, _textlib, nullptr, &pos);
    pos.y += 80;
    for (std::size_t i = 0; i != libs.size(); i++) {
        _tmp = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, libs[i].c_str(), SDL_Color{255, 255, 255, 255}));
        pos.w = 75;
        pos.h = 50;
        SDL_RenderCopy(_rend, _tmp, nullptr, &pos);
        pos.y += 50;
    }
    pos = {740, 640, 350, 75};
    SDL_RenderCopy(_rend, _textname, nullptr, &pos);
    pos = {740 - (int)(_name.size() * 2), 700, 100, 75};
    _tmp = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, _name.c_str(), SDL_Color{255, 255, 255, 255}));
    SDL_RenderCopy(_rend, _tmp, nullptr, &pos);
    pos = {840, 370, 100, 50};
    SDL_RenderCopy(_rend, _textscore, nullptr, &pos);
    pos.y += 80;
    pos.x -= 60;
    for (std::size_t i = 0; i != scores.size(); i++) {
        if ((int) i == 10)
            break;
        _tmp = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, scores[i].c_str(), SDL_Color{255, 255, 255, 255}));
        pos.w = 350;
        pos.h = 50;
        SDL_RenderCopy(_rend, _tmp, nullptr, &pos);
        pos.y += 30;
    }
    SDL_RenderPresent(_rend);
    return -1;
}

void lib::Sdl2::GetKeyName() noexcept
{
    switch (_event.key.keysym.scancode)
    {
        case SDL_SCANCODE_A:
            _name.insert(_name.end(), 1, 'Q');
            break;
        case SDL_SCANCODE_B:
            _name.insert(_name.end(), 1, 'B');
            break;
        case SDL_SCANCODE_C:
            _name.insert(_name.end(), 1, 'C');
            break;
        case SDL_SCANCODE_D:
            _name.insert(_name.end(), 1, 'D');
            break;
        case SDL_SCANCODE_E:
            _name.insert(_name.end(), 1, 'E');
            break;
        case SDL_SCANCODE_F:
            _name.insert(_name.end(), 1, 'F');
            break;
        case SDL_SCANCODE_G:
            _name.insert(_name.end(), 1, 'G');
            break;
        case SDL_SCANCODE_H:
            _name.insert(_name.end(), 1, 'H');
            break;
        case SDL_SCANCODE_I:
            _name.insert(_name.end(), 1, 'I');
            break;
        case SDL_SCANCODE_J:
            _name.insert(_name.end(), 1, 'J');
            break;
        case SDL_SCANCODE_K:
            _name.insert(_name.end(), 1, 'K');
            break;
        case SDL_SCANCODE_L:
            _name.insert(_name.end(), 1, 'L');
            break;
        case SDL_SCANCODE_M:
            _name.insert(_name.end(), 1, 'M');
            break;
        case SDL_SCANCODE_N:
            _name.insert(_name.end(), 1, 'N');
            break;
        case SDL_SCANCODE_O:
            _name.insert(_name.end(), 1, 'O');
            break;
        case SDL_SCANCODE_P:
            _name.insert(_name.end(), 1, 'P');
            break;
        case SDL_SCANCODE_Q:
            _name.insert(_name.end(), 1, 'A');
            break;
        case SDL_SCANCODE_R:
            _name.insert(_name.end(), 1, 'R');
            break;
        case SDL_SCANCODE_S:
            _name.insert(_name.end(), 1, 'S');
            break;
        case SDL_SCANCODE_T:
            _name.insert(_name.end(), 1, 'T');
            break;
        case SDL_SCANCODE_U:
            _name.insert(_name.end(), 1, 'U');
            break;
        case SDL_SCANCODE_V:
            _name.insert(_name.end(), 1, 'V');
            break;
        case SDL_SCANCODE_W:
            _name.insert(_name.end(), 1, 'Z');
            break;
        case SDL_SCANCODE_X:
            _name.insert(_name.end(), 1, 'X');
            break;
        case SDL_SCANCODE_Y:
            _name.insert(_name.end(), 1, 'Y');
            break;
        case SDL_SCANCODE_Z:
            _name.insert(_name.end(), 1, 'W');
            break;
        case SDL_SCANCODE_SPACE:
            _name.insert(_name.end(), 1, ' ');
            break;
        case SDL_SCANCODE_BACKSPACE:
            if (_name.size() != 0)
                _name.erase(_name.size() - 1);
            break;
        case SDL_SCANCODE_LEFT:
                _game = 1;
            break;
        case SDL_SCANCODE_RIGHT:
                _game = 0;
            break;
        case SDL_SCANCODE_UP:
            break;
        case SDL_SCANCODE_DOWN:
            break;
        case SDL_SCANCODE_UNKNOWN:
            break;
        case SDL_SCANCODE_ESCAPE:
            _isOpen = false;
            break;
        default:
            break;
    }
}

void draw_rectangle_fill(SDL_Renderer* renderer, const SDL_Rect& rectangle, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (auto y = rectangle.y; y < rectangle.y + rectangle.h; y++)
    {
        for (auto x = rectangle.x; x < rectangle.x + rectangle.w; x++)
        {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

void lib::Sdl2::Game(std::vector<std::string> map) noexcept
{
    SDL_Rect rect;
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _isOpen = false;
        }
    }
    SDL_Delay(1000 / 60);
    SDL_SetRenderDrawColor(_rend, 0, 0, 0, 255);
    SDL_RenderClear(_rend);
    for (long unsigned int i = 0; i < map.size(); i++) {
        for (long unsigned int y = 0; y < map[0].length(); y++) {
            if (map[i][y] == '*') {
                rect = {(int) y * 50, (int) i * 50, 50, 50};
                draw_rectangle_fill(_rend, rect, SDL_Color {0, 0, 255, 255});
            }
            if (map[i][y] == ' ')
                continue;
            if (map[i][y] == 'o') {
                rect = {(int) y * 50, (int) i * 50, 25, 25};
                draw_rectangle_fill(_rend, rect, SDL_Color {255, 255, 0, 255});
            }
            if (map[i][y] == 'P') {
                rect = {(int) y * 50, (int) i * 50, 50, 50};
                draw_rectangle_fill(_rend, rect, SDL_Color {255, 255, 0, 255});
            }
            if (map[i][y] == 'F') {
                rect = {(int) y * 50, (int) i * 50, 50, 50};
                draw_rectangle_fill(_rend, rect, SDL_Color {255, 20, 147, 255});
            }
        }
    }
    SDL_RenderPresent(_rend);
}

void lib::Sdl2::DisplayScore(int score) noexcept
{
    std::string base = "Score : ";
    SDL_Rect pos = {800, 50, 200, 75};

    base.append(std::to_string(score));
    _tmp = SDL_CreateTextureFromSurface(_rend, TTF_RenderText_Solid(_font, base.c_str(), SDL_Color{255, 255, 255, 255}));
    SDL_RenderCopy(_rend, _textscore, nullptr, &pos);
    SDL_RenderPresent(_rend);
}


int lib::Sdl2::GetKey() noexcept
{
    if (_event.type == SDL_KEYDOWN) {
        switch (_event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                _isOpen = false;
                return lib::escape;
            case SDL_SCANCODE_SPACE:
                return lib::space;
            case SDL_SCANCODE_BACKSPACE:
                return lib::backspace;
            case SDL_SCANCODE_UP:
                this->~Sdl2();
                return lib::arrowUp;
            case SDL_SCANCODE_DOWN:
                this->~Sdl2();
                return lib::arrowDown;
            case SDL_SCANCODE_LEFT:
                return lib::arrowLeft;
            case SDL_SCANCODE_RIGHT:
                return lib::arrowRight;
            case SDL_SCANCODE_W:
                return lib::Z;
            case SDL_SCANCODE_A:
                return lib::Q;
            case SDL_SCANCODE_S:
                return lib::S;
            case SDL_SCANCODE_D:
                return lib::D;
            case SDL_SCANCODE_UNKNOWN:
                break;
            default:
                return null;
            }
        }
    return null;
}

std::string lib::Sdl2::GetName() const noexcept
{
    return _name;
}