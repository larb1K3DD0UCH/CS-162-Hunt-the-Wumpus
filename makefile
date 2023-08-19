# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11

# Source files
SRC_FILES = bats.cpp   game.cpp  main.cpp  room.cpp \
			event.cpp  gold.cpp  pit.cpp   wumpus.cpp
# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)
# Executable name
EXEC = Hunt_Wumpus

# Targets and rules
all: $(EXEC)
	rm -f *.o

$(EXEC): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(EXEC)

