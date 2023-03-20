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
    DLLoader <arcade::IDisplayModule> dlloader(av[1]);
    Core *core = new Core();
    core->run(dlloader);
    // std::string line;

    // std::cout << "ARKD > ";
    // while(getline(std::cin, line)) {
    //     if (line == "exit")
    //         break;
    //     else if (line == "sfml")
    //         dlloader.switchLibrary("lib/arcade_sfml.so");
    //     else if (line == "sdl")
    //         dlloader.switchLibrary("lib/arcade_sdl.so");
    //     else if (line == "ncurses")
    //         dlloader.switchLibrary("lib/arcade_ncurses.so");
    //     else if (line == "simulate")
    //         core->setDisplay(dlloader.getInstance("entryPoint"));
    //     else if (line == "commands")
    //         std::cout << "sfml | ncurses | sdl | simulate | exit" << std::endl;
    //     else
    //         std::cout << "Invalid command. Use \"commands\" to see commands" << std::endl;
    //     std::cout << "ARKD > ";
    // }

    return (0);
}
