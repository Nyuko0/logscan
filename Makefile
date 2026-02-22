CC = gcc
CFLAGS = -std=c99 -Werror -Wall -Wextra -Wvla -pedantic

SRC= src/logscan.c src/cli.c src/parser.c src/level.c src/filter.c
OBJ=$(SRC:.c=.o)

TARGET = logscan

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -I./include/

test: RULE = test
test: CFLAGS += -fsanitize=address -g
test: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I./include/
clean: RULE = clean
clean:
	$(RM) test $(TARGET) $(OBJ)
