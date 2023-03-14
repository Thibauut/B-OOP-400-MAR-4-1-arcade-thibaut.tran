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

class Core : public IDisplayModule{
    public:
        Core() {};
        Core(std::string name, std::string path) : _name(name) { DLLoader <IDisplayModule> dlloader(path);};
        ~Core() {};

        // IDisplayModule
        void init() override {};
        void stop() override {};
        void clear() override {};
        void refresh() override {};
        bool isRunning() const override { return true; };

        void run() {
            _currentDisplay->init();
            setDisplay(dlloader.getInstance("entryPoint"));
            // _currentGame->init();
            while (_currentDisplay->isRunning()) {
                _currentDisplay->clear();
                // _currentGame->update();
                _currentDisplay->refresh();
            }
            _currentDisplay->stop();
            // _currentGame->stop();
        };

        const std::string &getName() const override { return _name; };
        virtual int entryPoint() override {return 0; };

        // Setters
        void setDisplay(IDisplayModule *display) { _currentDisplay = display; };
        void setGame(IGame *game) { _currentGame = game; };

        // Getters
        IDisplayModule *getDisplay() const { return _currentDisplay; };
        IGame *getGame() const { return _currentGame;};

    protected:
        DLLoader <IDisplayModule> dlloader;
        IDisplayModule *_currentDisplay;
        IGame *_currentGame;
        std::string _name;
        std::string _info;
};