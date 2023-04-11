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

namespace arcade
{
    class Animation
    {
        public:
            Animation(std::string path, int nbFrame, int frameRate, float width, float height, float x, float y, float restart) : _nbFrame(nbFrame), _frameRate(frameRate), _width(width), _height(height), _x(x), _y(y), _restart(restart) {};
            ~Animation(){};

            float _clock;
            float _restart;
            int _nbFrame;
            int _frameRate;
            bool _isAnimation = false;
            int _width, _height, _x, _y;
    };

    class Object
    {
        public:
            enum Type
            {
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
                FOOD,
                PLAYER_1,
                PLAYER_2
            };
            Object(float posx, float posy, float sizex, float sizey, std::string path, Type type, int life) : _posx(posx), _posy(posy), _sizex(sizex), _sizey(sizey), _path(path), _type(type), _life(life) {
                _animation = new Animation(path, 1, 0, 0, 0, 0, 0, 0);
            };
            Object(float posx, float posy, float sizex, float sizey, std::string path, Type type) : _posx(posx), _posy(posy), _sizex(sizex), _sizey(sizey), _path(path), _type(type), _life(100) {
                _animation = new Animation(path, 1, 0, 0, 0, 0, 0, 0);
            };
            Object(float posx, float posy, float size, std::string path, Type type) : _posx(posx), _posy(posy), _sizex(size), _sizey(size), _path(path), _type(type), _life(100) {
                _animation = new Animation(path, 1, 0, 0, 0, 0, 0, 0);
            };
            ~Object(){};

            float _posx = 0;
            float _posy = 0;
            float _sizex;
            float _sizey;
            std::string _path;
            Type _type;
            int _life;
            int _lastDirection;
            int _direction;
            Animation *_animation;
    };
}