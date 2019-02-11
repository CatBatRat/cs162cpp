# All cpp files here.
CC=main.cpp board.cpp play.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) memgame.hpp # All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

tags: $(ALL)
	ctags $(ALL)

c: $(CC)
	clang++ -Wall -Wextra -Werror -std=c++11 -pedantic $(CC) -o $(OUT)

t: $(OUT)
	clear
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
