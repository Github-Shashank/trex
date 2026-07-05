CC = gcc

CFLAGS = -std=c11 -Wall -Wextra -Werror -Iinclude

# SRC = $(wildcard src/*.c)
# SRC = src/main.c src/file.c
SRC = src/main.c \
      src/file.c \
      src/platform.c

OBJ = $(SRC:.c=.o)

TARGET = trex

all: $(TARGET)

$(TARGET): $(OBJ)
# 	$(CC) $(OBJ) -lncurses -o $(TARGET)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)