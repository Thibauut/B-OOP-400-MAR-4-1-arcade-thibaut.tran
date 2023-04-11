/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** StreetFighTek.cpp
*/

#include "StreetFighTek.hpp"

extern "C" void __attribute__((constructor)) init_arcade_sft()
{
    printf("[arcade_street_fight_tek] Loading StreetFighTek library...\n");
}

extern "C" arcade::IGame *entryPoint()
{
    printf("[arcade_street_fight_tek] Entry point for StreetFighTek game!\n");
    return new arcade::StreetFighTek();
}

extern "C" void __attribute__((destructor)) clean_sft()
{
    printf("[arcade_street_fight_tek] StreetFighTek closing...\n");
}

arcade::StreetFighTek::StreetFighTek()
{
    _info = "StreetFighTek";
    _direction1 = arcade::Input::NONE;
    _direction2 = arcade::Input::NONE;
    _score = 0;
    _gameOver = false;
    _speed = 0.1;
}

arcade::StreetFighTek::~StreetFighTek() = default;

std::string arcade::StreetFighTek::getBackground()
{
    return "Games/StreetFighTek/assets/image/background.png";
}

int arcade::StreetFighTek::getScore()
{
    return _score;
}

std::string arcade::StreetFighTek::getInfo()
{
    return _info;
}

bool arcade::StreetFighTek::gameOver()
{
    return _gameOver;
}

void arcade::StreetFighTek::initGame()
{
    _gameOver = false;
}

void arcade::StreetFighTek::initLifeBarAnimation(arcade::Object *lifebar)
{
    lifebar->_animation->_isAnimation = true;
    lifebar->_animation->_x = 0;
    lifebar->_animation->_y = 0;
    lifebar->_animation->_width = 900;
    lifebar->_animation->_height = 100;
    lifebar->_animation->_clock = 0;
    lifebar->_animation->_restart = 100;
    lifebar->_animation->_nbFrame = 0;
    lifebar->_animation->_frameRate = 0;
}

arcade::Object *arcade::StreetFighTek::initLifeBar(float x, float y)
{
    arcade::Object *lifeBar = new arcade:: Object(
        x / 60,
        y / 60,
        1,
        1,
        "Games/StreetFighTek/assets/image/lifeBar.png",
        arcade::Object::Type::PLAYER_1,
        900
    );
    initLifeBarAnimation(lifeBar);
    return lifeBar;
}

arcade::Object *arcade::StreetFighTek::initLifeBar2(float x, float y)
{
    arcade::Object *lifeBar = new arcade:: Object(
        x / 60,
        y / 60,
        1,
        1,
        "Games/StreetFighTek/assets/image/lifeBarCadre.png",
        arcade::Object::Type::PLAYER_1,
        900
    );
    initLifeBarAnimation(lifeBar);
    return lifeBar;
}

arcade::Object *arcade::StreetFighTek::initJump()
{
    Object *jump = new Object(100, 100, 1, 1, "", arcade::Object::Type::PLAYER_1, 0);
    jump->_animation->_clock = 0.01;
    jump->_animation->_restart = 0.01;
    jump->_animation->_nbFrame = 0;
    jump->_animation->_frameRate = 0;
    jump->_animation->_isAnimation = true;
    jump->_posx = 0;
    return (jump);
}

arcade::AllObjects *arcade::StreetFighTek::initMap()
{
    arcade::AllObjects *allObjects = new arcade::AllObjects();
    allObjects->_player.push_back(init_player_1());
    allObjects->_objects.push_back(initLifeBar(450, 100));
    allObjects->_player.push_back(init_player_2());
    allObjects->_objects.push_back(initLifeBar(1400, 100));
    allObjects->_objects.push_back(initJump());
    allObjects->_objects.push_back(initJump());
    allObjects->_objects.push_back(initLifeBar2(450, 100));
    allObjects->_objects.push_back(initLifeBar2(1400, 100));
    return allObjects;
}

