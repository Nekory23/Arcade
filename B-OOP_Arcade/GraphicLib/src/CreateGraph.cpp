/*
** EPITECH PROJECT, 2021
** B-OOP_Arcade
** File description:
** CreateGraph
*/

#include "Sfml.hpp"
#include "Ncurses.hpp"
#include "Sdl2.hpp"

extern "C" {
    lib::ILibGraph *createSfml() {
        return new lib::Sfml();
    }
}

extern "C" {
    lib::ILibGraph *createNcurses() {
        return new lib::Ncurses();
    }
}

extern "C" {
    lib::ILibGraph *createSdl2() {
        return new lib::Sdl2();
    }
}