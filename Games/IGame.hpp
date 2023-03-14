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

using namespace std;

namespace Arcade {
    class IGame {
        public:
            virtual ~IGame() = default;
            virtual std::string getInfo() = 0;
    };
}