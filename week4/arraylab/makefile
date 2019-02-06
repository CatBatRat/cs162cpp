# All cpp files here.
# Additional cpp files here.
CC=main.cpp sorter.cpp thearray.cpp findin.cpp

# Additional files including hpp etc.
ALL=$(CC) arraylab.hpp

# Output file name.
OUT=numberfinder

clean:
	rm $(OUT)
c: $(CC)
	clang++ -Wall $(CC) -o $(OUT)
r: $(OUT)
	clear
	./$(OUT)
rt: $(OUT)
	clear
	mate-terminal -x ./$(OUT)
