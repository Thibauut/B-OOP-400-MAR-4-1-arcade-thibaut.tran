/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** IDisplay.hpp
*/

#pragma once

#include <string>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <sstream>

class IDisplayModule {
    public :
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual void clear() = 0;
        virtual void refresh() = 0;
        virtual int entryPoint() = 0;
        virtual bool isRunning() const = 0;
        virtual const std::string &getName() const = 0;

        // //information about the library (name)
        // virtual std::string getInfo() = 0;

        // // create the window
        // virtual void createWindow() = 0;

        // // handle the event
        // virtual void handleEvent() = 0;

        // // create the user menu
        // virtual void createMenu() = 0;

        // // destroy the window
        // virtual void destroyWindow() = 0;

        // // draw all the elements
        // virtual void draw() = 0;
};