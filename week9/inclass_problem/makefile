# All cpp files here.
CC=main.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) # All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

tags: $(ALL)
	ctags $(ALL)

c: $(CC)
	clang++ -Wall -Wextra -Werror -std=c++11 $(CC) -o $(OUT)

cd: $(CC)
	clang++ -d -Wall -Wextra -Werror -std=c++11 $(CC) -o $(OUT)_debug

rd: $(OUT)_debug
	gdb $(OUT)_debug

t: $(OUT)
	clear
	kitty --hold ./$(OUT)

r:
	clear
	./$(OUT)
