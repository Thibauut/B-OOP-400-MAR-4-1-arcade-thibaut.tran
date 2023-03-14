/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Ncurse.cpp
*/

#include "Ncurse.hpp"

extern "C" void __attribute__((constructor)) init_ncurses() {
    printf("[arcade_ncurses] Loading ncurses library...\n");
    // SFML *sfml = new SFML();
}

extern "C"  IDisplayModule *entryPoint()
{
    printf("[arcade_ncurses] entryPoint ncurses library\n");
    return new Ncurses();
}

extern "C" void __attribute__((destructor)) clean_ncurses() {
    printf("[arcade_ncurses] ncurses closing...\n");
}

// Ncurses::Ncurses()
// {
//     _info = "Ncurses";
// }

// Ncurses::~Ncurses() = default;

// extern "C" std::string Ncurses::getInfo()
// {
//     return _info;
// }

// extern "C" IDisplayModule *Ncurses::entryPoint()
// {
//     return this;
// }

// void Ncurses::createWindow()
// {
//     initscr();
//     noecho();
//     cbreak();
//     keypad(stdscr, TRUE);
//     curs_set(0);
// }

// void Ncurses::createMenu()
// {
// }

// void Ncurses::handleEvent()
// {
//     int ch = getch();
// }

// void Ncurses::destroyWindow()
// {
//     endwin();
// }

// void Ncurses::draw()
// {
//     clear();
//     mvprintw(0, 0, "Hello World !!!");
//     refresh();
// }
