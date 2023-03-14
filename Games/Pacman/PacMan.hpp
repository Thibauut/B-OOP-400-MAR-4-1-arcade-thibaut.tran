/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** pacman.hpp
*/

#pragma once

#include "../IGame.hpp"

namespace Arcade {
    class PacManGame: public IGame {
        public:
            PacManGame();
            ~PacManGame();
            std::string getInfo();

        protected:
            std::string _info;
    };
}