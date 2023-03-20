/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.hpp
*/

#pragma once

#include "../../Interfaces/IDisplayModule.hpp"
#include "../../Interfaces/Object.hpp"
#include "../../Interfaces/IGame.hpp"
#include <SFML/Graphics.hpp>

namespace arcade {
    class SFML: public IDisplayModule {
        public:
            enum STATES {
                MENU,
                GAME,
                SETTINGS,
                EXIT
            };
            SFML();
            ~SFML();

            void init() override;
            arcade::Input handleEvent() override;
            int refresh(arcade::AllObjects *AllObjects) override;
            void menu() override;
            void drawBackground(const std::string &background) override;
            void drawElement(arcade::Object *object) override;
            void stop() override;
            void clear() override {};
            const std::string &getName() const override { return _info; }
            bool isRunning() const override { return true; };

            int _state;
            std::string _info;
            sf::Font _font;
            sf::RenderWindow *_window;
            sf::Event _event;
            sf::Sprite _background;
            sf::Texture _backgroundTexture;
            sf::Sprite _backgroundGame;
            sf::Texture _backgroundGameTexture;
            sf::Text _title;
            sf::Clock _clock;
            sf::IntRect _rectBackground;
            sf::Sprite _pacmanBt;
            sf::Texture _pacmanBtTexture;
            sf::Sprite _snakeBt;
            sf::Texture _snakeBtTexture;
            sf::Sprite _quitBt;
            sf::Texture _quitBtTexture;
            bool _isRunning;

    };
}
