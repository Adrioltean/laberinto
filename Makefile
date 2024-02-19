OBJ = main.o maze.o util.o
CC = g++
CFLAGS = -Wall -g

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o laberinto

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

maze.o: maze.cpp
	$(CC) $(CFLAGS) -c $< -o $@

util.o: util.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ./*.o ./laberinto