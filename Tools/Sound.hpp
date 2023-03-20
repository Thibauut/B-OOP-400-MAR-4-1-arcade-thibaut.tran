/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Sound.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>


namespace arcade {
    class Sound {
        public:
            enum Type {
                BACK_SOUND,
                EAT_SOUND,
                DEATH_SOUND
            };

            Sound(std::string path, Type type, bool loop, int volume) :
            _path(path), _type(type), _loop(loop), _volume(volume) {};
            ~Sound() {};

            std::string _path;
            Type _type;
            bool _loop;
            int _volume;
    };
}