/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** StreetFighTek.hpp
*/

#pragma once
#include "../../Interfaces/IGame.hpp"

namespace arcade {
    class StreetFighTek : public arcade::IGame {
        public:
            StreetFighTek();
            ~StreetFighTek();

            int width_map = 32;
            int height_map = 17;

            arcade::AllObjects *initMap();
            void initGame();
            std::string getBackground();
            std::string getInfo();
            int handleEvent(arcade::Input input);
            void update(arcade::AllObjects *allObjects);
            bool gameOver();
            void spawnBonus(arcade::AllObjects *allObjects) {};
            int getScore();
            std::vector<arcade::Sound*> sound() {};
            void goLeft(Object *player);
            void goUp(Object *player, Object *jump);
            void goDown(Object *player);
            void goRight(Object *player);
            void hit(Object *player1, Object *player2);
            void initAnimation(arcade::Object *player);
            void checkEndAttack(Object *player);
            Object *initLifeBar(float x, float y);
            Object *initLifeBar2(float x, float y);
            void initLifeBarAnimation(Object *lifebar);
            Object *initJump();


            Object *init_player_1();
            Object *init_player_2();

        protected:
            std::string _info;
            int _direction1;
            int _direction2;
            std::vector<std::string> _map;
            int _score;
            bool _gameOver;
            float _speed;
            std::vector<arcade::Sound*> _sound;
    };
};