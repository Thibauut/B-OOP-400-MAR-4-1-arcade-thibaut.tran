/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Objects.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <list>

#include "Object.hpp"

namespace arcade {
    class AllObjects {
        public:
            AllObjects() {};
            ~AllObjects() {};

            std::vector<std::string> _map;
            std::list<arcade::Object *> _player;
            std::vector<arcade::Object *> _objects;
            std::vector<arcade::Object *> _food;
    };
}
