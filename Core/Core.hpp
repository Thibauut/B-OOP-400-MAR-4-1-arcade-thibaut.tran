/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"
#include "../Interfaces/IGame.hpp"
#include "../Tools/dlloader/dlloader.hpp"
#include "../Interfaces/AllObjects.hpp"

class Core {

    public:
        Core() { _state = arcade::STATES::MENU; };
        ~Core() {};

        void switchLibraryGraphical(DLLoader <arcade::IDisplayModule> *dl, const char *lib);
        void switchLibraryGame(DLLoader <arcade::IGame> *dl, const char *lib);
        void run(DLLoader <arcade::IDisplayModule> *dl);
        void checkInputs(arcade::Input input, DLLoader <arcade::IDisplayModule> *dl, DLLoader <arcade::IGame> *dlGame);
        void checkInputsMenu(arcade::Input input, DLLoader <arcade::IDisplayModule> *dl, DLLoader <arcade::IGame> *dlGame);

        // Setters
        void setDisplay(arcade::IDisplayModule *display) { _currentDisplay = display; };
        void setGame(arcade::IGame *game) { _currentGame = game; };
        void setState(arcade::STATES state) { _state = state; };

        // Getters
        arcade::STATES getState() const { return _state; };
        arcade::IDisplayModule *getDisplay() const { return _currentDisplay; };
        arcade::IGame *getGame() const { return _currentGame;};

    protected:
        arcade::STATES _state;
        arcade::AllObjects *_allObjects;
        arcade::IDisplayModule *_currentDisplay;
        arcade::IGame *_currentGame;
        std::string _info;

};