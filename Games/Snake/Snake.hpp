/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Snake.hpp
*/

#pragma once

#include "../../Interfaces/IGame.hpp"

namespace arcade {
    class SnakeGame: public IGame {
        public:
            SnakeGame();
            ~SnakeGame();

            int width_map = 32;
            int height_map = 17;

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
            int checkSnake(AllObjects *allObjects);

        protected:
            std::string _info;
            int _direction;
            int _lastDirection;
            std::vector<std::string> _map;
            int _score;
            bool _gameOver = false;
            float _speed = 0.1;
            std::vector<arcade::Sound*> _sound;

            bool _isLeft = false;
            bool _isRight = false;
            bool _isUp = false;
            bool _isDown = false;
    };
}