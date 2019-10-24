/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:33:48 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/06 15:24:59 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp[size];
	int i;
	int n;

	i = 0;
	n = 0;
	while (i <= size)
	{
		temp[i] = tab[(size - i - 1)];
		i++;
	}
	while (n <= size)
	{
		tab[n] = temp[n];
		n++;
	}
}
