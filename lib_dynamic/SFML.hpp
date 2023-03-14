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
        void refresh() override;
        bool isRunning() const override { return true; };
        const std::string &getName() const override { return "toto"; }

        std::string _info;
        sf::Font _font;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Sprite _background;
};

// class SFML: public IDisplayModule {
//     public:
//         SFML() {
//             entryPoint();
//         };
//         ~SFML();

//         void init() override;
//         void stop() override;
//         void clear() override;
//         void refresh() override;

//         int entryPoint() override;

//         void drawSprite(int x, int y, const std::string &path, int width, int height);
// };