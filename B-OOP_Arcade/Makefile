##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CPP			=	g++

## Sources ##
BIN_SRC		=	Core/src/Core.cpp		\
				Core/src/Error.cpp		\
				Core/src/Start_core.cpp	\

TEST_SRC	=	tests/unitTestsCore.cpp

INC			=	-I./Core/include/
#############

##	Obj	   ##
BIN_OBJ		=	$(BIN_SRC:.cpp=.o)
TEST_OBJ	=	$(TEST_SRC:.cpp=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(INC)
LDFLAGS		=	-ldl
#############

##	Names  ##
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	core games graphicals

core:	
	make -C Core/ -f Makefile -s
	mv Core/arcade ./

games:
	make -C Game/ -f Makefile -s
	mv Game/arcade_pacman.so ./lib
	mv Game/arcade_nibbler.so ./lib

graphicals:	
	make -C GraphicLib/ -f Makefile -s
	mv GraphicLib/arcade_sfml.so ./lib
	mv GraphicLib/arcade_ncurses.so ./lib
	mv GraphicLib/arcade_sdl2.so ./lib

# Unit Test
tests_run:	fclean
tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(BIN_OBJ) $(TEST_OBJ)
	$(CPP) -o $(TEST_BIN) $(BIN_SRC) $(TEST_SRC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

# Coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

# Clear
clean:
	rm -f $(TEST_OBJ)
	rm -f $(SRC_OBJ)
	make clean -C Core/ -f Makefile -s
	make clean -C GraphicLib/ -f Makefile -s
	make clean -C Game/ -f Makefile -s
	

fclean: clean
	rm -f ./arcade
	rm -f ./lib/arcade_sfml.so
	rm -f ./lib/arcade_ncurses.so
	rm -f ./lib/arcade_sdl2.so
	rm -f ./lib/arcade_nibbler.so
	rm -f ./lib/arcade_pacman.so
	rm -f *.gc**
	rm -f ${TEST_BIN}
	make fclean -C Core/ -f Makefile -s
	make fclean -C GraphicLib/ -f Makefile -s
	make fclean -C Game/ -f Makefile -s

# re
re : fclean all

# PHONY
.PHONY: all core games graphicals tests_run coverage clean fclean re