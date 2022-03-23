/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"

namespace game {
    class Pacman : public IGame {
        public:
            Pacman() noexcept;
            ~Pacman() = default;
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
            std::vector<std::string> _directionF;
    };
}

#endif /* !PACMAN_HPP_ */
