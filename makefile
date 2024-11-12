
CC = gcc
CFLAGS = -Wall -g
TARGET = main
SRC = main.c 1.c
OBJ = main.o 1.o
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c 1.h
	$(CC) $(CFLAGS) -c main.c

1.o: 1.c 1.h
	$(CC) $(CFLAGS) -c 1.c

clean:
	rm -f $(OBJ) $(TARGET)
