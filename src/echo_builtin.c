/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:37:19 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:37:20 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				echo_builtin(char **argv, char **envp)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
