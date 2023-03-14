/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** IDisplay.hpp
*/

#pragma once

#include <string>

class IDisplayModule {
    public :
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual void clear() = 0;
        virtual void refresh() = 0;
        virtual void entryPoint() = 0;
        virtual const std::string &getName() const = 0;
};