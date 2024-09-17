CC = gcc
FLAGS = -Wall -Werror -Wextra
EX = main
SRC = main.c files.c memory.c strings.c

all: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(EX)
clean: $(EX)
	rm $(EX)
