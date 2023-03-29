/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.cpp
*/

#include "Core.hpp"

void Core::switchLibraryGraphical(DLLoader <arcade::IDisplayModule> *dl, const char *lib)
{
    _currentDisplay->stop();
    delete _currentDisplay;
    dl->switchLibrary(lib);
    setDisplay(dl->getInstance("entryPoint"));
    _currentDisplay->init();
}

void Core::switchLibraryGame(DLLoader <arcade::IGame> *dl, const char *lib)
{
    // _currentGame->stop();
    delete _allObjects;
    delete _currentGame;
    dl->switchLibrary(lib);
    setGame(dl->getInstance("entryPoint"));
    _allObjects = _currentGame->initMap();
    _currentGame->initGame();
}

void Core::run(DLLoader <arcade::IDisplayModule> *dl)
{
    setDisplay(dl->getInstance("entryPoint"));
    DLLoader <arcade::IGame> dlGame("lib/arcade_pacman.so");
    setGame(dlGame.getInstance("entryPoint"));
    _allObjects = _currentGame->initMap();
    _currentDisplay->init();
    _currentGame->initGame();
    // _currentDisplay->playSound(_currentGame->sound()[0]->_path, _currentGame->sound()[0]->_volume, _currentGame->sound()[0]->_loop);
    while (_currentDisplay->isRunning()) {
        arcade::Input input = _currentDisplay->handleEvent();
        if (input == arcade::Input::SWITCH_LIB) {
            if (_currentDisplay->getName() == "Ncurses")
                switchLibraryGraphical(dl, "lib/arcade_sfml.so");
            else
                switchLibraryGraphical(dl, "lib/arcade_ncurses.so");
        } else if (input == arcade::Input::SWITCH_GAME) {
            if (_currentGame->getInfo() == "PacMan")
                switchLibraryGame(&dlGame, "lib/arcade_snake.so");
            else
                switchLibraryGame(&dlGame, "lib/arcade_pacman.so");
        } else {
            _currentGame->handleEvent(input);
        }
        _currentGame->update(_allObjects);

        if (_currentGame->gameOver()) {
            cout << "game over" << endl;
            cout << "score: " << _currentGame->getScore() << endl;
            break;
        }
        _currentDisplay->menu();
        _currentDisplay->drawBackground(_currentGame->getBackground());
        _currentDisplay->displayScore(_currentGame->getScore());
        _currentDisplay->refreshw(_allObjects);
    }
    delete _allObjects;
    _currentDisplay->stop();
    delete _currentGame;
    delete _currentDisplay;
}