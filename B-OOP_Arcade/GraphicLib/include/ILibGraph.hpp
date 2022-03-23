/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** ILibGraph
*/

#ifndef ILIBGRAPH_HPP_
#define ILIBGRAPH_HPP_

#include <vector>

namespace lib {
    enum key 
    {
        space = 32,
        escape = 27,
        backspace = 8, 
        arrowUp = -1,
        arrowDown = -2,
        arrowLeft = -3,
        arrowRight = -4,
        Z = 122,
        Q = 113,
        S = 115,
        D = 100,
        null = 0
    };

    class ILibGraph {
        public:
            ~ILibGraph() = default;
            virtual int Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept = 0;
            virtual void Game(std::vector<std::string> map) noexcept = 0;
            virtual void DisplayScore(int score) noexcept = 0;
            virtual int GetKey() noexcept = 0;
            virtual std::string GetName() const noexcept = 0;
            virtual bool GetStatus() const noexcept = 0;
    
        protected:
        private:
    };
}

#endif /* !ILIBGRAPH_HPP_ */
