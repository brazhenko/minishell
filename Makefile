INC = inc
SRC = src
NAME = minishell

all : $NAME

$NAME:
	gcc -Wextra minishell.c -I $(INC) -o minishell