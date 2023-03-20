/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** pacman.hpp
*/

#pragma once

#include "../../Interfaces/IGame.hpp"

namespace Arcade {
    class PacManGame: public arcade::IGame {
        public:
            PacManGame();
            ~PacManGame();
            std::string getInfo();

        protected:
            std::string _info;
    };
}