/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** IObject.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace arcade {
    class IObject {
        enum Type {
            PLAYER,
            MOB,
            OBS,
            BONUS
        };
        public:
            IObject(float posx, float posy, float size, std::string path) :
            _posx(posx), _posy(posy), _size(size), _path(path) {};
            ~IObject() {};

            float _posx;
            float _posy;
            float _size;
            std::string _path;
    };
}