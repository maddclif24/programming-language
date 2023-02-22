.PHONY:	all

all:
	gcc -fsanitize=address -ggdb3 -Wall -Wextra -Werror -std=c11 -pedantic -Iinclude src/main.c -o main
