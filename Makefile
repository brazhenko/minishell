INC 		= inc
SRC 		= src
NAME 		= minishell
CC 			= gcc

all: 
	@$(CC) $(SRC)/minishell.c \
		$(SRC)/get_env.c \
		$(SRC)/parse_command.c \
		$(SRC)/execute_process.c \
		$(SRC)/ft_putbsn.c \
		$(SRC)/cd_builtin.c \
		$(SRC)/env_builtin.c \
		$(SRC)/try_get_env.c \
		$(SRC)/echo_builtin.c \
		$(SRC)/ctrl_c.c \
		$(SRC)/prompt.c \
		$(SRC)/delete_commandvv.c \
		$(SRC)/libft.a \
		-I $(INC) -o $(NAME)
	@echo COMPILED!

clean:
	
	
fclean: clean 
	rm -f $(NAME)

re: fclean all
