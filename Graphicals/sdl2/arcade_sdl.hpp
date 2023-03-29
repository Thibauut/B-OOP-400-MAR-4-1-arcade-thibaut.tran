/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.hpp
*/

#pragma once

#include "../../Interfaces/IDisplayModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

namespace arcade {
    class SDL2: public IDisplayModule {
        public:
            enum STATES {
                MENU,
                GAME,
                SETTINGS,
                EXIT
            };
            SDL2();
            ~SDL2();

            void init() override;
            arcade::Input handleEvent() override;
            void refreshw(arcade::AllObjects *AllObjects) override;
            void menu() override;
            void drawBackground(const std::string &background) override;
            void drawElement(arcade::Object *object) override;
            void stop() override;
            void clear() override {};
            const std::string &getName() const override { return _info; }
            bool isRunning() const override { return true; };
            void displayScore(int score) override;
            void playSound(const std::string &path, int volume, bool loop) override;

            int _state;
            std::string _info;
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            TTF_Font *_font;
            SDL_Event *_event;
            SDL_Surface *_background;
            SDL_Texture *_backgroundTexture;
            SDL_Rect _backgroundRect;
            SDL_Texture *_score;
            SDL_Rect _scoreRect;
            // sf::Sprite _backgroundGame;
            // sf::Texture _backgroundGameTexture;
            // sf::Text _title;
            // sf::Clock _clock;
            // sf::IntRect _rectBackground;
            // sf::Sprite _pacmanBt;
            // sf::Texture _pacmanBtTexture;
            // sf::Sprite _snakeBt;
            // sf::Texture _snakeBtTexture;
            // sf::Sprite _quitBt;
            // sf::Texture _quitBtTexture;
            // sf::Music _music;

    };
}
