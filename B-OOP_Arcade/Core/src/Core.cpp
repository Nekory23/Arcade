/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Core
*/

#include <fstream>
#include <memory>
#include <dlfcn.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "Error.hpp"
#include "Core.hpp"
#include "../../GraphicLib/include/ILibGraph.hpp"
#include "../../Game/include/IGame.hpp"

static std::string getLibName(const char *lib) noexcept
{
    std::string name = lib;

    name = name.substr(name.find('_') + 1);
    name = name.substr(0, name.find('.'));
    return name;
}

static std::string getFunctionName(std::string libName)
{
    std::string functionName = "create";

    functionName.append(libName);
    functionName[6] -= 32;
    return functionName;
}

static std::vector<std::string> getLibs(std::string file)
{
    std::ifstream fd(file);
    std::string line;
    std::string libName;
    std::vector<std::string> ret;

    while (std::getline(fd, line)) {
        if (line.compare("## nameLib") == 0)
            continue;
        if (line.compare("## nameLib_end") == 0)
            break;
        std::ifstream test(line);
        if (!test)
            continue;
        libName = getLibName(line.c_str());
        ret.push_back(libName);
    }
    fd.close();
    return ret;
}

void core::Core::getGraphicLibs(char const *lib)
{
    char *error;
    std::ifstream fd(_configFile);
    std::string libName = getLibName(lib);
    std::string funcName = getFunctionName(libName);
    std::string line;
    lib::ILibGraph* (*getGraph)();

    _libhandle = dlopen(lib, RTLD_LAZY);
    if (!_libhandle)
        throw Error(std::cerr, dlerror());
    getGraph = (lib::ILibGraph* (*)()) dlsym(_libhandle, funcName.c_str());
    if ((error = dlerror()))
        throw Error(std::cerr, error);
    _graph = (lib::ILibGraph*) getGraph();
    _currentLib = libName;
}

void core::Core::getNewLib(std::string libToGet)
{
    std::ifstream fd(_configFile);
    std::string toGet;
    std::string line;

    while(std::getline(fd, line)) {
        if (line.compare("## nameLib") == 0)
            continue;
        if (line.compare("## nameLib_end") == 0)
            break;
        if(line.find(libToGet) != std::string::npos) {
            toGet = line;
            break;
        }
    }
    dlclose(_libhandle);
    getGraphicLibs(toGet.c_str());
}

void core::Core::getGames(void)
{
    char *error;
    std::ifstream fd(_configFile);
    std::string libName;
    std::string funcName;
    std::string line;
    game::IGame* (*getGame)();
    game::IGame* game;

    while (std::getline(fd, line))
        if (line.compare("## nameGame") == 0)
            break;
    while (std::getline(fd, line)) {
        if (line.compare("## nameGame_end") == 0)
            break;
        std::ifstream exist(line);
        if (!exist)
            continue;
        libName = getLibName(line.c_str());
        funcName = getFunctionName(libName);
        _handles.push_back(dlopen(line.c_str(), RTLD_LAZY));
        if (!_handles[_handles.size() - 1])
            throw Error(std::cerr, dlerror());
        getGame = (game::IGame* (*)()) dlsym(_handles[_handles.size() - 1], funcName.c_str());
        if ((error = dlerror()))
            throw Error(std::cerr, error);
        game = (game::IGame*) getGame();
        _game.emplace(libName, game);
        _game[libName] = game;
    }
}

void core::Core::writeScore(void)
{
    std::ifstream fd(_scoreFile);
    std::string line;
    std::string temp = "## " + _currentGame;
    std::vector<std::string> content;
    std::string playerName = _graph->GetName();
    std::string score = std::to_string(_game[_currentGame]->getScore());
    std::string toWrite = playerName.append(" " + score);

    while (std::getline(fd, line))
        content.push_back(line);
    fd.close();
    for (std::vector<std::string>::iterator it = content.begin(); it < content.end(); it++)
        if (it->find(temp) != std::string::npos) {
            content.emplace(it + 1, toWrite);
            break;
        }
    std::ofstream fdw(_scoreFile);
    for (std::size_t i = 0; i != content.size(); i++) {
        fdw << content[i];
        fdw << std::endl;
    }
}

std::string core::Core::getCommand(void)
{
    switch (_graph->GetKey()) {
        case lib::S :
            return "down";
        case lib::Q :
            return "left";
        case lib::D :
            return "right";
        case lib::Z :
            return "up";
        case lib::backspace :
            return "menu";
        case lib::arrowDown :
            return "nextLib";
        case lib::arrowUp :
            return "prevLib";
        case lib::arrowLeft :
            return "prevGame";
        case lib::arrowRight :
            return "nextGame";
        case lib::escape :
            return "exit";
        case lib::space :
            return "restart";
    }
    return "";
}

