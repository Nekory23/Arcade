/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <string>
#include <map>
#include "../../GraphicLib/include/ILibGraph.hpp"
#include "../../Game/include/IGame.hpp"
#include "ICore.hpp"

namespace core {
    class Core : public ICore {
        public:
            Core(int const ac, char const **av);
            ~Core() noexcept;
            void displayMenu() noexcept;
            void getGraphicLibs(char const *lib);
            void getGames(void);
            void loop(void) noexcept;
            std::string getCommand(void);
            void writeScore(void);
            void getNewLib(std::string libToGet);
    
        protected:
        private:
            std::string _configFile;
            std::string _scoreFile;
            std::string _player;
            std::vector<void *> _handles;
            void *_libhandle;
            std::string _currentGame;
            std::string _currentLib;
            std::map<std::string, game::IGame*> _game;
            lib::ILibGraph *_graph;
    };
}

#endif /* !CORE_HPP_ */
