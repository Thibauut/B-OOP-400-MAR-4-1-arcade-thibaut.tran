/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.cpp
*/

#include <stdio.h>
#include "arcade_ncurses.hpp"


extern "C" void __attribute__((constructor)) init_ncurses() {
    printf("[arcade_ncurses] Loading ncurses library...\n");
}

extern "C" int entryPoint ()
{
    printf("[arcade_ncurses] Entry point for ncurses!\n");
    return 0;
}

extern "C" void __attribute__((destructor)) clean_ncurses() {
    printf("[arcade_ncurses] ncurses closing...\n");
}