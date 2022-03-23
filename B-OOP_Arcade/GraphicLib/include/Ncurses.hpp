/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "ALibGraph.hpp"

namespace lib {
    class Ncurses : public ALibGraph {
        public:
            Ncurses();
            ~Ncurses() = default;
            int Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept;
            void Game(std::vector<std::string> map) noexcept;
            void DisplayScore(int score) noexcept;
            int GetKey() noexcept;
            std::string GetName() const noexcept;
            bool GetStatus() const noexcept;
            void GetKeyName(int key) noexcept;

        protected:
        private:
            std::string _name;
            int _game;
            bool _stop;
    };
}

#endif /* !NCURSES_HPP_ */
