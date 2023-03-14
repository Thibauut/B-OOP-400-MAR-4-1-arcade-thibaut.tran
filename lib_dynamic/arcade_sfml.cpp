/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

SFML::SFML() {

}

SFML::~SFML() {

}

extern "C" void __attribute__((constructor)) init_sfml() {
    printf("[arcade_sfml] Loading sfml library...\n");
    SFML *sfml = new SFML();
}

// extern "C" std::string SFML::getInfo()
// {
//     return _info;
// }

extern "C" int entryPoint()
{
    printf("[arcade_sfml] entryPoint sfml library\n");
   return 0;
}

// void SFML::createWindow()
// {
//     sf::VideoMode videoMode;
//     videoMode.width = 1920;
//     videoMode.height = 1080;

//     _window.create(videoMode, "Arcade - SFML", sf::Style::Resize | sf::Style::Close);
//     _window.setFramerateLimit(60);

//     sf::Texture backgroundTexture;
//     backgroundTexture.loadFromFile("Library/assets/t.png");
//     _background.setTexture(backgroundTexture);
//     _background.setPosition(0, 0);
//     _background.setScale(1, 1);
// }

// void SFML::createMenu()
// {
// }

// void SFML::handleEvent()
// {
//     if (_event.type == sf::Event::Closed)
//         _window.close();
// }

// void SFML::destroyWindow()
// {
//     _window.close();
// }

// void SFML::refreshWindow()
// {
//     _window.draw(_background);
//     _window.display();
// }

extern "C" void __attribute__((destructor)) clean_sfml() {
    printf("[arcade_sfml] sfml closing...\n");
}