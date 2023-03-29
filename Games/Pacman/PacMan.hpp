/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** pacman.hpp
*/

#pragma once

#include "../../Interfaces/IGame.hpp"

namespace arcade {
    class PacManGame: public IGame {
        public:
            PacManGame();
            ~PacManGame();

            int width_map = 32;
            int height_map = 18;

            arcade::AllObjects *initMap();
            void initGame();
            std::string getBackground();
            std::string getInfo();
            int handleEvent(arcade::Input input);
            void update(arcade::AllObjects *allObjects);
            bool gameOver();
            int getScore();
            void spawnBonus(AllObjects *allObjects);
            std::vector<arcade::Sound*> sound();

            void goLeft(AllObjects *allObjects);
            void goRight(AllObjects *allObjects);
            void goUp(AllObjects *allObjects);
            void goDown(AllObjects *allObjects);
            void keepMoving(AllObjects *allObjects);

            void clyde(AllObjects *allObjects);
            void blinky(AllObjects *allObjects);
            void pinky(AllObjects *allObjects);
            void inky(AllObjects *allObjects);

            void moveGhost(arcade::Object * _ghost, arcade::AllObjects *allObjects);
            bool isValidDirection(int x, int y, arcade::AllObjects *allObjects);
            void ghostMove(arcade::Object *_ghost, arcade::AllObjects *allObjects, int x, int y);

            std::string _info;
            int _direction = arcade::Input::ARROW_RIGHT;
            int _lastDirection;
            bool _validDir = false;
            int _moveFrame = 0;
            int verif = 1;

            bool _scatter = false;


            std::vector<std::string> _map;
            std::vector<std::string> _points;

            bool _gameOver = false;

            int _score;
            std::vector<arcade::Sound*> _sound;
            float _speed = 0.08;
    };
}