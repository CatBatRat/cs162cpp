CPP=main.cpp logic.cpp display.cpp tools.cpp funcs.cpp
HEADER=dungeon.hpp qolife.hpp
OUT=dungeon-crawl

c: $(CPP) $(HEADER)
	g++ -Wall $(CPP) $(HEADER) -o $(OUT) -std=c++11

r: $(OUT)
	mate-terminal -x ./$(OUT)
