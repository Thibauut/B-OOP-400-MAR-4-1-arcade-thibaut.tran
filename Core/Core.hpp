/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"
#include "../Interfaces/IGame.hpp"
#include "../dlloader/dlloader.hpp"

class Core {
    public:
        Core() {};
        ~Core() {};

        void run(DLLoader <IDisplayModule> dl) {
            setDisplay(dl.getInstance("entryPoint"));
            _currentDisplay->init();
            while (_currentDisplay->isRunning()) {
                _currentDisplay->clear();
                _currentDisplay->refresh();
            }
            _currentDisplay->stop();
        };


        // Setters
        void setDisplay(IDisplayModule *display) { _currentDisplay = display; };
        void setGame(IGame *game) { _currentGame = game; };

        // Getters
        IDisplayModule *getDisplay() const { return _currentDisplay; };
        IGame *getGame() const { return _currentGame;};

    protected:
        IDisplayModule *_currentDisplay;
        IGame *_currentGame;
        std::string _info;
};