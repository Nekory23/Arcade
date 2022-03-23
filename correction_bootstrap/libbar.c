/*
** EPITECH PROJECT, 2021
** Bootstrap_Arcade
** File description:
** lib
*/

#include <stdio.h>

int test;

__attribute__((constructor))
void setup(void) {
    test = 56;
    printf("[bar] : Setup complete\n");
}

__attribute__((destructor))
void destruct(void) {
    printf("[bar] : Deleted\n");
}

void entryPoint(void) {
    printf("hey there I am the entry point of bar !\n");
}
