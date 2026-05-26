CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/shell.c

OBJ = build/main.o build/shell.o

OUT = build/dash

#build build/dash first
all: $(OUT)

#now to build dash, its dependencies 
$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)     

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/shell.o: src/shell.c
	$(CC) $(CFLAGS) -c src/shell.c -o build/shell.o


clean:
	rm -f build/*.o build/dash
