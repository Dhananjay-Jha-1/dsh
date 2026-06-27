CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/shell.c src/parser.c src/executor.c src/builtins.c src/signals.c
 
OBJ = build/main.o build/shell.o build/parser.o build/executor.o build/builtins.o build/signals.o

OUT = build/dsh

build:
	mkdir -p build

#build build/dash first
all: $(OUT)

#now to build dash, its dependencies 
$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)     

build/main.o: src/main.c | build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/shell.o: src/shell.c | build
	$(CC) $(CFLAGS) -c src/shell.c -o build/shell.o

build/parser.o: src/parser.c | build
	$(CC) $(CFLAGS) -c src/parser.c -o build/parser.o

build/executor.o: src/executor.c | build
	$(CC) $(CFLAGS) -c src/executor.c -o build/executor.o

build/builtins.o: src/builtins.c | build
	$(CC) $(CFLAGS) -c src/builtins.c -o build/builtins.o

build/signals.o: src/signals.c | build
	$(CC) $(CFLAGS) -c src/signals.c -o build/signals.o

clean:
	rm -f build/*.o build/dsh
