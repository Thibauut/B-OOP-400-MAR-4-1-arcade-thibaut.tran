/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** test.cpp
*/

#include "Library/SFML/SFML.cpp"
#include "Library/Ncurses/Ncurse.cpp"

using namespace Arcade;

int main()
{
    // Arcade::SFML *sfml = new Arcade::SFML();

    // sfml->createWindow();
    // while (sfml->_window.isOpen()) {
    //     while (sfml->_window.pollEvent(sfml->_event)) {
    //         sfml->handleEvent();
    //     }
    //     sfml->draw();
    // }
    // sfml->destroyWindow();
    // delete sfml;

    Arcade::Ncurses *ncurses = new Arcade::Ncurses();

    ncurses->createWindow();
    while (1) {
        ncurses->handleEvent();
        ncurses->draw();
    }
    ncurses->destroyWindow();
    delete ncurses;
    return 0;
}