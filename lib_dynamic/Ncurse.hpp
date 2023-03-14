/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Ncurse.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"
#include <ncurses.h>

class Ncurses: public IDisplayModule {
    public:
        Ncurses();
        ~Ncurses();

        void init() override;
        void stop() override;
        void clear() override {};
        int refresh() override;
        bool isRunning() const override { return _isRunning; };
        const std::string &getName() const { return "toto"; };

        int handleEvent();

    private:
        bool _isRunning;
};
