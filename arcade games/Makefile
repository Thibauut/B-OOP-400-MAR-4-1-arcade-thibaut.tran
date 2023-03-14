##
## EPITECH PROJECT, 2022
## arcade games
## File description:
## Makefile
##

SRC	=	test.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	= test

all	:	$(NAME)	$(SRC)

$(NAME)	:
	@printf "\x1B[1;34m\r[Compiling]               %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.5
	@g++	-o $(NAME) $(SRC) -g3	-std=c++20	-lsfml-graphics	-lsfml-window	-lsfml-system	-Wall	-Wextra	-Werror
	@printf "\x1B[1;32m\r[Compilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.3

clean :
	@rm	-f	$(OBJ)

fclean :
	@printf "\x1B[1;31m\r[Cleaning]                %$(SPACES)c\x1B[1;0m" ' '
	@sleep 1
	@rm	-f	$(NAME)
	@printf "\x1B[1;32m\r[Clean terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.5

re :	fclean	clean
	@printf "\x1B[1;33m\r[Recompiling]             %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.5
	@g++	-o $(NAME) $(SRC) -g3	-std=c++20	-lncurses	-lsfml-graphics	-lsfml-window	-lsfml-system
	@printf "\x1B[1;32m\r[Recompilation terminated]%$(SPACES)c\n\x1B[1;0m" ' '
	@sleep 0.3