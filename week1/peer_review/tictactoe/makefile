CC=main.cpp
HEADER=tictac.hpp
LIBS=game.cpp dialog.cpp
OUT=tictactoe

c: $(CC) $(HEADER) $(LIBS)
	g++ -Wall $(CC) $(HEADER) $(LIBS) -o $(OUT) -std=c++11

r: $(OUT)
	clear
	mate-terminal -x ./$(OUT)
