/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** SFML.cpp
*/

#include "SFML.hpp"

extern "C" void __attribute__((constructor)) init_arcade_sfml() {
    printf("[arcade_sfml] Loading library...\n");
    printf("[arcade_sfml] Library loaded !\n");
}

extern "C"  arcade::IDisplayModule *entryPoint()
{
    printf("[arcade_sfml] Entry point !\n");
    return new arcade::SFML();
}

extern "C" void __attribute__((destructor)) clean_sfml() {
    printf("[arcade_sfml] Closed !\n");
}

arcade::SFML::SFML()
{
    _info = "SFML";
    _state = STATES::MENU;
    _selectedButton = 0;
    _selectedButtonPause = 0;
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

    sf::Vector2i mousePosition = sf::Mouse::getPosition();


    sf::RectangleShape buttonPACMAN(sf::Vector2f(_pacmanBt.getGlobalBounds().width, _pacmanBt.getGlobalBounds().height));
    buttonPACMAN.setPosition(_pacmanBt.getPosition());
    _buttonPACMAN = buttonPACMAN;
    _buttonPACMAN.setTexture(&_pacmanBtTexture);

    sf::RectangleShape buttonSNAKE(sf::Vector2f(_snakeBt.getGlobalBounds().width, _snakeBt.getGlobalBounds().height));
    buttonSNAKE.setPosition(_snakeBt.getPosition());
    _buttonSNAKE = buttonSNAKE;
    _buttonSNAKE.setTexture(&_snakeBtTexture);

    sf::RectangleShape buttonSFT(sf::Vector2f(_sftBt.getGlobalBounds().width, _sftBt.getGlobalBounds().height));
    buttonSFT.setPosition(_sftBt.getPosition());
    _buttonSFT = buttonSFT;
    _buttonSFT.setTexture(&_sftBtTexture);

    sf::RectangleShape buttonQUIT(sf::Vector2f(_quitBt.getGlobalBounds().width, _quitBt.getGlobalBounds().height));
    buttonQUIT.setPosition(_quitBt.getPosition());
    _buttonQUIT = buttonQUIT;
    _buttonQUIT.setTexture(&_quitBtTexture);

    //selected button
    switch (_selectedButton)
    {
        case 0:
            _buttonPACMAN.setOutlineThickness(5.f);
            _buttonPACMAN.setOutlineColor(sf::Color(147,112,219));
            _buttonSNAKE.setOutlineThickness(0.f);
            _buttonSFT.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 1:
            _buttonPACMAN.setOutlineThickness(0.f);
            _buttonSNAKE.setOutlineThickness(5.f);
            _buttonSNAKE.setOutlineColor(sf::Color(147,112,219));
            _buttonSFT.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 2:
            _buttonPACMAN.setOutlineThickness(0.f);
            _buttonSNAKE.setOutlineThickness(0.f);
            _buttonSFT.setOutlineThickness(5.f);
            _buttonSFT.setOutlineColor(sf::Color(147,112,219));
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 3:
            _buttonPACMAN.setOutlineThickness(0.f);
            _buttonSNAKE.setOutlineThickness(0.f);
            _buttonSFT.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(5.f);
            _buttonQUIT.setOutlineColor(sf::Color(147,112,219));
            break;
    }
}

void arcade::SFML::pauseMenu()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    sf::RectangleShape buttonRESUME(sf::Vector2f(_resumeBt.getGlobalBounds().width, _resumeBt.getGlobalBounds().height));
    buttonRESUME.setPosition(_resumeBt.getPosition());
    _buttonRESUME = buttonRESUME;
    _buttonRESUME.setTexture(&_resumeBtTexture);

    sf::RectangleShape buttonMENU(sf::Vector2f(_menuBt.getGlobalBounds().width, _menuBt.getGlobalBounds().height));
    buttonMENU.setPosition(_menuBt.getPosition());
    _buttonMENU = buttonMENU;
    _buttonMENU.setTexture(&_menuBtTexture);

    sf::RectangleShape buttonSWITCHLIB(sf::Vector2f(_switchLibBt.getGlobalBounds().width, _switchLibBt.getGlobalBounds().height));
    buttonSWITCHLIB.setPosition(_switchLibBt.getPosition());
    _buttonSWITCHLIB = buttonSWITCHLIB;
    _buttonSWITCHLIB.setTexture(&_switchLibBtTexture);

    sf::RectangleShape buttonQUIT(sf::Vector2f(_quitBt.getGlobalBounds().width, _quitBt.getGlobalBounds().height));
    buttonQUIT.setPosition(_quitBt.getPosition());
    _buttonQUIT = buttonQUIT;
    _buttonQUIT.setTexture(&_quitBtTexture);

    // //selected button
    switch (_selectedButtonPause)
    {
        case 0:
            _buttonRESUME.setOutlineThickness(5.f);
            _buttonRESUME.setOutlineColor(sf::Color(147,112,219));
            _buttonMENU.setOutlineThickness(0.f);
            _buttonSWITCHLIB.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 1:
            _buttonRESUME.setOutlineThickness(0.f);
            _buttonMENU.setOutlineThickness(5.f);
            _buttonMENU.setOutlineColor(sf::Color(147,112,219));
            _buttonSWITCHLIB.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 2:
            _buttonRESUME.setOutlineThickness(0.f);
            _buttonMENU.setOutlineThickness(0.f);
            _buttonSWITCHLIB.setOutlineThickness(5.f);
            _buttonSWITCHLIB.setOutlineColor(sf::Color(147,112,219));
            _buttonQUIT.setOutlineThickness(0.f);
            break;
        case 3:
            _buttonRESUME.setOutlineThickness(0.f);
            _buttonMENU.setOutlineThickness(0.f);
            _buttonSWITCHLIB.setOutlineThickness(0.f);
            _buttonQUIT.setOutlineThickness(5.f);
            _buttonQUIT.setOutlineColor(sf::Color(147,112,219));
            break;
    }
}

