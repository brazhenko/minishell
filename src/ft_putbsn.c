//
// Created by Lommy greenhands Reznak mo reznak on 2019-02-09.
//

#include "libft.h"

int 			ft_strbsn_len(char *str)
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

void				ft_putbsn(char *str)
{
	write(1, str, ft_strbsn_len(str));
}