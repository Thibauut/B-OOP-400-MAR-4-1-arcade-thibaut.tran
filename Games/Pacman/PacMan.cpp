/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** pacman.cpp
*/

#include "PacMan.hpp"

Arcade::PacManGame::PacManGame()
{
    this->_info = "PacMan";
}

Arcade::PacManGame::~PacManGame() = default;

std::string Arcade::PacManGame::getInfo()
{
    return this->_info;
}
