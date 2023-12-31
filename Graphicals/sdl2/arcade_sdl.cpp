/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** foo.cpp
*/

#include <stdio.h>
#include <unistd.h>
#include "arcade_sdl.hpp"

extern "C" void __attribute__((constructor)) init_arcade_sdl() {
    printf("[arcade_sdl] Loading library...\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        write(2, "[arcade_sdl] /!'\' Failed to load library\n", 42);
        exit(84);
    }
    if (TTF_Init() != 0) {
        write(2, "[arcade_sdl] /!'\' Failed to load font library\n", 46);
        exit(84);
    }
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        write(2, "[arcade_sdl] /!'\' Failed to load image library\n", 47);
        exit(84);
    }
    printf("[arcade_sdl] Library loaded !\n");
}

extern "C"  arcade::IDisplayModule *entryPoint()
{
    printf("[arcade_sdl] Entry point !\n");
    return new arcade::SDL2();
}

extern "C" void __attribute__((destructor)) clean_sdl() {
    TTF_Quit();
    SDL_Quit();
    printf("[arcade_sdl] Closed !\n");
}

arcade::SDL2::SDL2()
{
    _clock = SDL_GetTicks();
    _info = "SDL2";
    _state = STATES::GAME;
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_USEREVENT;
    event.user.code = 0;
    event.user.data1 = NULL;
    event.user.data2 = NULL;
    _event = new SDL_Event();
    _event = &event;
}

arcade::SDL2::~SDL2() = default;

SDL_Rect *arcade::SDL2::animObject(Object *object, SDL_Rect *rectOther)
{
    Uint32 currentTime = SDL_GetTicks();
    Uint32 elapsedTime = currentTime - _clockAnim;
    if (object->_animation->_isAnimation == true) {
        object->_animation->_clock = _clockAnim;
        if (elapsedTime >= object->_animation->_restart) {
            object->_animation->_clock = 0;
            object->_animation->_x += object->_animation->_width;
            object->_animation->_frameRate += 1;
            if (object->_animation->_frameRate >= object->_animation->_nbFrame) {
                object->_animation->_frameRate = 0;
                object->_animation->_x = 0;
            }
            _clockAnim = currentTime;
        }
        SDL_Rect *rect = new SDL_Rect();
        rect->x = object->_animation->_x;
        rect->y = object->_animation->_y;
        rect->w = object->_animation->_width;
        rect->h = object->_animation->_height;
        rectOther->h *= 5;
        rectOther->w *= 5;
        return (rect);
    }
    return (NULL);
}

void arcade::SDL2::menu()
{
    Uint32 currentTime = SDL_GetTicks();
    Uint32 elapsedTime = currentTime - _clock;
    if (elapsedTime >= 100) {
        xrb++;
        if (xrb > 5) {
            xrb = 0;
            yrb++;
        }
        if (yrb > 11)
            yrb = 0;
        _clock = currentTime;
    }

    // sf::Vector2i mousePosition = sf::Mouse::getPosition();


    // sf::RectangleShape buttonPACMAN(sf::Vector2f(_pacmanBt.getGlobalBounds().width, _pacmanBt.getGlobalBounds().height));
    // buttonPACMAN.setPosition(_pacmanBt.getPosition());
    // _buttonPACMAN = buttonPACMAN;
    // _buttonPACMAN.setTexture(&_pacmanBtTexture);

    // sf::RectangleShape buttonSNAKE(sf::Vector2f(_snakeBt.getGlobalBounds().width, _snakeBt.getGlobalBounds().height));
    // buttonSNAKE.setPosition(_snakeBt.getPosition());
    // _buttonSNAKE = buttonSNAKE;
    // _buttonSNAKE.setTexture(&_snakeBtTexture);

    // sf::RectangleShape buttonQUIT(sf::Vector2f(_quitBt.getGlobalBounds().width, _quitBt.getGlobalBounds().height));
    // buttonQUIT.setPosition(_quitBt.getPosition());
    // _buttonQUIT = buttonQUIT;
    // _buttonQUIT.setTexture(&_quitBtTexture);

    // selected button
    switch (_selectedButton)
    {
        case 0:
            SDL_SetRenderDrawColor(_renderer, 147, 112, 219, 255);
            SDL_RenderDrawRect(_renderer, &_buttonPACMAN);
            SDL_RenderFillRect(_renderer, &_buttonPACMAN);
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(_renderer, &_buttonSNAKE);
            SDL_RenderDrawRect(_renderer, &_buttonQUIT);
            break;
        case 1:
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(_renderer, &_buttonPACMAN);
            SDL_RenderDrawRect(_renderer, &_buttonQUIT);
            SDL_SetRenderDrawColor(_renderer, 147, 112, 219, 255);
            SDL_RenderDrawRect(_renderer, &_buttonSNAKE);
            SDL_RenderFillRect(_renderer, &_buttonSNAKE);
            break;
        case 2:
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(_renderer, &_buttonPACMAN);
            SDL_RenderDrawRect(_renderer, &_buttonSNAKE);
            SDL_SetRenderDrawColor(_renderer, 147, 112, 219, 255);
            SDL_RenderDrawRect(_renderer, &_buttonQUIT);
            SDL_RenderFillRect(_renderer, &_buttonQUIT);
            break;
    }
}

