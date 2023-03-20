/*
** EPITECH PROJECT, 2022
** arcade games
** File description:
** Snake.cpp
*/

#include "Snake.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

#include "../../Interfaces/Object.hpp"

extern "C" void __attribute__((constructor)) init_arcade_sdl() {
    printf("[arcade_snake] Loading Snake library...\n");
}

extern "C" arcade::IGame *entryPoint()
{
    printf("[arcade_snake] Entry point for Snake game!\n");
    return new arcade::SnakeGame();
}

extern "C" void __attribute__((destructor)) clean_sdl() {
    printf("[arcade_snake] Snake closing...\n");
}

arcade::SnakeGame::SnakeGame() {
    _info = "Snake";
    _direction = arcade::Input::ARROW_RIGHT;
    _score = 0;
}

arcade::SnakeGame::~SnakeGame() = default;

arcade::AllObjects *arcade::SnakeGame::initMap() {
    // //place map
    ifstream input_file("Games/Snake/assets/map.txt");
    AllObjects *allObjects = new AllObjects();
    std::string line;
    while (getline(input_file, line))
        _map.push_back(line);
    for (int i = 0; i < height_map; i++) {
        for (int j = 0; j < width_map; j++) {
            if (_map[i][j] == '#') {
                Object *wall = new Object(j, i, 60, "Games/Snake/assets/image/tile024.png", arcade::Object::Type::WALL);
                allObjects->_objects.push_back(wall);
            }
            if (_map[i][j] == ' ') {
                Object *empty = new Object(j, i, 60, "", arcade::Object::Type::EMPTY);
                allObjects->_objects.push_back(empty);
            }
        }
    }
    // //place player
    allObjects->_player.push_back(new Object(6, 9, 60, "Games/Snake/assets/image/tile052.png", arcade::Object::Type::HEAD));
    allObjects->_player.push_back(new Object(5, 9, 60, "Games/Snake/assets/image/tile053.png", arcade::Object::Type::BODY));
    allObjects->_player.push_back(new Object(4, 9, 60, "Games/Snake/assets/image/tile053.png", arcade::Object::Type::BODY));
    allObjects->_player.push_back(new Object(3, 9, 60, "Games/Snake/assets/image/tile053.png", arcade::Object::Type::BODY));

    // //place food
    spawnBonus(allObjects);

    _sound.push_back(new arcade::Sound("Games/Snake/assets/audio/backsound.wav", arcade::Sound::Type::BACK_SOUND, true, 25));
    return allObjects;
}

std::string arcade::SnakeGame::getBackground() {
    return "Games/Snake/assets/image/background.jpeg";
}

std::string arcade::SnakeGame::getInfo() {
    return _info;
}


void arcade::SnakeGame::initGame() {

}

int arcade::SnakeGame::handleEvent(arcade::Input input) {
    if (input == arcade::Input::ARROW_LEFT && _direction != arcade::Input::ARROW_RIGHT)
        _direction = arcade::Input::ARROW_LEFT;
    if (input == arcade::Input::ARROW_RIGHT && _direction != arcade::Input::ARROW_LEFT)
        _direction = arcade::Input::ARROW_RIGHT;
    if (input == arcade::Input::ARROW_UP && _direction != arcade::Input::ARROW_DOWN)
        _direction = arcade::Input::ARROW_UP;
    if (input == arcade::Input::ARROW_DOWN && _direction != arcade::Input::ARROW_UP)
        _direction = arcade::Input::ARROW_DOWN;
    return 0;
}

