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
    _currentDisplay->stop();
    _currentDisplay->init();
    dl->switchLibrary(lib);
    setGame(dl->getInstance("entryPoint"));
    _allObjects = _currentGame->initMap();
    _currentGame->initGame();
}

void Core::checkInputs(arcade::Input input, DLLoader <arcade::IDisplayModule> *dl, DLLoader <arcade::IGame> *dlGame)
{
    if (input == arcade::Input::PAUSE_1 && _state == arcade::STATES::GAME) {
        _state = arcade::STATES::PAUSE;
        return;
    }
    if (input == arcade::Input::RESUME && _state == arcade::STATES::PAUSE) {
        _state = arcade::STATES::GAME;
        return;
    }
    if (input == arcade::Input::SWITCH_LIB) {
        if (_currentDisplay->getName() == "Ncurses")
            switchLibraryGraphical(dl, "lib/arcade_sdl.so");
        else
            switchLibraryGraphical(dl, "lib/arcade_ncurses.so");
    } else if (input == arcade::Input::SWITCH_GAME && _state == arcade::STATES::GAME) {
        if (_currentGame->getInfo() == "PacMan")
            switchLibraryGame(dlGame, "lib/arcade_snake.so");
        else
            switchLibraryGame(dlGame, "lib/arcade_pacman.so");
    } else if (input == arcade::Input::MENU_1) {
        _state = arcade::STATES::MENU;
    } else {
        _currentGame->handleEvent(input);
    }
}

void Core::checkInputsMenu(arcade::Input input, DLLoader <arcade::IDisplayModule> *dl, DLLoader <arcade::IGame> *dlGame)
{
    if (input == arcade::Input::SWITCH_LIB) {
        if (_currentDisplay->getName() == "Ncurses")
            switchLibraryGraphical(dl, "lib/arcade_sfml.so");
        else
            switchLibraryGraphical(dl, "lib/arcade_ncurses.so");
    } else if (input == arcade::Input::MENU_1) {
        _state = arcade::STATES::MENU;
    } else if (input == arcade::Input::PACMAN) {
        dlGame->switchLibrary("lib/arcade_pacman.so");
        setGame(dlGame->getInstance("entryPoint"));
        _allObjects = _currentGame->initMap();
        _currentGame->initGame();
        _state = arcade::STATES::GAME;
    } else if (input == arcade::Input::SNAKE) {
        dlGame->switchLibrary("lib/arcade_snake.so");
        setGame(dlGame->getInstance("entryPoint"));
        _allObjects = _currentGame->initMap();
        _currentGame->initGame();
        _state = arcade::STATES::GAME;
    } else if (input == arcade::Input::ESCAPE) {
        exit(0);
    }
}

void Core::run(DLLoader <arcade::IDisplayModule> *dl)
{
    setDisplay(dl->getInstance("entryPoint"));
    _currentDisplay->init();
    _state = arcade::STATES::MENU;
    DLLoader <arcade::IGame> dlGame;
    while (1) {
    // _currentDisplay->playSound(_currentGame->sound()[0]->_path, _currentGame->sound()[0]->_volume, _currentGame->sound()[0]->_loop);
        while (_state == arcade::STATES::GAME) {
            arcade::Input input = _currentDisplay->handleEvent();
            checkInputs(input, dl, &dlGame);
            _currentGame->update(_allObjects);

            if (_currentGame->gameOver()) {
                cout << "game over" << endl;
                cout << "score: " << _currentGame->getScore() << endl;
                _currentDisplay->stop();
                exit(0);
            }
            _currentDisplay->drawBackground(_currentGame->getBackground());
            _currentDisplay->displayScore(_currentGame->getScore());
            _currentDisplay->refreshw(_allObjects);
        }
        while (_state == arcade::STATES::PAUSE) {
            // _currentDisplay->pause();
            arcade::Input input = _currentDisplay->handleEvent();
            checkInputs(input, dl, &dlGame);
            // _currentDisplay->refreshw(_allObjects);
        }
        while (_state == arcade::STATES::MENU) {
            _currentDisplay->menu();
            arcade::Input input = _currentDisplay->handleEvent();
            checkInputsMenu(input, dl, &dlGame);
            _currentDisplay->refreshw(_allObjects);
        }
    }
    delete _allObjects;
    _currentDisplay->stop();
    delete _currentGame;
    delete _currentDisplay;
}