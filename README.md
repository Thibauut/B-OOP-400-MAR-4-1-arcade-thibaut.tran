
# Arcade
Arcade is a game platform from the "Object-Oriented Programming" module and is a project for our 2nd year at EPITECH. It is a program that allows the user to choose a game and keeps a record of the players' states. There are two games that can be used with three interchangeable graphics libraries at any time during the game.

## Requirements

- C++ compiler
- Makefile
- Core, games, display separated
- 3 graphic libs differents


## Librairies
### Graphic
We include `3` graphic libs:
- SFML
- SDL
- NCURSES

### Game
We have created `2` game libs:
- Pacman
- Snake

## Build

```
make re
```

## Usage
```bash
USAGE:
  ./arcade path_to_graphic_lib

DESCRIPTION:
  lib         path to the initial graphical library to load (./lib/arcade_lib_name.so)

COMMANDS:
  ?           next graphic lib
  ?           previous graphic lib
  ?           next game lib
  ?           previous game lib

  ?           menu
  ?           reset the game
  ESC         quit arcade
```

## Documentation
In progress...

## Contributors

- [Maori Dino](https://github.com/MaoKoro)
- [Thibaut Tran]
- [Yanis Denat]