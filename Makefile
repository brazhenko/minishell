INC = inc
SRC = src
NAME = minishell

all: 
	@gcc $(SRC)/minishell.c \
		$(SRC)/get_env.c \
		$(SRC)/parse_command.c \
		$(SRC)/execute_process.c \
		$(SRC)/ft_putbsn.c \
		$(SRC)/cd_buildin.c \
		$(SRC)/libft.a \
		-I $(INC) -o minishell
