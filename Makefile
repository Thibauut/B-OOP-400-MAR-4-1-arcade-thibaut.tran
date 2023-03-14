##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-arcade-maori.dino
## File description:
## Makefile
##

SRC_SFML 	= 	lib_dynamic/arcade_sfml.cpp 		\

SRC_SDL 	= 	lib_dynamic/arcade_sdl.cpp 			\

SRC_NCURSES 	= 	lib_dynamic/arcade_ncurses.cpp 	\

BIN = arcade

all: graphicals
	g++ main.cpp -ldl -o $(BIN) -fno-gnu-unique -lsfml-graphics	-lsfml-window -lsfml-system

clean:
	rm -f lib/*.so

fclean: clean
	rm -f $(BIN)

graphicals:
	g++ -shared -fPIC -o lib/arcade_sfml.so $(SRC_SFML) -fno-gnu-unique
	g++ -shared -fPIC -o lib/arcade_sdl.so $(SRC_SDL) -fno-gnu-unique
	g++ -shared -fPIC -o lib/arcade_ncurses.so $(SRC_NCURSES) -fno-gnu-unique

re: fclean all

.PHONY: all fclean re
