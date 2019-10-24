/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:54:49 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/11 08:44:57 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		to_hexa(char x)
{
	char		*base;

	base = "0123456789abcdef";
	if (x > 16)
	{
		to_hexa(x / 16);
		to_hexa(x % 16);
	}
	else
		ft_putchar(base[x]);
}

void		ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) ||
				str[i] == 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			to_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
