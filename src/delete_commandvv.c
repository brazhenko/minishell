/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commandvv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 07:47:52 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/16 07:47:55 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					delete_commandvv(char ***commandvv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (commandvv[i])
	{
		while (commandvv[i][j])
		{
			free(commandvv[i][j]);
			j++;
		}
		free(commandvv[i]);
		j = 0;
		i++;
	}
	free(commandvv);
	return (1);
}
