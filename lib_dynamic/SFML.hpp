/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"
#include <SFML/Graphics.hpp>

class SFML: public IDisplayModule {
    public:
        SFML();
        ~SFML();

        void init() override;
        void stop() override;
        void clear() override {};
        int refresh() override;
        bool isRunning() const override { return _isRunning; };
        const std::string &getName() const override { return "toto"; }

        std::string _info;
        sf::Font _font;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Sprite _background;

    private:
        bool _isRunning;
};