void arcade::SDL2::init()
{
    // window
    _window = SDL_CreateWindow("Arcade - SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    // font
    _font = TTF_OpenFont("assets/font/visitor.ttf", 270);
    if (!_font)
        write(2, "[arcade_sdl] /!'\' Failed to load font\n", 39);

    // title
    // _title.setFont(_font);
    // _title.setString("ARCADE");
    // _title.setCharacterSize(270);
    // _title.setPosition(530, 100);
    // _title.setOutlineColor(sf::Color (106,90,205));
    // _title.setOutlineThickness(10);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(_font, "ARCADE !", color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = surface->w;
    rect.h = surface->h;

    SDL_RenderCopy(_renderer, texture, NULL, &rect);

    // background
    _background = IMG_Load("assets/image/background.png");
    _backgroundTexture = SDL_CreateTextureFromSurface(_renderer, _background);
    // anim background
    _backgroundRect.x = 0;
    _backgroundRect.y = 0;
    _backgroundRect.w = 1920;
    _backgroundRect.h = 1080;
    xrb = 0, yrb = 0;
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 6; col++) {
            _rectBackground[row][col].x = col * 1920;
            _rectBackground[row][col].y = row * 1080;
            _rectBackground[row][col].w = 1920;
            _rectBackground[row][col].h = 1080;
        }
    }
    // sf::IntRect rectBackground(0, 0, 1920, 1080);
    // _rectBackground = rectBackground;
    // _background.setTextureRect(_rectBackground);

    // //pacman button
    // _pacmanBtTexture.loadFromFile("assets/image/pacman_bt.png");
    // _pacmanBt.setTexture(_pacmanBtTexture);
    // _pacmanBt.setPosition(790, 600);
    // _pacmanBt.setScale(0.4, 0.38);

    // //snake button
    // _snakeBtTexture.loadFromFile("assets/image/snake_bt.png");
    // _snakeBt.setTexture(_snakeBtTexture);
    // _snakeBt.setPosition(820, 700);
    // _snakeBt.setScale(0.4, 0.38);

    // //quit button
    // _quitBtTexture.loadFromFile("assets/image/quit_bt.png");
    // _quitBt.setTexture(_quitBtTexture);
    // _quitBt.setPosition(850, 810);
    // _quitBt.setScale(0.4, 0.38);
}

