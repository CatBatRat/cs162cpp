# All cpp files here.
CC=main.cpp triangle.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) lab6.hpp# All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

tags: $(ALL)
	ctags $(ALL)

c: $(CC)
	clang++ -Wall -Wextra -Werror -std=c++11 $(CC) -o $(OUT)

t: $(OUT)
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
