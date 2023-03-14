/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"

class arcade_sdl : public IDisplayModule {
    public:
        arcade_sdl() {
            entryPoint();
        };
        ~arcade_sdl();

        void init() override;
        void stop() override;
        void clear() override;
        void refresh() override;

        void entryPoint();

        void drawSprite(int x, int y, const std::string &path, int width, int height);
};