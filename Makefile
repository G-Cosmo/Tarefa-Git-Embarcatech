EXEC = ConversorDeUnidades.exe

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ConversorDeUnidades.c Conversores.c
OBJ = $(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean run
