##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

## Var def ##
SHELL		=	/bin/sh
CC			=	gcc
CPP			=	g++
RM			=	rm -f
#############

## Sources ##
MAIN		=

PACMAN_SRC	=	src/CreateGame.cpp	\
				src/Pacman.cpp

SNAKE_SRC	=	src/CreateGame.cpp	\
				src/Snake.cpp	\
				src/SnakeList.cpp

TEST_SRC	=

INC			=	-I./include/
#############

##	Obj	   ##
MAIN_OBJ	=	$(MAIN:.cpp=.o)
PACMAN_OBJ	=	$(PACMAN_SRC:.cpp=.o)
SNAKE_OBJ	=	$(SNAKE_SRC:.cpp=.o)
TEST_OBJ	=	$(TEST_SRC:.cpp=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(INC)
LDFLAGS		=	
#############

##	Names  ##
PACMAN		=	arcade_pacman.so
SNAKE		=	arcade_nibbler.so
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	$(PACMAN_OBJ) $(SNAKE_OBJ)
	$(CPP) -shared -o $(PACMAN) $(PACMAN_SRC) $(CFLAGS) $(CPPFLAGS) -fpic
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(PACMAN) | tr ' ' '.'
	$(CPP) -shared -o $(SNAKE) $(SNAKE_SRC) $(CFLAGS) $(CPPFLAGS) -fpic
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(SNAKE) | tr ' ' '.'

# Debug
debug:	fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	all

# Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(PACMAN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(PACMAN_OBJ) | tr ' ' '.'
	@$(RM) $(SNAKE_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SNAKE_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(PACMAN)
	@$(RM) $(SNAKE)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'

# re
re : fclean all

# PHONY
.PHONY: all debug tests_run coverage clean fclean re
