# All cpp files here.
# Additional cpp files here.
CC=main.cpp selection.cpp binsearch.cpp thearray.cpp

# Additional files including hpp etc.
ALL=$(CC) arraylab.hpp

# Output file name.
OUT=out

clean:
	rm $(OUT)
c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)
rt: $(OUT)
	clear
	mate-terminal -x ./$(OUT)
rc: $(OUT)
	clear
	./$(OUT)