void core::Core::displayMenu() noexcept
{
    std::string line;
    std::string gameName;
    std::ifstream fd(_scoreFile);
    std::vector<std::string> graph = getLibs(_configFile);
    std::vector<std::string> games;
    std::vector<std::string> scores;
    std::map<std::string, game::IGame*>::iterator itgame;
    int number = 0;
    int currentLibNbr = -1;

    for (itgame = _game.begin(); itgame != _game.end(); itgame++)
        games.push_back(itgame->first);
    if (fd) {
        for (int check = 0; std::getline(fd, line);) {
            if (line.compare(0, 2, "##") == 0) {
                check++;
                gameName = line.append("\t\t");
                gameName = gameName.substr(3);
                continue;
            }
            if (check % 2 != 0) {
                std::string temp = gameName;
                scores.push_back(temp.append(line));
                int pos = scores[scores.size() - 1].find(" ");
                scores[scores.size() - 1][pos] = '\t';
            }
            else
                continue;
        }
    }
    for (std::size_t i = 0; i != graph.size(); i++)
        if (graph[i].compare(_currentLib) == 0) {
            currentLibNbr = i;
            break;
        }
    while (_currentGame.empty() || _player.empty()) {
        if (!_graph->GetStatus())
            break;
        line = getCommand();
        if (line.compare("nextLib") == 0) {
            currentLibNbr++;
            if ((std::size_t)currentLibNbr >= graph.size())
                currentLibNbr = 0;
            getNewLib(graph[currentLibNbr]);
        }
        if (line.compare("prevLib") == 0) {
            currentLibNbr--;
            if (currentLibNbr < 0)
                currentLibNbr = graph.size() - 1;
            getNewLib(graph[currentLibNbr]);
        }
        number = _graph->Menu(games, graph, scores);
        if (number == -1)
            continue;
        _currentGame = games[number];
        _player = _graph->GetName();
    }
}

void core::Core::loop() noexcept
{
    std::string command;
    std::string lastDirection;
    std::vector<std::string> graph = getLibs(_configFile);
    int currentLibNbr = -1;

    for (std::size_t i = 0; i != graph.size(); i++)
        if (graph[i].compare(_currentLib) == 0) {
            currentLibNbr = i;
            break;
        }
    if (_currentGame.empty())
        displayMenu();
    while (_graph->GetStatus()) {
        if (_game[_currentGame]->getOver() != 0) {
            writeScore();
            _game[_currentGame]->reset();
            _currentGame = "";
            lastDirection = "";
            displayMenu();
            continue;
        }
        _graph->Game(_game[_currentGame]->getMap());
        _graph->DisplayScore(_game[_currentGame]->getScore());
        command = getCommand();
        if (command.compare("exit") == 0)
            break;
        if (command.compare("menu") == 0) {
            _currentGame = "";
            displayMenu();
            continue;
        }
        if (command.compare("restart") == 0) {
            _game[_currentGame]->reset();
            lastDirection = "";
        }
        if (command.compare("nextLib") == 0) {
            currentLibNbr++;
            if ((std::size_t)currentLibNbr >= graph.size())
                currentLibNbr = 0;
            getNewLib(graph[currentLibNbr]);
        }
        if (command.compare("prevLib") == 0) {
            currentLibNbr--;
            if (currentLibNbr < 0)
                currentLibNbr = graph.size() - 1;
            getNewLib(graph[currentLibNbr]);
        }
        if (command.compare("right") == 0 || command.compare("left") == 0 ||
            command.compare("down") == 0 || command.compare("up") == 0)
            lastDirection = command;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        _game[_currentGame]->play(lastDirection);
    }
}

core::Core::Core(int const ac, char const **av)
{
    std::string line;

    _configFile = "./lib/config.txt";
    _scoreFile = "./lib/score.txt";
    if (ac != 2)
        throw Error(std::cerr, "Invalid number of arguments.\n\nUSAGE:\n    ./arcade ./lib/arcade_[name of your graphic lib].so");
    std::ifstream fd(_configFile);
    if (!fd)
        throw Error(std::cerr, "Config file is not found.");
    while (std::getline(fd, line)) {
        if (line.compare("## nameLib_end") == 0)
            throw Error(std::cerr, (std::string) av[1] + " is not compatible or does not exist");
        if (line.compare(av[1]) == 0)
            break;
    }
    fd.close();
    _currentGame = "";
    _player = "";
}

core::Core::~Core() noexcept
{
    for (std::size_t i = 0; i != _handles.size(); i++)
        dlclose(_handles[i]);
}