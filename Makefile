.PHONY:	all

all:
	gcc -fsanitize=address -ggdb3 -Wall -Wextra -Werror -std=c11 -pedantic -o main main.c