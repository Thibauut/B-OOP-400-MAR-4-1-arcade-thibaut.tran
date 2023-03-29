/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** main.cpp
*/

#include <iostream>
#include "Core/Core.cpp"

void handle_error_argument(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./arcade [lib.so]" << std::endl;
        exit(84);
    }
}

int main(int ac, char **av)
{
    handle_error_argument(ac, av);

    DLLoader <arcade::IDisplayModule> dlloader;
    dlloader.switchLibrary(av[1]);

    Core *core = new Core();

    core->run(&dlloader);

    return (0);
}
