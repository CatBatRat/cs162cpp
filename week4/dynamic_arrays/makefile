# All cpp files here.
CC=main.cpp # Additional cpp files here.
# Additional files including hpp etc.
ALL=$(CC) # All other files go here.
# Output file name.
OUT=out # Replace with your output file.

setup:
	touch $(ALL)

c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)

rt: $(OUT)
	clear
	mate-terminal -x ./$(OUT)
rc: $(OUT)
	clear
	./$(OUT)
