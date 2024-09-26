CC = gcc
FLAGS = -Wall -Werror -Wextra
EX = main
SRC = memory.c files.c  main.c parse_buffer.c  solve_map.c strings.c
GEN = ./map_gen.c

all: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(EX)
clean:
	@rm $(EX) gen
gen: $(GEN)
	$(CC) $(FLAGS) $(GEN) -o gen
