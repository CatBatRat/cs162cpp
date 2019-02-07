# All cpp files here.
CC=main.cpp board.cpp play.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) memgame.hpp # All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)

t: $(OUT)
	clear
	kitty --hold ./$(OUT)
r: $(OUT)
	clear
	./$(OUT)
