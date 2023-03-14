/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"
#include "../Interfaces/IGame.hpp"

class Core : public IDisplayModule {
    public:
        Core();
        Core(std::string name) : _name(name) {};
        ~Core();

        // IDisplayModule
        void init() override;
        void stop() override;
        void clear() override;
        void refresh() override;
        const std::string &getName() const override { return _name; };

        // Setters
        void setDisplay(IDisplayModule *display);
        void setGame(IGame *game);

        // Getters
        IDisplayModule *getDisplay() const;
        IGame *getGame() const;

    protected:
        IDisplayModule *_currentDisplay;
        IGame *_currentGame;
        std::string _name;
};