arcade::Input arcade::SDL2::handleEvent()
{
    while (SDL_PollEvent(_event) != 0) {
        switch (_event->type) {
            case SDL_QUIT:
                this->stop();
                exit(EXIT_SUCCESS);
                break;
            case SDL_KEYDOWN:
                if (_event->key.keysym.sym == SDLK_ESCAPE)
                    return (arcade::Input::ESCAPE);
                if (_event->key.keysym.sym == SDLK_LEFT)
                    return (arcade::Input::ARROW_LEFT);
                if (_event->key.keysym.sym == SDLK_RIGHT)
                    return (arcade::Input::ARROW_RIGHT);
                if (_event->key.keysym.sym == SDLK_UP)
                    return (arcade::Input::ARROW_UP);
                if (_event->key.keysym.sym == SDLK_DOWN)
                    return (arcade::Input::ARROW_DOWN);
                if (_event->key.keysym.sym == SDLK_SPACE)
                    return (arcade::Input::SPACE);
                if (_event->key.keysym.sym == SDLK_g)
                    return (arcade::Input::SWITCH_LIB);
                if (_event->key.keysym.sym == SDLK_h)
                    return (arcade::Input::SWITCH_GAME);
                if (_event->key.keysym.sym == SDLK_p)
                    return (arcade::Input::PAUSE_1);
                break;
            default:
                return (arcade::Input::NONE);
                break;
        }
    }
    return (arcade::Input::NONE);
}

void arcade::SDL2::stop()
{
    printf("[arcade_sdl] Stopping...\n");
    // SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

void arcade::SDL2::drawBackground(const std::string &background)
{
    _background = IMG_Load(background.c_str());
    _backgroundTexture = SDL_CreateTextureFromSurface(_renderer, _background);

    _backgroundRect.x = 0;
    _backgroundRect.y = 0;
    _backgroundRect.w = 1920;
    _backgroundRect.h = 1080;

    // std::cout << "MENU" << _state << std::endl;

    // _backgroundGame.setScale(10, 10);
}

void arcade::SDL2::drawElement(arcade::Object *object)
{
    SDL_Texture *texture;
    SDL_Rect rect;
    rect.x = object->_posx * 60;
    rect.y = object->_posy * 60;
    rect.w = 60;
    rect.h = 60;
    if (object->_path == "") {
        texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 60, 60);
        // texture.setScale(10, 10);
        rect.w *= 10;
        rect.h *= 10;
        SDL_RenderCopy(_renderer, texture, NULL, &rect);
    } else {
        SDL_Surface *sprite = IMG_Load(object->_path.c_str());
        // rect.w *= 7.5;
        // rect.h *= 7.5;
        SDL_Rect *tmp = animObject(object, &rect);
        texture = SDL_CreateTextureFromSurface(_renderer, sprite);
        SDL_RenderCopy(_renderer, texture, tmp, &rect);
        // texture.setScale(7.5, 7.5);
    }
}

void arcade::SDL2::displayScore(int score)
{
    SDL_Color color = {255, 255, 255, 255};
    const std::string score_txt = "Score: " + std::to_string(score);
    char *score_char = new char[score_txt.length() + 1];
    strcpy(score_char, score_txt.c_str());
    TTF_SetFontSize(_font, 70);
    SDL_Surface* score_s = TTF_RenderText_Solid(_font, score_char, color);
    _score = SDL_CreateTextureFromSurface(_renderer, score_s);
    _scoreRect.x = 30;
    _scoreRect.y = 0;
    _scoreRect.w = score_s->w;
    _scoreRect.h = score_s->h;
}

void arcade::SDL2::refreshw(arcade::AllObjects *AllObjects)
{
    SDL_RenderClear(_renderer);
    if (_state == STATES::MENU) {
        SDL_RenderCopy(_renderer, _backgroundTexture, &_rectBackground[yrb][xrb], &_backgroundRect);
        // SDL_RenderCopy(_renderer, _title, NULL, &_backgroundRect);
        // _window->draw(_pacmanBt);
        // _window->draw(_snakeBt);
        // _window->draw(_quitBt);
    }
    if (_state == STATES::GAME) {
        SDL_RenderCopy(_renderer, _backgroundTexture, NULL, &_backgroundRect);
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
        SDL_RenderCopy(_renderer, _score, NULL, &_scoreRect);
    }
    if (_state == STATES::SETTINGS) {

    }
    if (_state == STATES::EXIT) {

    }
    SDL_RenderPresent(_renderer);
}

void arcade::SDL2::playSound(const std::string &path, int volume, bool loop)
{
    // if (!_music.openFromFile(path)) {
    //     std::cerr << "Erreur lors du chargement de " << path << std::endl;
    //     return;
    // }
    // _music.setVolume(volume);
    // _music.setLoop(loop);
    // _music.play();
}

