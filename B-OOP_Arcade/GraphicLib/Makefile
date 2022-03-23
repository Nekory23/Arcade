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
MAIN		=	src/Main.cpp

SFML_SRC	=	src/CreateGraph.cpp		\
				src/SfmlFunction.cpp

NCURSES_SRC	=	src/CreateGraph.cpp		\
				src/NcursesFunction.cpp

SDL_SRC		=	src/CreateGraph.cpp		\
				src/Sdl2Function.cpp

TEST_SRC	=

INC			=	-I./include/
#############

##	Obj	   ##
MAIN_OBJ	=	$(MAIN:.cpp=.o)
SFML_OBJ	=	$(SMFL_SRC:.cpp=.o)
NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)
SDL_OBJ		=	$(SDL_SRC:.cpp=.o)
TEST_OBJ	=	$(TEST_SRC:.cpp=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(INC)
LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lncurses -lSDL2 -lSDL2_image -lSDL2_ttf
#############

##	Names  ##
SFML		=	arcade_sfml.so
NCURSES		=	arcade_ncurses.so
SDL			=	arcade_sdl2.so
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	$(SFML_OBJ) $(NCURSES_OBJ) $(SDL_OBJ)
	$(CPP) -shared -o $(SFML) $(SFML_SRC) $(CFLAGS) -g -fPIC $(LDFLAGS) $(CPPFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(SFML) | tr ' ' '.'
	$(CPP) -shared -o $(NCURSES) $(NCURSES_SRC) $(CFLAGS) -g -fPIC $(LDFLAGS) $(CPPFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NCURSES) | tr ' ' '.'
	$(CPP) -shared -o $(SDL) $(SDL_SRC) $(CFLAGS) -g -fPIC $(LDFLAGS) $(CPPFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(SDL) | tr ' ' '.'

test:	$(MAIN_OBJ) $(BIN_OBJ)
	$(CPP) -o test $(MAIN_OBJ) $(BIN_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

# Debug
debug:	fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	all

# Unit Test
tests_run:	fclean
tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(SRC_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_BIN) $(BIN_SRC) $(TEST_SRC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

# Coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

# Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(SFML_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SFML_OBJ) | tr ' ' '.'
	@$(RM) $(NCURSES_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NCURSES_OBJ) | tr ' ' '.'
	@$(RM) $(SDL_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SDL_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(SFML)
	@$(RM) $(NCURSES)
	@$(RM) $(SDL)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(BIN_OBJ) | tr ' ' '.'
	@$(RM) */*.gc*
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

# re
re : fclean all

# PHONY
.PHONY: all debug tests_run coverage clean fclean re