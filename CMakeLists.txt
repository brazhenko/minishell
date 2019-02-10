cmake_minimum_required(VERSION 3.13)
project(minishell)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)
add_executable(minishell src/minishell.c src/execute_process.c src/get_env.c src/ft_putbsn.c src/parse_command.c src/cd_builtin.c src/env_builtin.c src/try_get_env.c src/echo_builtin.c)