/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** IDisplayModule.hpp
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
#include "IGame.hpp"

using namespace std;

namespace arcade {
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void init() = 0;
            virtual void stop() = 0;
            virtual void clearw() = 0;
            virtual void menu() = 0;
            virtual void refreshw(arcade::AllObjects *AllObjects) = 0;
            virtual void drawBackground(const std::string &background) = 0;
            virtual void drawElement(arcade::Object *object) = 0;
            virtual void displayScore(int score) = 0;
            virtual arcade::Input handleEvent() = 0;
            virtual bool isRunning() const = 0;
            virtual const std::string &getName() const = 0;
            virtual void playSound(const std::string &path, int volume, bool loop) = 0;
    };
}

