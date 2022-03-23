/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "ALibGraph.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

namespace lib {
    class Sdl2 : public ALibGraph {
        public:
            Sdl2();
            ~Sdl2();
            int Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept;
            void Game(std::vector<std::string> map) noexcept;
            void DisplayScore(int score) noexcept;
            std::string GetName() const noexcept;
            void GetKeyName() noexcept;
            int GetKey() noexcept;
            bool GetStatus() const noexcept;

        protected:
        private:
            SDL_Window* _win;
            SDL_Renderer* _rend;
            SDL_Event _event;
            TTF_Font* _font;
            SDL_Texture* _textgame;
            SDL_Texture* _textscore;
            SDL_Texture* _textlib;
            SDL_Texture* _textname;
            SDL_Texture* _tmp;
            std::string _name;
            int _game;
            bool _isOpen;
    };
}

#endif /* !SDL2_HPP_ */
