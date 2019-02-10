INC = inc
SRC = src
NAME = minishell

all: 
	@gcc $(SRC)/minishell.c \
		$(SRC)/get_env.c \
		$(SRC)/parse_command.c \
		$(SRC)/execute_process.c \
		$(SRC)/ft_putbsn.c \
		$(SRC)/cd_builtin.c \
		$(SRC)/env_builtin.c \
		$(SRC)/try_get_env.c \
		$(SRC)/echo_builtin.c \
		$(SRC)/libft.a \
		-I $(INC) -o minishell
