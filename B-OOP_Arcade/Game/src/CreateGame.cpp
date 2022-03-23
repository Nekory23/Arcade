/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** CreateGame
*/

#include "Pacman.hpp"
#include "Snake.hpp"

extern "C" {
    game::IGame *createPacman() {
        return new game::Pacman ();
    }
}

extern "C" {
    game::IGame *createNibbler() {
        return new game::Snake ();
    }
}