void arcade::SFML::init()
{
    //window
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arcade - SFML", sf::Style::Resize | sf::Style::Close);
    _window->setFramerateLimit(244);

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
    _pacmanBt.setPosition(790, 500);
    _pacmanBt.setScale(0.4, 0.38);

    //snake button
    _snakeBtTexture.loadFromFile("assets/image/snake_bt.png");
    _snakeBt.setTexture(_snakeBtTexture);
    _snakeBt.setPosition(820, 600);
    _snakeBt.setScale(0.4, 0.38);

    //street fight tek button
    _sftBtTexture.loadFromFile("assets/image/sft_bt.png");
    _sftBt.setTexture(_sftBtTexture);
    _sftBt.setPosition(620, 700);
    _sftBt.setScale(0.35, 0.3);

    //quit button
    _quitBtTexture.loadFromFile("assets/image/quit_bt.png");
    _quitBt.setTexture(_quitBtTexture);
    _quitBt.setPosition(850, 810);
    _quitBt.setScale(0.4, 0.38);

    //resume button
    _resumeBtTexture.loadFromFile("assets/image/resume_bt.png");
    _resumeBt.setTexture(_resumeBtTexture);
    _resumeBt.setPosition(790, 400);
    _resumeBt.setScale(0.4, 0.38);

    //menu button
    _menuBtTexture.loadFromFile("assets/image/returnmenuBT.png");
    _menuBt.setTexture(_menuBtTexture);
    _menuBt.setPosition(540, 500);
    _menuBt.setScale(0.35, 0.3);

    //switch lib button
    _switchLibBtTexture.loadFromFile("assets/image/switchlib_bt.png");
    _switchLibBt.setTexture(_switchLibBtTexture);
    _switchLibBt.setPosition(640, 600);
    _switchLibBt.setScale(0.35, 0.3);

    //background pause
    _backgroundPauseTexture.loadFromFile("assets/image/pause_bg.png");
    _backgroundPause.setTexture(_backgroundPauseTexture);
    _backgroundPause.setPosition(0, -100);
    _backgroundPause.setScale(1, 1);
}

