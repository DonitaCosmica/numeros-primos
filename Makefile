# Definición de variables
CC = gcc
CFLAGS = -Wall
TARGET = app
SRC = main.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: clean
