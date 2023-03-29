/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** pacman.cpp
*/

#include "PacMan.hpp"

#include <ncurses.h>

extern "C" void __attribute__((constructor)) init_arcade_pacman() {
    printf("[arcade_pacman] Loading library...\n");
    printf("[arcade_pacman] Library loaded !\n");
}

extern "C"  arcade::IGame *entryPoint()
{
    printf("[arcade_pacman] Entry point !\n");
    return new arcade::PacManGame();
}

extern "C" void __attribute__((destructor)) clean_sfml() {
    printf("[arcade_pacman] Closed !\n");
}

arcade::PacManGame::PacManGame()
{
    this->_info = "PacMan";
}

arcade::PacManGame::~PacManGame() = default;

arcade::AllObjects *arcade::PacManGame::initMap() {
    // //place map
    ifstream input_file("Games/Pacman/assets/map2.txt");
    AllObjects *allObjects = new AllObjects();
    std::string line;
    while (getline(input_file, line)) {
        _map.emplace_back(line);
        allObjects->_map.emplace_back(line);
    }
    _score = 0;
    ifstream input_file2("Games/Pacman/assets/map.txt");
    std::string line2;
    while (getline(input_file2, line2)) {
        _points.emplace_back(line2);
        allObjects->_points.emplace_back(line2);
    }

    for (int i = 0; i < height_map; i++) {
        for (int j = 0; j < width_map; j++) {
            if (_map[i][j] == '#') {
                Object *wall = new Object(j, i, 60, "Games/Snake/assets/image/tile101.png", arcade::Object::Type::WALL);
                allObjects->_objects.emplace_back(wall);
            }
            if (_map[i][j] == ' ') {
                Object *empty = new Object(j, i, 60, "", arcade::Object::Type::EMPTY);
                allObjects->_objects.emplace_back(empty);
            }
            if (_points[i][j] == '*') {
                Object *food = new Object(j, i, 60, "Games/Snake/assets/image/tile011.png", arcade::Object::Type::FOOD);
                allObjects->_food.emplace_back(food);
            }
        }
    }
    //place pacman
    allObjects->_player.clear();
    allObjects->_player.emplace_back(new Object(1, 16, 60, "Games/Snake/assets/image/tile004.png", arcade::Object::Type::PACMAN));

    //place ghost
    allObjects->_enemy.emplace_back(new Object(10, 9, 60, "Games/Snake/assets/image/tile0004.png", arcade::Object::Type::CLYDE));
    allObjects->_enemy.emplace_back(new Object(11, 9, 60, "Games/Snake/assets/image/tile0002.png", arcade::Object::Type::BLINKY));
    allObjects->_enemy.emplace_back(new Object(12, 9, 60, "Games/Snake/assets/image/tile0001.png", arcade::Object::Type::PINKY));
    allObjects->_enemy.emplace_back(new Object(13, 9, 60, "Games/Snake/assets/image/tile0003.png", arcade::Object::Type::INKY));

    return allObjects;
}

std::string arcade::PacManGame::getBackground() {
    return "Games/Pacman/assets/background.jpeg";
}

std::string arcade::PacManGame::getInfo() {
    return this->_info;
}

void arcade::PacManGame::initGame() {}

int arcade::PacManGame::handleEvent(arcade::Input input) {
    if (input == arcade::Input::ARROW_LEFT)
        _direction = arcade::Input::ARROW_LEFT;
    if (input == arcade::Input::ARROW_RIGHT)
        _direction = arcade::Input::ARROW_RIGHT;
    if (input == arcade::Input::ARROW_UP)
        _direction = arcade::Input::ARROW_UP;
    if (input == arcade::Input::ARROW_DOWN)
        _direction = arcade::Input::ARROW_DOWN;
    return 0;
}

void arcade::PacManGame::keepMoving(AllObjects *allObjects) {
    if (_direction == arcade::Input::ARROW_LEFT) {
        goLeft(allObjects);
        return;
    }
    if (_direction == arcade::Input::ARROW_RIGHT) {
        goRight(allObjects);
        return;
    }
    if (_direction == arcade::Input::ARROW_UP) {
        goUp(allObjects);
        return;
    }
    if (_direction == arcade::Input::ARROW_DOWN) {
        goDown(allObjects);
        return;
    }
}

