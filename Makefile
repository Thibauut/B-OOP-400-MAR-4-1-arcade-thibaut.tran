##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-maori.dino
## File description:
## Makefile
##

SRC_SFML 	= 	Graphicals/sfml/SFML.cpp 						\

SRC_SDL 	= 	Graphicals/sdl2/arcade_sdl.cpp 					\

SRC_NCURSES = 	Graphicals/nCurses/arcade_ncurses.cpp 			\

SRC_SNAKE 	= 	Games/Snake/Snake.cpp 							\

SRC_PACMAN 	= 	Games/Pacman/PacMan.cpp 						\

SRC_SFT 	= 	Games/StreetFighTek/StreetFighTek.cpp 			\

BIN = arcade

all: graphicals games core

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(BIN)

games:
	g++ -shared -fPIC -o lib/arcade_snake.so $(SRC_SNAKE) -fno-gnu-unique -g3
	g++ -shared -fPIC -o lib/arcade_pacman.so $(SRC_PACMAN) -fno-gnu-unique
	g++ -shared -fPIC -o lib/arcade_sft.so $(SRC_SFT) -fno-gnu-unique

core:
	g++ main.cpp -ldl -o $(BIN) -fno-gnu-unique  -g3

graphicals:
	g++ -shared -fPIC -o lib/arcade_sfml.so $(SRC_SFML) -lsfml-graphics	-lsfml-audio -lsfml-window -lsfml-system
	g++ -shared -fPIC -o lib/arcade_sdl2.so $(SRC_SDL) -lSDL2_image -lSDL2_ttf -lSDL2 -lSDL2main -fno-gnu-unique
	g++ -shared -fPIC -o lib/arcade_ncurses.so $(SRC_NCURSES) -fno-gnu-unique -lncurses

re: fclean all

.PHONY: all fclean re
