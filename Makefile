CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): main.o MainMenu.o MenuMap.o MoreGame.o PauseGame.o StateMan.o Game.o GamePlay.o GameOver.o DuckGravity.o AssetMan.o HitBox.o
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)
HitBox.o: $(SRC)/HitBox.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
main.o: $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^ 
MainMenu.o: $(SRC)/MainMenu.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
MenuMap.o: $(SRC)/MenuMap.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
MoreGame.o: $(SRC)/MoreGame.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
PauseGame.o: $(SRC)/PauseGame.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
StateMan.o: $(SRC)/StateMan.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
Game.o: $(SRC)/Game.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
GamePlay.o: $(SRC)/GamePlay.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
GameOver.o: $(SRC)/GameOver.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
DuckGravity.o: $(SRC)/DuckGravity.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^
AssetMan.o: $(SRC)/AssetMan.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) -c $^

clean:
	-rm *.o  $(BIN)/*
