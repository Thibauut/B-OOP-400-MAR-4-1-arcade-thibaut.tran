/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.cpp
*/

#include "Core.hpp"

void Core::switchLibraryGraphical(DLLoader <arcade::IDisplayModule> dl, const char *lib)
{
    _currentDisplay->stop();
    dl.switchLibrary(lib);
    setDisplay(dl.getInstance("entryPoint"));
    _currentDisplay->init();
}

void Core::run(DLLoader <arcade::IDisplayModule> dl)
{
    setDisplay(dl.getInstance("entryPoint"));
    DLLoader <arcade::IGame> dlGame("lib/arcade_snake.so");
    setGame(dlGame.getInstance("entryPoint"));
    arcade::AllObjects *AllObjects = _currentGame->initMap();
    _currentDisplay->init();
    _currentGame->initGame();
    _currentDisplay->playSound(_currentGame->sound()[0]->_path, _currentGame->sound()[0]->_volume, _currentGame->sound()[0]->_loop);
    while (_currentDisplay->isRunning()) {
        _currentGame->handleEvent(_currentDisplay->handleEvent());
        _currentGame->update(AllObjects);

        if (_currentGame->gameOver()) {
            cout << "game over" << endl;
            cout << "score: " << _currentGame->getScore() << endl;
            break;
        }
        _currentDisplay->menu();
        _currentDisplay->drawBackground(_currentGame->getBackground());
        _currentDisplay->displayScore(_currentGame->getScore());
        int refresh = _currentDisplay->refresh(AllObjects);
        if (refresh == 1)
            switchLibraryGraphical(dl, "lib/arcade_ncurses.so");
        if (refresh == 2)
            switchLibraryGraphical(dl, "lib/arcade_sfml.so");
        // _currentDisplay->clear();
    }
    delete AllObjects;
    _currentDisplay->stop();
    delete _currentGame;
    delete _currentDisplay;
}