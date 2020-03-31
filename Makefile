CXX= g++
CXXFLAGS= -Wall -Wextra -Werror -pedantic -std=c++17
DBFLAGS= -g

OBJS= runaway.o
BIN= "RunAway!!"



all: $(BIN)


$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


debug:
	$(CXX) $(CXXFLAGS) $(DBFLAGS) -o $@ $^


clean:
	$(RM) $(OBJS) $(BIN)


.PHONY: all clean debug
