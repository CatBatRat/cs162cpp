# All cpp files here.
CC=main.cpp Car.cpp CarList.cpp# Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) Car.h CarList.h # All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

tags: $(ALL)
	ctags $(ALL)

c: $(CC)
	clang++ -g -Wall -Wextra -Werror -std=c++11 $(CC) -o $(OUT)

t: $(OUT)
	clear
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