void arcade::SnakeGame::keepMoving(arcade::AllObjects *allObjects) {
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

void arcade::SnakeGame::goLeft(arcade::AllObjects *allObjects) {
    //change head direction
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if ((*it)->_type == arcade::Object::Type::HEAD) {
            (*it)->_path = "Games/Snake/assets/image/tile050.png";
            break;
        }
    }

    //collision
    for (auto &x : allObjects->_objects) {
        if ((x->_type == arcade::Object::Type::WALL
        &&x->_posx == allObjects->_player.front()->_posx - 1
        && x->_posy == allObjects->_player.front()->_posy) || (checkSnake(allObjects) == 1)) {
            _gameOver = true;
            return;
        }
    }
    for (auto &x : allObjects->_food) {
        if (x->_type == arcade::Object::Type::FOOD
        && x->_posx == allObjects->_player.front()->_posx - 1
        && x->_posy == allObjects->_player.front()->_posy) {
            _score += 1;
            std::cout << "score: " << _score << std::endl;
            allObjects->_food.pop_back();
            spawnBonus(allObjects);
            allObjects->_player.push_back(new Object(allObjects->_player.back()->_posx, allObjects->_player.back()->_posy, allObjects->_player.back()->_size, allObjects->_player.back()->_path, allObjects->_player.back()->_type));
            _speed -= 0.005;
            break;
        }
    }

    //move
    Object *newFront = new Object(allObjects->_player.front()->_posx - 1,
    allObjects->_player.front()->_posy,
    allObjects->_player.front()->_size,
    allObjects->_player.front()->_path,
    allObjects->_player.front()->_type);

    if (allObjects->_player.front()->_type == arcade::Object::Type::HEAD) {
        allObjects->_player.front()->_type = arcade::Object::Type::BODY;
        allObjects->_player.front()->_path = "Games/Snake/assets/image/tile053.png";
    }
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::SnakeGame::goRight(arcade::AllObjects *allObjects) {
    //change head direction
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if ((*it)->_type == arcade::Object::Type::HEAD) {
            (*it)->_path = "Games/Snake/assets/image/tile052.png";
            break;
        }
    }

    //collision
    for (auto &x : allObjects->_objects) {
        if ((x->_type == arcade::Object::Type::WALL
        &&x->_posx == allObjects->_player.front()->_posx + 1
        && x->_posy == allObjects->_player.front()->_posy) || (checkSnake(allObjects) == 1)) {
            _gameOver = true;
            return;
        }
    }
    for (auto &x : allObjects->_food) {
        if (x->_type == arcade::Object::Type::FOOD
        && x->_posx == allObjects->_player.front()->_posx + 1
        && x->_posy == allObjects->_player.front()->_posy) {
            _score += 1;
            std::cout << "score: " << _score << std::endl;
            allObjects->_food.pop_back();
            spawnBonus(allObjects);
            allObjects->_player.push_back(new Object(allObjects->_player.back()->_posx, allObjects->_player.back()->_posy, allObjects->_player.back()->_size, allObjects->_player.back()->_path, allObjects->_player.back()->_type));
            _speed -= 0.005;
            break;
        }
    }

    //move
    Object *newFront = new Object(allObjects->_player.front()->_posx + 1,
    allObjects->_player.front()->_posy,
    allObjects->_player.front()->_size,
    allObjects->_player.front()->_path,
    allObjects->_player.front()->_type);

    if (allObjects->_player.front()->_type == arcade::Object::Type::HEAD) {
        allObjects->_player.front()->_type = arcade::Object::Type::BODY;
        allObjects->_player.front()->_path = "Games/Snake/assets/image/tile053.png";
    }
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::SnakeGame::goUp(arcade::AllObjects *allObjects) {
    //change head direction
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if ((*it)->_type == arcade::Object::Type::HEAD) {
            (*it)->_path = "Games/Snake/assets/image/tile049.png";
            break;
        }
    }

    //collision
    for (auto &x : allObjects->_objects) {
        if ((x->_type == arcade::Object::Type::WALL
        &&x->_posx == allObjects->_player.front()->_posx
        && x->_posy == allObjects->_player.front()->_posy - 1) || (checkSnake(allObjects) == 1)) {
            _gameOver = true;
            return;
        }
    }
    for (auto &x : allObjects->_food) {
        if (x->_type == arcade::Object::Type::FOOD
        && x->_posx == allObjects->_player.front()->_posx
        && x->_posy == allObjects->_player.front()->_posy - 1) {
            _score += 1;
            std::cout << "score: " << _score << std::endl;
            allObjects->_food.pop_back();
            spawnBonus(allObjects);
            allObjects->_player.push_back(new Object(allObjects->_player.back()->_posx, allObjects->_player.back()->_posy, allObjects->_player.back()->_size, allObjects->_player.back()->_path,allObjects->_player.back()->_type));
            _speed -= 0.005;
            break;
        }
    }

    //move
    Object *newFront = new Object(allObjects->_player.front()->_posx,
    allObjects->_player.front()->_posy - 1,
    allObjects->_player.front()->_size,
    allObjects->_player.front()->_path,
    allObjects->_player.front()->_type);

    if (allObjects->_player.front()->_type == arcade::Object::Type::HEAD) {
        allObjects->_player.front()->_type = arcade::Object::Type::BODY;
        allObjects->_player.front()->_path = "Games/Snake/assets/image/tile053.png";
    }
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}


