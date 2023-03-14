/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Ncurse.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"

#include <ncurses.h>
#include <SFML/Graphics.hpp>

class Ncurses: public IDisplayModule {
        public:
        Ncurses();
        ~Ncurses();

        void init() override;
        void stop() override;
        void clear() override;
        void refresh() override;
        bool isRunning() const override { return true; };
        const std::string &getName() const;

        int entryPoint();

        std::string _info;
        sf::Font _font;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Sprite _background;
};