arcade::Input arcade::SFML::handleEvent()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window->close();
        if (_state == STATES::PAUSE) {
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::P) {
                _state = STATES::GAME;
                return (arcade::Input::RESUME);
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up) {
                _selectedButtonPause--;
                if (_selectedButtonPause < 0)
                    _selectedButtonPause = 3;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down) {
                _selectedButtonPause++;
                if (_selectedButtonPause > 3)
                    _selectedButtonPause = 0;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter) {
                if (_selectedButtonPause == 0) {
                    _state = STATES::GAME;
                    return (arcade::Input::RESUME);
                }
                if (_selectedButtonPause == 1) {
                    _state = STATES::MENU;
                    return (arcade::Input::MENU_1);
                }
                if (_selectedButtonPause == 2) {
                    _state = STATES::MENU;
                    return (arcade::Input::SWITCH_LIB);
                }
                if (_selectedButtonPause == 3)
                    _window->close();
            }
        }
        if (_state == STATES::MENU) {
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up) {
                _selectedButton--;
                if (_selectedButton < 0)
                    _selectedButton = 3;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down) {
                _selectedButton++;
                if (_selectedButton > 3)
                    _selectedButton = 0;
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter) {
                if (_selectedButton == 0) {
                    _state = STATES::GAME;
                    return (arcade::Input::PACMAN);
                }
                if (_selectedButton == 1) {
                    _state = STATES::GAME;
                    return (arcade::Input::SNAKE);
                }
                if (_selectedButton == 2) {
                    _state = STATES::GAME;
                    return (arcade::Input::SFT);
                }
                if (_selectedButton == 3)
                    _window->close();
            }
        }
        if (_state == STATES::TUTORIAL) {
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Enter) {
                if (_selectedButton == 0) {
                    // _backgroundTutoTexture.loadFromFile("assets/image/tuto_bg.png");
                    // _backgroundTuto.setTexture(_backgroundTutoTexture);
                    // _backgroundTuto.setPosition(0, 0);
                    // _backgroundTuto.setScale(1, 1);
                    _state = STATES::GAME;
                    return (arcade::Input::PACMAN);
                }
                if (_selectedButton == 1) {
                    _state = STATES::GAME;
                    return (arcade::Input::SNAKE);
                }
            }
        }
        if (_state == STATES::GAME) {
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::P) {
                _state = STATES::PAUSE;
                return (arcade::Input::PAUSE_1);
            }
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
                return (arcade::Input::ESCAPE);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Left)
                return (arcade::Input::ARROW_LEFT);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Right)
                return (arcade::Input::ARROW_RIGHT);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Q)
                return (arcade::Input::PLAYER2_LEFT);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::D)
                return (arcade::Input::PLAYER2_RIGHT);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Z)
                return (arcade::Input::PLAYER2_JUMP);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::S)
                return (arcade::Input::PLAYER2_HIT);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up)
                return (arcade::Input::ARROW_UP);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down)
                return (arcade::Input::ARROW_DOWN);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::G)
                return (arcade::Input::SWITCH_LIB);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::H)
                return (arcade::Input::SWITCH_GAME);
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::M)
                return (arcade::Input::PLAYER1_HIT);
        }
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
    // _backgroundGame.setScale(10, 10);
}

void arcade::SFML::animObject(Object *object, sf::Sprite *sprite)
{
    if (object->_animation->_isAnimation == true) {
        sprite->setOrigin(object->_animation->_width / 2, object->_animation->_height / 2);
        if (_clockAnim.getElapsedTime().asMilliseconds() >= object->_animation->_restart) {
            object->_animation->_x += object->_animation->_width;
            object->_animation->_frameRate += 1;
            if (object->_animation->_frameRate >= object->_animation->_nbFrame) {
                object->_animation->_frameRate = 0;
                object->_animation->_x = 0;
            }
            object->_animation->_restart = _clockAnim.getElapsedTime().asMilliseconds() + object->_animation->_clock;
        }
        sprite->setTextureRect(sf::IntRect(
            object->_animation->_x,
            object->_animation->_y,
            object->_animation->_width,
            object->_animation->_height
        ));
        sprite->setScale(object->_sizex, object->_sizey);
    }
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
        animObject(object, &sprite);
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

void arcade::SFML::refreshw(arcade::AllObjects *AllObjects)
{
    if (_state == STATES::MENU) {
        _window->draw(_background);
        _window->draw(_title);
        _window->draw(_pacmanBt);
        _window->draw(_snakeBt);
        _window->draw(_sftBt);
        _window->draw(_quitBt);

        _window->draw(_buttonPACMAN);
        _window->draw(_buttonSNAKE);
        _window->draw(_buttonSFT);
        _window->draw(_buttonQUIT);
    }
    if (_state == STATES::TUTORIAL) {
        _window->draw(_backgroundTuto);
    }
    if (_state == STATES::GAME) {
        _window->draw(_backgroundGame);
        if (!AllObjects->_objects.empty()) {
            for (auto &i : AllObjects->_objects)
                drawElement(i);
        }
        if (!AllObjects->_player.empty()) {
            for (auto &i : AllObjects->_player)
                drawElement(i);
        }
        if (!AllObjects->_food.empty()) {
            for (auto &i : AllObjects->_food)
                drawElement(i);
        }
        if (!AllObjects->_enemy.empty()) {
            for (auto &i : AllObjects->_enemy)
                drawElement(i);
        }
        _window->draw(_score);
    }
    if (_state == STATES::SETTINGS) {

    }
    if (_state == STATES::PAUSE) {
            _window->draw(_backgroundPause);
            _window->draw(_resumeBt);
            _window->draw(_menuBt);
            _window->draw(_switchLibBt);
            _window->draw(_quitBt);

            _window->draw(_buttonRESUME);
            _window->draw(_buttonMENU);
            _window->draw(_buttonSWITCHLIB);
            _window->draw(_buttonQUIT);
    }
    if (_state == STATES::EXIT) {
        _window->close();
    }
    _window->display();
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
