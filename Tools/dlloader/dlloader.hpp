/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** dlloader.hpp
*/

#pragma once

#include <iostream>
#include <dlfcn.h>
#include <vector>
#include <dirent.h>

template<typename T>
class DLLoader {
    public:
        DLLoader() : handler(nullptr), _path(getLibraryPath()), _currentLib(0) {
        }

        DLLoader(const std::string& filename) : handler(dlopen(filename.c_str(), RTLD_LAZY)), _path(getLibraryPath()) {
            _currentLib = getCurrentLibrary(filename);
        }

        ~DLLoader() {
            if (handler != nullptr) {
                dlclose(handler);
            }
        }

        void close() {
            dlclose(handler);
        }

        T* getInstance(const std::string& className) {
            T* instance = nullptr;

            if (handler != nullptr) {
                typedef T* (*create_t)();
                create_t create = reinterpret_cast<create_t>(dlsym(handler, className.c_str()));
                if (create != nullptr)
                    instance = create();
                else
                    std::cerr << "Failed to find " << className << " in library\n";
            } else {
                std::cerr << "Failed to load library\n" << dlerror() << std::endl;
            }

            return instance;
        }

        std::vector<std::string> getLibraryPath() {
            DIR *dir;
            struct dirent *ent;
            std::vector<std::string> path;

            if ((dir = opendir ("./lib")) != NULL) {
                while ((ent = readdir (dir)) != NULL) {
                    if (ent->d_name[0] != '.') {
                        std::string tmp = "./lib/" + std::string(ent->d_name);
                        path.push_back(tmp);
                    }
                }
                closedir (dir);
            } else {
                std::cerr << "Failed to open directory" << std::endl;
            }
            return (path);
        }

        void switchLibrary(const char* filename) {
            if (handler != nullptr) {
                dlclose(handler);
            }
            handler = dlopen(filename, RTLD_LAZY);
        }

        int getCurrentLibrary(std::string lib) {
            for (int i = 0; i < _path.size(); i++) {
                if (_path[i] == lib)
                    return (i);
            }
            return (0);
        }

        void nextLibrary() {
            if (handler != nullptr) {
                dlclose(handler);
            }
            _currentLib += 1;
            if (_currentLib >= _path.size())
                _currentLib = 0;
            handler = dlopen(_path[_currentLib].c_str(), RTLD_LAZY);
        }

    public:
        void *handler;
        std::vector<std::string> _path;
        int _currentLib;
};
