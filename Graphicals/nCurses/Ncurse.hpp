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
        Ncurses();
        ~Ncurses();

        void init() override;
        void stop() override;
        void clear() override {};
        void menu() override {};
        void displayScore(int score) override {};
        void playSound(const std::string &path, int volume, bool loop) override {};
        void drawBackground(const std::string &background) override {};
        void drawElement(arcade::Object *object) override {};
        arcade::Input handleEvent() override;
        int refresh(arcade::AllObjects *AllObjects) override;
        bool isRunning() const override { return _isRunning; };
        const std::string &getName() const override { return "toto"; };

        int handleKeys();

        // int handleEvent();

    private:
        bool _isRunning;
};
