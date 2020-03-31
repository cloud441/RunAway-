CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic -std=c++17 -Isrc/
SFMLFLAGS= -lsfml-graphics \
	-lsfml-window \
	-lsfml-system
DBFLAGS= -g

OBJS= src/runaway.o\
	  src/Game/Game.o

BIN= "RunAway!!"



all: $(BIN)


$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SFMLFLAGS) -o $@ $^


debug:
	$(CXX) $(CXXFLAGS) $(SFMLFLAGS) $(DBFLAGS) -o $@ $^


test:
	echo "Not implemented yet!"

clean:
	$(RM) $(OBJS) $(BIN)


.PHONY: all clean debug
