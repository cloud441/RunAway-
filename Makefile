CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic -std=c++17 -Isrc/\
		  -Itexture_pack/
SFMLFLAGS= -lsfml-graphics \
	-lsfml-window \
	-lsfml-system
DBFLAGS= -g

OBJS= src/runaway.o\
	  src/Game/Game.o\
	  src/SplashScreen/SplashScreen.o\
	  src/Menus/MainMenu.o\
	  src/Objects/VisibleObject.o\
	  src/Objects/Player.o\
	  src/Objects/Monsters/Monster.o\
	  src/Objects/Monsters/SadIsaac.o\
	  src/Objects/ObjectManager.o

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
