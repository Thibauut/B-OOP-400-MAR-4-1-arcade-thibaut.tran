/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** dlloader.hpp
*/

#pragma once

#include <iostream>
#include <dlfcn.h>

template<typename T>
class DLLoader {
    public:
        DLLoader(const std::string& filename) : handler(dlopen(filename.c_str(), RTLD_LAZY)) {}

        ~DLLoader() {
            if (handler != nullptr) {
                dlclose(handler);
            }
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
                std::cerr << "Failed to load library\n";
            }

            return instance;
        }

        void switchLibrary(const char* filename) {
            if (handler != nullptr) {
                dlclose(handler);
            }
            handler = dlopen(filename, RTLD_LAZY);
        }

    private:
        void *handler;
};
