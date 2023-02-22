.PHONY:	all

all:
	gcc -fsanitize=address -ggdb3 -Wall -Wextra -Werror -std=c11 -pedantic src/main.c -o main
