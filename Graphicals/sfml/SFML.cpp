/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

using namespace arcade;

extern "C" void __attribute__((constructor)) init_sfml() {
    printf("[arcade_sfml] Loading sfml library...\n");
    SFML *sfml = new SFML();
}

extern "C" IDisplayModule *entryPoint()
{
    printf("[arcade_sfml] entryPoint sfml library\n");
   return new SFML();
}

extern "C" void __attribute__((destructor)) clean_sfml()
{
    printf("[arcade_sfml] sfml closing...\n");
}

arcade::SFML::SFML()
{
    _info = "SFML";
    _state = STATES::GAME;
}

arcade::SFML::~SFML() = default;

void arcade::SFML::menu()
{
    sf::Time elapsed = _clock.getElapsedTime();
    if (elapsed.asMilliseconds() > 100)
    {
        _rectBackground.left += 1920;
        if  (_rectBackground.left >= 11520)
            _rectBackground.left = 0,  _rectBackground.top += 1080;
        if  (_rectBackground.top >= 12960)
            _rectBackground.top = 0;
        _background.setTextureRect(_rectBackground);
        _clock.restart();
    }
}

void arcade::SFML::init()
{
    //window
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade - SFML", sf::Style::Resize | sf::Style::Close);
    _window->setFramerateLimit(60);

    //font
    _font.loadFromFile("assets/font/visitor.ttf");

    //title
    _title.setFont(_font);
    _title.setString("ARCADE");
    _title.setCharacterSize(270);
    _title.setPosition(530, 100);
    _title.setOutlineColor(sf::Color (106,90,205));
    _title.setOutlineThickness(10);

    //background
    _backgroundTexture.loadFromFile("assets/image/background.png");
    _background.setTexture(_backgroundTexture);
    _background.setPosition(0, 0);
    _background.setScale(1, 1);

    //anim background
    sf::IntRect rectBackground(0, 0, 1920, 1080);
    _rectBackground = rectBackground;
    _background.setTextureRect(_rectBackground);

    //pacman button
    _pacmanBtTexture.loadFromFile("assets/image/pacman_bt.png");
    _pacmanBt.setTexture(_pacmanBtTexture);
    _pacmanBt.setPosition(790, 600);
    _pacmanBt.setScale(0.4, 0.38);

    //snake button
    _snakeBtTexture.loadFromFile("assets/image/snake_bt.png");
    _snakeBt.setTexture(_snakeBtTexture);
    _snakeBt.setPosition(820, 700);
    _snakeBt.setScale(0.4, 0.38);

    //quit button
    _quitBtTexture.loadFromFile("assets/image/quit_bt.png");
    _quitBt.setTexture(_quitBtTexture);
    _quitBt.setPosition(850, 810);
    _quitBt.setScale(0.4, 0.38);
}

arcade::Input arcade::SFML::handleEvent()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window->close();
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
            return (arcade::Input::ESCAPE);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Left)
            return (arcade::Input::ARROW_LEFT);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Right)
            return (arcade::Input::ARROW_RIGHT);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up)
            return (arcade::Input::ARROW_UP);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down)
            return (arcade::Input::ARROW_DOWN);
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Space)
            return (arcade::Input::SPACE);
    }
    return (arcade::Input::NONE);
}

void arcade::SFML::stop()
{
    _window->close();
}

void arcade::SFML::drawBackground(const std::string &background)
{
    _backgroundGameTexture.loadFromFile(background);
    _backgroundGame.setTexture(_backgroundGameTexture);
    _backgroundGame.setPosition(0, 0);
    _backgroundGame.setScale(10, 10);
}

void arcade::SFML::drawElement(arcade::Object *object)
{
    if (object->_path == "") {
        sf::RectangleShape rect(sf::Vector2f(60, 60));
        rect.setPosition(object->_posx * 60, object->_posy * 60);
        rect.setFillColor(sf::Color::Black);
        _window->draw(rect);
    } else {
        sf::Texture texture;
        texture.loadFromFile(object->_path);
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(object->_posx * 60, object->_posy * 60);
        sprite.setScale(7.5, 7.5);
        _window->draw(sprite);
    }
}

void arcade::SFML::displayScore(int score)
{
    _score.setFont(_font);
    _score.setString("Score: " + std::to_string(score));
    _score.setCharacterSize(70);
    _score.setPosition(30, -22);
}

int arcade::SFML::refresh(arcade::AllObjects *AllObjects)
{
    if (_state == STATES::MENU) {
        _window->draw(_background);
        _window->draw(_title);
        _window->draw(_pacmanBt);
        _window->draw(_snakeBt);
        _window->draw(_quitBt);
    }
    if (_state == STATES::GAME) {
        _window->draw(_backgroundGame);
        for (auto &i : AllObjects->_objects)
            drawElement(i);
        for (auto &i : AllObjects->_player)
            drawElement(i);
        for (auto &i : AllObjects->_food)
            drawElement(i);
        _window->draw(_score);
    }
    if (_state == STATES::SETTINGS) {

    }
    if (_state == STATES::EXIT) {
        _window->close();
    }
    _window->display();
    return (0);
}

void arcade::SFML::playSound(const std::string &path, int volume, bool loop)
{
    if (!_music.openFromFile(path)) {
        std::cerr << "Erreur lors du chargement de " << path << std::endl;
        return;
    }
    _music.setVolume(volume);
    _music.setLoop(loop);
    _music.play();
}
