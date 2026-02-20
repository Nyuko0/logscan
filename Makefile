CC = gcc
CFLAGS = -std=c99 -Werror -Wall -Wextra -Wvla -pedantic

SRC= src/logscan.c src/cli.c
OBJ=$(SRC:.c=.o)

TARGET = logscan

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: RULE = test
test: CFLAGS += -fsanitize=address -g
test: $(OBJ)

clean: RULE = clean
clean:
	$(RM) test $(TARGET) $(OBJ)
