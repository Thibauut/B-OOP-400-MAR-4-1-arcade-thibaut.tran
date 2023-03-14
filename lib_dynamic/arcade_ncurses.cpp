/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Ncurse.cpp
*/

#include "Ncurse.hpp"

extern "C" void __attribute__((constructor)) init_ncurses() {
    printf("[arcade_ncurses] Loading ncurses library...\n");
    Ncurses *ncurses = new Ncurses();
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[arcade_ncurses] entryPoint ncurses library\n");
    return new Ncurses();
}

extern "C" void __attribute__((destructor)) clean_ncurses() {
    printf("[arcade_ncurses] ncurses closing...\n");
}

Ncurses::Ncurses()
{
    _isRunning = true;
}

Ncurses::~Ncurses() {};

// extern "C" std::string Ncurses::getInfo()
// {
//     return _info;
// }

// extern "C" IDisplayModule *Ncurses::entryPoint()
// {
//     return this;
// }

void Ncurses::init()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}

// void Ncurses::createMenu()
// {
// }

int Ncurses::handleEvent()
{
    int ch = getch();
    if (ch == 27)
        return (1);
    return (0);
}

void Ncurses::stop()
{
    endwin();
}

int Ncurses::refresh()
{
    if (handleEvent() == 1)
        return (2);
    clear();
    mvprintw(0, 0, "Hello World !!!");
    refresh();
    return (0);
}
