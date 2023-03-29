/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Object.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace arcade {
    class Object {
        public:
            enum Type {
                WALL,
                HEAD,
                BODY,
                EMPTY,
                CLYDE,
                INKY,
                BLINKY,
                PINKY,
                PACMAN,
                BOOST,
                FOOD
            };
            Object(float posx, float posy, float size, std::string path, Type type) :
            _posx(posx), _posy(posy), _size(size), _path(path), _type(type) {};
            ~Object() {};

            float _posx = 0;
            float _posy = 0;
            float _size;
            std::string _path;
            Type _type;
            int _lastDirection;
    };
}