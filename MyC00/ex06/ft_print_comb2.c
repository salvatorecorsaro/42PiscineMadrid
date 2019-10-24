/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:58:28 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/05 21:04:24 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int a[2];

	a[0] = -1;
	while (a[0]++ < 99)
	{
		a[1] = -1;
		while (a[1]++ < 99)
		{
			if (a[0] < a[1])
			{
				if (!(a[0] == 0 && a[1] == 1))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				ft_putchar(a[0] / 10 + '0');
				ft_putchar(a[0] % 10 + '0');
				ft_putchar(' ');
				ft_putchar(a[1] / 10 + '0');
				ft_putchar(a[1] % 10 + '0');
			}
		}
	}
}
