/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** IGame.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "Object.hpp"
#include "AllObjects.hpp"
#include "../Tools/Input.hpp"
#include "../Tools/Sound.hpp"

using namespace std;

namespace arcade {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual arcade::AllObjects *initMap() = 0;
            virtual void initGame() = 0;
            virtual std::string getBackground() = 0;
            virtual std::string getInfo() = 0;
            virtual int handleEvent(arcade::Input input) = 0;
            virtual void update(arcade::AllObjects *allObjects) = 0;
            virtual bool gameOver() = 0;
            virtual int getScore() = 0;
            virtual void spawnBonus(arcade::AllObjects *allObjects) = 0;
            virtual std::vector<arcade::Sound*> sound() = 0;
    };
}