int arcade::StreetFighTek::handleEvent(arcade::Input input)
{
    if (input == arcade::Input::PLAYER1_JUMP)
        _direction1 = arcade::Input::PLAYER1_JUMP;
    else if (input == arcade::Input::PLAYER1_DOWN)
        _direction1 = arcade::Input::PLAYER1_HIT;
    else if (input == arcade::Input::PLAYER1_LEFT)
        _direction1 = arcade::Input::PLAYER1_LEFT;
    else if (input == arcade::Input::PLAYER1_RIGHT)
        _direction1 = arcade::Input::PLAYER1_RIGHT;
    else if (input == arcade::Input::PLAYER1_HIT)
        _direction1 = arcade::Input::PLAYER1_HIT;
    else
        _direction1 = arcade::Input::NONE;
    if (input == arcade::Input::PLAYER2_JUMP)
        _direction2 = arcade::Input::PLAYER2_JUMP;
    else if (input == arcade::Input::PLAYER2_DOWN)
        _direction2 = arcade::Input::PLAYER2_HIT;
    else if (input == arcade::Input::PLAYER2_LEFT)
        _direction2 = arcade::Input::PLAYER2_LEFT;
    else if (input == arcade::Input::PLAYER2_RIGHT)
        _direction2 = arcade::Input::PLAYER2_RIGHT;
    else if (input == arcade::Input::PLAYER2_HIT)
        _direction2 = arcade::Input::PLAYER2_HIT;
    else
        _direction2 = arcade::Input::NONE;
    _speed -= 0.002;
    return arcade::Input::NONE;
}

void arcade::StreetFighTek::goUp(Object *player, Object *jump)
{
    if (jump->_posx == 1 || jump->_posx == 2) {
        jump->_animation->_isAnimation = true;
        if (jump->_posx == 1) {
            player->_animation->_frameRate = 1;
            player->_animation->_nbFrame = 1;
            player->_animation->_clock = 10000000000000000;
            player->_animation->_restart = 10000000000000000;
            player->_animation->_x = 107;
            player->_animation->_y = 117 * 3;
            player->_posy -= 0.5;
            if (player->_posy <= 5)
                jump->_posx = 2;
        }
        if (jump->_posx == 2) {
            player->_animation->_frameRate = 1;
            player->_animation->_nbFrame = 1;
            player->_animation->_clock = 10000000000000000;
            player->_animation->_restart = 10000000000000000;
            player->_animation->_x = 0;
            player->_animation->_y = 117 * 3;
            player->_posy += 0.5;
            if (player->_posy >= 11) {
                player->_animation->_frameRate = 0;
                player->_animation->_nbFrame = 7;
                player->_animation->_x = 0;
                player->_animation->_y = 0;
                player->_animation->_clock = 100;
                player->_animation->_restart = 100;
                jump->_posx = 0;
            }
        }
    } else {
        jump->_animation->_clock = 0.001;
        jump->_animation->_restart = 0.001;
        jump->_animation->_nbFrame = 0;
        jump->_animation->_frameRate = 0;
    }
}

void arcade::StreetFighTek::goLeft(Object *player)
{
    if (player->_animation->_nbFrame != 6) {
        player->_animation->_nbFrame = 6;
        player->_animation->_frameRate = 0;
        player->_animation->_y = 117;
        player->_animation->_x = 0;
        if (player->_sizex > 0)
            player->_sizex = player->_sizex * (-1);
    }
}

void arcade::StreetFighTek::goRight(Object *player)
{
    if (player->_animation->_nbFrame != 6) {
        player->_animation->_nbFrame = 6;
        player->_animation->_frameRate = 0;
        player->_animation->_y = 117;
        player->_animation->_x = 0;
        if (player->_sizex < 0)
            player->_sizex = player->_sizex * (-1);
    }
}

void arcade::StreetFighTek::hit(Object *player, Object *target)
{
    if (player->_animation->_nbFrame != 3) {
        player->_animation->_y = 117 * 2;
        player->_animation->_x = 0;
        player->_animation->_nbFrame = 3;
        player->_animation->_frameRate = 0;
        player->_animation->_clock = 300;
        if ((player->_posx - target->_posx >= -50) && (player->_posx - target->_posx <= 50))
            target->_life -= 15;
    }
}