void arcade::PacManGame::goLeft(AllObjects *allObjects) {
    for (auto &i: allObjects->_objects) {
        if (i->_posx == allObjects->_player.front()->_posx - 1 && i->_posy == allObjects->_player.front()->_posy) {
            if (i->_type == arcade::Object::Type::WALL)
                return;
        }
    }

    for (auto it = allObjects->_food.begin(); it != allObjects->_food.end(); ++it) {
        if ((*it)->_posx == allObjects->_player.front()->_posx - 1 && (*it)->_posy == allObjects->_player.front()->_posy) {
            allObjects->_food.erase(it);
            _score += 10;
            break;
        }
    }

    Object *newFront = new Object(allObjects->_player.front()->_posx - 1,
    allObjects->_player.front()->_posy,
    allObjects->_player.front()->_size,
    "Games/Snake/assets/image/tile002.png",
    allObjects->_player.front()->_type);
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::PacManGame::goRight(AllObjects *allObjects) {

    for (auto &i: allObjects->_objects) {
        if (i->_posx == allObjects->_player.front()->_posx + 1 && i->_posy == allObjects->_player.front()->_posy) {
            if (i->_type == arcade::Object::Type::WALL)
                return;
        }
    }

    for (auto it = allObjects->_food.begin(); it != allObjects->_food.end(); ++it) {
        if ((*it)->_posx == allObjects->_player.front()->_posx + 1 && (*it)->_posy == allObjects->_player.front()->_posy) {
            allObjects->_food.erase(it);
            _score += 10;
            break;
        }
    }

    Object *newFront = new Object(allObjects->_player.front()->_posx + 1,
    allObjects->_player.front()->_posy,
    allObjects->_player.front()->_size,
    "Games/Snake/assets/image/tile004.png",
    allObjects->_player.front()->_type);
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::PacManGame::goUp(AllObjects *allObjects) {
    for (auto &i: allObjects->_objects) {
        if (i->_posx == allObjects->_player.front()->_posx && i->_posy == allObjects->_player.front()->_posy - 1) {
            if (i->_type == arcade::Object::Type::WALL)
                return;
        }
    }

    for (auto it = allObjects->_food.begin(); it != allObjects->_food.end(); ++it) {
        if ((*it)->_posx == allObjects->_player.front()->_posx && (*it)->_posy == allObjects->_player.front()->_posy - 1) {
            allObjects->_food.erase(it);
            _score += 10;
            break;
        }
    }

    Object *newFront = new Object(allObjects->_player.front()->_posx,
    allObjects->_player.front()->_posy - 1,
    allObjects->_player.front()->_size,
    "Games/Snake/assets/image/tile001.png",
    allObjects->_player.front()->_type);
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::PacManGame::goDown(AllObjects *allObjects) {
    for (auto &i: allObjects->_objects) {
        if (i->_posx == allObjects->_player.front()->_posx && i->_posy == allObjects->_player.front()->_posy + 1) {
            if (i->_type == arcade::Object::Type::WALL)
                return;
        }
    }

    for (auto it = allObjects->_food.begin(); it != allObjects->_food.end(); ++it) {
        if ((*it)->_posx == allObjects->_player.front()->_posx && (*it)->_posy == allObjects->_player.front()->_posy + 1) {
            allObjects->_food.erase(it);
            _score += 10;
            break;
        }
    }

    Object *newFront = new Object(allObjects->_player.front()->_posx,
    allObjects->_player.front()->_posy + 1,
    allObjects->_player.front()->_size,
    "Games/Snake/assets/image/tile003.png",
    allObjects->_player.front()->_type);
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::PacManGame::clyde(arcade::AllObjects *allObjects)
{
    for (auto &it: allObjects->_enemy) {
        if (it->_type == arcade::Object::Type::CLYDE) {
            moveGhost(it, allObjects);
        }
    }
}

void arcade::PacManGame::blinky(arcade::AllObjects *allObjects)
{
    for (auto &it: allObjects->_enemy) {
        if (it->_type == arcade::Object::Type::BLINKY) {
            moveGhost(it, allObjects);
        }
    }
}

void arcade::PacManGame::inky(arcade::AllObjects *allObjects)
{
    for (auto &it: allObjects->_enemy) {
        if (it->_type == arcade::Object::Type::INKY) {
            moveGhost(it, allObjects);
        }
    }
}

void arcade::PacManGame::pinky(arcade::AllObjects *allObjects)
{
    for (auto &it: allObjects->_enemy) {
        if (it->_type == arcade::Object::Type::PINKY) {
            moveGhost(it, allObjects);
        }
    }
}

bool arcade::PacManGame::isValidDirection(int x, int y, arcade::AllObjects *allObjects)
{
    for (auto &i : allObjects->_objects) {
        if (i->_posx == x && i->_posy == y) {
            if (i->_type == arcade::Object::Type::WALL) {
                return false;
            }
        }
    }
    return true;
}

void arcade::PacManGame::ghostMove(arcade::Object * _ghost, arcade::AllObjects *allObjects, int x, int y)
{
    _ghost->_posx += x;
    _ghost->_posy += y;
}

void arcade::PacManGame::moveGhost(arcade::Object *_ghost, arcade::AllObjects *allObjects)
{
    srand(time(NULL));
    std::vector<int> validDirs;
    int dir = rand() % 4;
    if (isValidDirection(_ghost->_posx - 1, _ghost->_posy, allObjects) && _ghost->_lastDirection != arcade::Input::ARROW_RIGHT)
        validDirs.push_back(arcade::Input::ARROW_LEFT);
    if (isValidDirection(_ghost->_posx + 1, _ghost->_posy, allObjects) && _ghost->_lastDirection != arcade::Input::ARROW_LEFT)
        validDirs.push_back(arcade::Input::ARROW_RIGHT);
    if (isValidDirection(_ghost->_posx, _ghost->_posy - 1, allObjects) && _ghost->_lastDirection != arcade::Input::ARROW_DOWN)
        validDirs.push_back(arcade::Input::ARROW_UP);
    if (isValidDirection(_ghost->_posx, _ghost->_posy + 1, allObjects) && _ghost->_lastDirection != arcade::Input::ARROW_UP)
        validDirs.push_back(arcade::Input::ARROW_DOWN);
    if (validDirs.empty())
        return;
    dir = validDirs[rand() % validDirs.size()];

    switch (dir) {
        case arcade::Input::ARROW_LEFT:
            ghostMove(_ghost, allObjects, -1, 0);
            break;
        case arcade::Input::ARROW_RIGHT:
            ghostMove(_ghost, allObjects, 1, 0);
            break;
        case arcade::Input::ARROW_UP:
            ghostMove(_ghost, allObjects, 0, -1);
            break;
        case arcade::Input::ARROW_DOWN:
            ghostMove(_ghost, allObjects, 0, 1);
            break;
    }
    _ghost->_lastDirection = dir;
    if (_ghost->_posx == allObjects->_player.front()->_posx && _ghost->_posy == allObjects->_player.front()->_posy) {
        _gameOver = true;
        return;
    }
}

void arcade::PacManGame::update(arcade::AllObjects *allObjects)
{
    static clock_t lastTime = clock();
    clock_t currentTime = clock();
    double deltaTime = static_cast<double>(currentTime - lastTime) / CLOCKS_PER_SEC;
    if (deltaTime >= _speed) {
        pinky(allObjects);
        blinky(allObjects);
        if (_moveFrame == 100)
            verif = 0;
        if (verif == 0) {
            inky(allObjects);
            clyde(allObjects);
        }
        lastTime = currentTime;
        _moveFrame ++;
        keepMoving(allObjects);
        if (gameOver())
            return;
    }
}

bool arcade::PacManGame::gameOver()
{
    return _gameOver;
}

int arcade::PacManGame::getScore()
{
    return _score;
}

void arcade::PacManGame::spawnBonus(AllObjects *allObjects) {}
    std::vector<arcade::Sound*> arcade::PacManGame::sound() {
    return _sound;
}