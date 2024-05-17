CC = gcc

INCLUDE_DIR = ./include
SRC_DIR = ./src
LIB_DIR = ./lib
OBJ_DIR = ./obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIB = $(LIB_DIR)/libprime.a


OUTPUT = app
CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lprime

all: $(OUTPUT)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB): $(OBJS) | $(LIB_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT): main.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(OUTPUT)

.PHONY: all clean
