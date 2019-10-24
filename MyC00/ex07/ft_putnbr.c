/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:44:05 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/17 16:44:19 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb = -lnb;
	}
	if (lnb > 9)
		ft_putnbr(lnb / 10);
	ft_putchar(lnb % 10 + '0');
}
