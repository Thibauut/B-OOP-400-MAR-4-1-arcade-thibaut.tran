/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.cpp
*/

#include <stdio.h>
#include "arcade_sdl.hpp"

extern "C" void __attribute__((constructor)) init_arcade_sdl() {
    printf("[arcade_sdl] Loading sdl library...\n");
}

extern "C"  IDisplayModule *entryPoint()
{
    printf("[arcade_sdl] Entry point for sdl!\n");
    return new arcade_sdl();
}

extern "C" void __attribute__((destructor)) clean_sdl() {
    printf("[arcade_sdl] sdl closing...\n");
}