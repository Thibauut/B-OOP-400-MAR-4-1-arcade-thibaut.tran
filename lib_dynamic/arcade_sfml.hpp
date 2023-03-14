/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.hpp
*/

#pragma once

#include "../Interfaces/IDisplayModule.hpp"

class arcade_sfml : public IDisplayModule {
    public:
        arcade_sfml() {
            entryPoint();
        };
        ~arcade_sfml();

        void init() override;
        void stop() override;
        void clear() override;
        void refresh() override;

        void entryPoint();

        void drawSprite(int x, int y, const std::string &path, int width, int height);
};