/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbsn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:36:33 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/11 10:36:35 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strbsn_len(char *str)
{
	int i;

	i = 0;
	while (*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (i + 1);
}

void			ft_putbsn(char *str)
{
	write(1, str, ft_strbsn_len(str));
}
