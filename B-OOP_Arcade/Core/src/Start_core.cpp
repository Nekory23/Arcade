/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Start_core
*/

#include "Error.hpp"
#include "Core.hpp"
#include "Arcade.hpp"

int startCore(int const ac, char const **av)
{
    int ret = SUCCESS;

    try {
        core::Core core(ac, av);
        core.getGraphicLibs(av[1]);
        core.getGames();
        core.loop();
    }
    catch (Error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        ret = ERROR;
    }
    catch (...) {}
    return ret;
}