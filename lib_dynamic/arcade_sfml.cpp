/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.cpp
*/

#include <stdio.h>
#include "arcade_sfml.hpp"


extern "C" void __attribute__((constructor)) init_arcade_sfml() {
    printf("[arcade_sfml] Loading sfml library...\n");
}

extern "C" int entryPoint()
{
    printf("[arcade_sfml] Entry point for sfml!\n");
    return 0;
}

extern "C" void __attribute__((destructor)) clean_sfml() {
    printf("[arcade_sfml] sfml closing...\n");
}