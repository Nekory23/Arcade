/*
** EPITECH PROJECT, 2021
** B-OOP_Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <vector>

namespace game {
    class IGame {
        public:
            ~IGame() = default;
            virtual void play(std::string direction) noexcept = 0;
            virtual bool checkDirection(std::string direction, int i, int y) noexcept = 0;
            virtual void moveF(std::string direction, int i, int y) noexcept = 0;
            virtual void enemy() noexcept = 0;
            virtual std::vector<std::string> getMap(void) const noexcept = 0;
            virtual int getScore(void) const noexcept = 0;
            virtual int getOver(void) const noexcept = 0;
            virtual void reset(void) noexcept = 0;
    
        protected:
        private:
    };
}

#endif /* !IGAME_HPP_ */
