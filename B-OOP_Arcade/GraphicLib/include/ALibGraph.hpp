/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** LibGraph
*/

#ifndef LIBGRAPH_HPP_
#define LIBGRAPH_HPP_

#include <string>
#include "ILibGraph.hpp"

namespace lib {
    class ALibGraph : public ILibGraph {
        public:
            ALibGraph() = default;
            ~ALibGraph() = default;
            void Game(std::vector<std::string> map) noexcept {(void) map;};
            int Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept 
            {
                (void) game;
                (void) lib;
                (void) score;
                return 0;
            };
            void DisplayScore(int score) noexcept {(void) score;};
            int GetKey() noexcept {return 0;};
            std::string GetName() const noexcept {return "";};
            bool GetStatus() const noexcept {return true;};

        protected:
            std::string _games = "GAMES AVAILABLES :";
            std::string _lib = "GRAPHICS AVAILABLES :";
            std::string _score = "SCORES :";
            std::string _names = "What is your player name ?";
        private:
    };
}

#endif /* !LIBGRAPH_HPP_ */
