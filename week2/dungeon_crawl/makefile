CPP=main.cpp logic.cpp room.cpp tools.cpp funcs.cpp monster.cpp
HEADER=dungeon.hpp qolife.hpp
OUT=dungeon-crawl

c: $(CPP)
	clang++ -Wall $(CPP) -o $(OUT) -std=c++11

r: $(OUT)
	mate-terminal -x ./$(OUT)