void arcade::SnakeGame::goDown(arcade::AllObjects *allObjects) {
    //change head direction
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if ((*it)->_type == arcade::Object::Type::HEAD) {
            (*it)->_path = "Games/Snake/assets/image/tile051.png";
            break;
        }
    }

    //collision
    for (auto &x : allObjects->_objects) {
        if ((x->_type == arcade::Object::Type::WALL
        &&x->_posx == allObjects->_player.front()->_posx
        && x->_posy == allObjects->_player.front()->_posy + 1) ||( checkSnake(allObjects) == 1)) {
            _gameOver = true;
            return;
        }
    }
    for (auto &x : allObjects->_food) {
        if (x->_type == arcade::Object::Type::FOOD
        && x->_posx == allObjects->_player.front()->_posx
        && x->_posy == allObjects->_player.front()->_posy + 1) {
            _score += 1;
            std::cout << "score: " << _score << std::endl;
            allObjects->_food.pop_back();
            spawnBonus(allObjects);
            allObjects->_player.push_back(new Object(allObjects->_player.back()->_posx, allObjects->_player.back()->_posy, allObjects->_player.back()->_size, allObjects->_player.back()->_path, allObjects->_player.back()->_type));
            _speed -= 0.005;
            break;
        }
    }

    //move
    Object *newFront = new Object(allObjects->_player.front()->_posx,
    allObjects->_player.front()->_posy + 1,
    allObjects->_player.front()->_size,
    allObjects->_player.front()->_path,
    allObjects->_player.front()->_type);
    if (allObjects->_player.front()->_type == arcade::Object::Type::HEAD) {
        allObjects->_player.front()->_type = arcade::Object::Type::BODY;
        allObjects->_player.front()->_path = "Games/Snake/assets/image/tile053.png";
    }
    allObjects->_player.push_front(newFront);
    allObjects->_player.pop_back();
}

void arcade::SnakeGame::update(arcade::AllObjects *allObjects) {
    //update time for moving
    static clock_t lastTime = clock();
    clock_t currentTime = clock();
    double deltaTime = static_cast<double>(currentTime - lastTime) / CLOCKS_PER_SEC;
    if (deltaTime >= _speed) {
        keepMoving(allObjects);
        lastTime = currentTime;
    }
}

bool arcade::SnakeGame::gameOver() {
    return _gameOver;
}

int arcade::SnakeGame::getScore() {
    return _score;
}

void arcade::SnakeGame::spawnBonus(arcade::AllObjects *allObjects) {
    srand(time(NULL));
    int x = rand() % 30 + 1;
    int y = rand() % 15 + 1;
    int fruit = rand() % 3;
    std::string _fruit[4] = {"Games/Snake/assets/image/tile054.png", "Games/Snake/assets/image/tile006.png", "Games/Snake/assets/image/tile022.png", "Games/Snake/assets/image/tile055.png"};
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if (allObjects->_food.size() < 1 && (*it)->_posx != x && (*it)->_posy != y) {
            Object *newBonus = new Object(x, y, 1, _fruit[fruit], arcade::Object::Type::FOOD);
            allObjects->_food.push_back(newBonus);
            return;
        } else {
            spawnBonus(allObjects);
            return;
        }
    }
}

int arcade::SnakeGame::checkSnake(AllObjects *allObjects) {
    for (auto it = allObjects->_player.begin(); it != allObjects->_player.end(); ++it) {
        if ((*it)->_type == arcade::Object::Type::HEAD) {
            for (auto it2 = allObjects->_player.begin(); it2 != allObjects->_player.end(); ++it2) {
                if ((*it2)->_posx == (*it)->_posx && (*it2)->_posy == (*it)->_posy && (*it2)->_type == arcade::Object::Type::BODY)
                    return 1;
            }
        }
    }
    return 0;
}

std::vector<arcade::Sound*> arcade::SnakeGame::sound() {
    return _sound;
}