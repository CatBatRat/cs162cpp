# All cpp files here.
CC=main.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) # All other files go here.
# Output file name.
OUT=main # Replace with your output file.

setup:
	touch $(ALL)

c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)

r: $(OUT)
	mate-terminal -x ./$(OUT)
