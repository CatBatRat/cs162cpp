# All cpp files here.
CC=main.cpp recursion.cpp
# Additional files including hpp etc.
ALL=$(CC) recursion.hpp # All other files go here.
# Output file name.
OUT=main # Replace with your output file.

setup:
	touch $(ALL)

c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)

r: $(OUT)
	clear
	./$(OUT)
