CC = gcc
FLAGS = -Wall -Werror -Wextra
EX = main
SRC = ./*.c

all: $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(EX)
clean: $(EX)
	rm $(EX)
