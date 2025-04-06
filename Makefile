# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I. -g -fsanitize=address -fsanitize=undefined
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -fsanitize=address -fsanitize=undefined

# Source files and object files
# SRCS = main.cpp src/*.cpp
SRCS = main.cpp src/option.cpp src/button.cpp src/menu.cpp src/mainmenu.cpp src/play.cpp src/controls.cpp src/lobby.cpp src/credits.cpp src/menumanager.cpp src/components.cpp src/Entity.cpp src/EntityManager.cpp src/resourcemanager.cpp src/mymap.cpp src/camera.cpp src/game.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = main

.PHONY: all clean

# Default target: build the program
all: $(TARGET)

# Linking the object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compiling the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the target
clean:
	rm -f $(OBJS) $(TARGET)
