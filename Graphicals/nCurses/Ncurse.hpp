/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Ncurse.hpp
*/

#pragma once

#include "../../Interfaces/IDisplayModule.hpp"
#include <ncurses.h>

class Ncurses: public arcade::IDisplayModule {
    public:
        enum STATES {
            MENU,
            GAME,
            SETTINGS,
            EXIT
        };
        Ncurses();
        ~Ncurses();

        void init() override;
        arcade::Input handleEvent() override;
        void refreshw(arcade::AllObjects *AllObjects) override;
        void menu() override;
        void drawBackground(const std::string &background) override;
        void drawElement(arcade::Object *object) override;
        void stop() override;
        void clear() override;
        const std::string &getName() const override { return _info; }
        bool isRunning() const override { return true; };
        void displayScore(int score) override;
        void playSound(const std::string &path, int volume, bool loop) override;

        int _state;
        std::string _info;
};
