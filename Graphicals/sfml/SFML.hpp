/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.hpp
*/

#pragma once

#include "../../Interfaces/IDisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace arcade {
    class SFML: public IDisplayModule {
        public:
            enum STATES {
                MENU,
                GAME,
                SETTINGS,
                PAUSE,
                TUTORIAL,
                EXIT
            };
            SFML();
            ~SFML();

            void init() override;
            arcade::Input handleEvent() override;
            void refreshw(arcade::AllObjects *AllObjects) override;
            void menu() override;
            void pauseMenu() override;
            void drawBackground(const std::string &background) override;
            void drawElement(arcade::Object *object) override;
            void stop() override;
            void clearw() override {};
            const std::string &getName() const override { return _info; }
            bool isRunning() const override { return true; };
            void displayScore(int score) override;
            void playSound(const std::string &path, int volume, bool loop) override;
            void animObject(Object *object, sf::Sprite *sprite);

            int _state;
            std::string _info;
            sf::Font _font;
            sf::RenderWindow *_window;
            sf::Event _event;
            sf::Sprite _background;
            sf::Texture _backgroundTexture;
            sf::Sprite _backgroundGame;
            sf::Texture _backgroundGameTexture;

            sf::Sprite _backgroundTuto;
            sf::Texture _backgroundTutoTexture;

            sf::Text _title;
            sf::Clock _clock;
            sf::IntRect _rectBackground;
            sf::Sprite _pacmanBt;
            sf::Texture _pacmanBtTexture;
            sf::Sprite _snakeBt;
            sf::Texture _snakeBtTexture;
            sf::Sprite _sftBt;
            sf::Texture _sftBtTexture;
            sf::Sprite _quitBt;
            sf::Texture _quitBtTexture;
            sf::Text _score;
            sf::Music _music;
            sf::Clock _clockAnim;

            int _selectedButton;
            sf::RectangleShape _buttonPACMAN;
            sf::RectangleShape _buttonSNAKE;
            sf::RectangleShape _buttonSFT;
            sf::RectangleShape _buttonQUIT;


            int _selectedButtonPause;
            sf::RectangleShape _buttonRESUME;
            sf::Sprite _resumeBt;
            sf::Texture _resumeBtTexture;

            sf::RectangleShape _buttonMENU;
            sf::Sprite _menuBt;
            sf::Texture _menuBtTexture;

            sf::RectangleShape _buttonSWITCHLIB;
            sf::Sprite _switchLibBt;
            sf::Texture _switchLibBtTexture;

            sf::RectangleShape _buttonEXIT;
            sf::Sprite _exitBt;
            sf::Texture _exitBtTexture;

            sf::Sprite _backgroundPause;
            sf::Texture _backgroundPauseTexture;
    };
}

