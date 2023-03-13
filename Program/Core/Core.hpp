/*
** EPITECH PROJECT, 2022
** B-OOP-400-MAR-4-1-arcade-maori.dino
** File description:
** Core.hpp
*/

#include "../Interfaces/IDisplay.hpp"
#include "../Interfaces/IGame.hpp"

class Core {
    public:
        Core();
        ~Core();

        // Setters
        void setDisplay(IDisplay *display);
        void setGame(IGame *game);

        // Getters
        IDisplay *getDisplay() const;
        IGame *getGame() const;

    protected:
        IDisplay *_currentDisplay;
        IGame *_currentGame;
};