TARGET = app
SRCS = main.c src/prime.c src/input.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