void arcade::StreetFighTek::checkEndAttack(Object *player)
{
    if (player->_animation->_nbFrame == 6)
        if (player->_sizex > 0)
            player->_posx += 0.3;
        else
            player->_posx -= 0.3;
    if (player->_animation->_nbFrame == 3 && player->_animation->_frameRate == 2) {
        player->_animation->_y = 0;
        player->_animation->_x = 0;
        player->_animation->_nbFrame = 7;
        player->_animation->_frameRate = 0;
        player->_animation->_clock = 100;
   }
   if (player->_animation->_nbFrame == 6 && player->_animation->_frameRate == 5) {
        player->_animation->_y = 0;
        player->_animation->_x = 0;
        player->_animation->_nbFrame = 7;
        player->_animation->_frameRate = 0;
        player->_animation->_clock = 100;
   }
}

void arcade::StreetFighTek::update(arcade::AllObjects *allObjects)
{
    goUp(allObjects->_player.front(), allObjects->_objects[2]);
    checkEndAttack(allObjects->_player.front());
    goUp(allObjects->_player.back(), allObjects->_objects[3]);
    checkEndAttack(allObjects->_player.back());
    if (_direction1 == arcade::Input::ARROW_LEFT)
        goLeft(allObjects->_player.front());
    if (_direction1 == arcade::Input::ARROW_RIGHT)
        goRight(allObjects->_player.front());
    if (_direction1 == arcade::Input::ARROW_UP && allObjects->_objects[2]->_posx == 0)
        allObjects->_objects[2]->_posx = 1;
    if (_direction1 == arcade::Input::PLAYER1_HIT)
        hit(allObjects->_player.front(), allObjects->_player.back());
    // if (allObjects->_player.front()->_life <= 0)
    //     allObjects->_player.erase(allObjects->_player.front());
    if (_direction2 == arcade::Input::PLAYER2_LEFT)
        goLeft(allObjects->_player.back());
    if (_direction2 == arcade::Input::PLAYER2_RIGHT)
        goRight(allObjects->_player.back());
    if (_direction2 == arcade::Input::PLAYER2_JUMP && allObjects->_objects[3]->_posx == 0)
        allObjects->_objects[3]->_posx = 1;
    if (_direction2 == arcade::Input::PLAYER2_HIT)
        hit(allObjects->_player.back(), allObjects->_player.front());
    // if (allObjects->_player.back()->_life <= 0)
    //     allObjects->_player.erase(allObjects->_player.back());
    allObjects->_objects[0]->_animation->_width = allObjects->_player.front()->_life * 9;
    allObjects->_objects[1]->_animation->_width = allObjects->_player.back()->_life * 9;
}

void arcade::StreetFighTek::initAnimation(arcade::Object *player)
{
    player->_animation->_isAnimation = true;
    player->_animation->_x = 0;
    player->_animation->_y = 0;
    player->_animation->_width = 107;
    player->_animation->_height = 117;
    player->_animation->_restart = 100;
    player->_animation->_clock = 100;
    player->_animation->_nbFrame = 7;
    player->_animation->_frameRate = 0;
}

arcade::Object *arcade::StreetFighTek::init_player_1()
{
    arcade::Object *player = new arcade:: Object(
        8,
        9,
        3,
        3,
        "Games/StreetFighTek/assets/image/player1.png",
        arcade::Object::Type::PLAYER_1,
        100
    );
    initAnimation(player);
    return player;
}

arcade::Object *arcade::StreetFighTek::init_player_2()
{
    arcade::Object *player = new arcade:: Object(
        23,
        9,
        -3,
        3,
        "Games/StreetFighTek/assets/image/player1.png",
        arcade::Object::Type::PLAYER_2,
        100
    );
    player->_animation->_isAnimation = true;
    initAnimation(player);
    return player;
}