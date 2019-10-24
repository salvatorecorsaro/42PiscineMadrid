/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:44:46 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/23 23:11:25 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "masterlib.h"

void	ft_init(char *items, char *str, int i)
{
	items[0] = str[i - 1];
	items[1] = str[i - 2];
	items[2] = str[i - 3];
}

void	ft_navigator(int *obs_value, int **tab, int row, int col)
{
	obs_value[0] = tab[row - 1][col];
	obs_value[1] = tab[row][col - 1];
	obs_value[2] = tab[row - 1][col - 1];
	tab[row][col] = obs_value[0] + obs_value[1] - obs_value[2] + obs_value[3];
}

void	ft_intmap(int **tab, int max_col, int max_row, char *str)
{
	t_intmap s;

	s.i = 0;
	s.col = -1;
	s.row = 0;
	while (str[s.i] != '\n')
		s.i++;
	ft_init(s.items, str, s.i);
	while (max_row > s.row && (++s.col || 1))
	{
		s.obs_value[3] = str[s.i] == s.items[1] ? 1 : 0;
		if (s.col == max_col)
		{
			s.row++;
			s.col = -1;
			s.i++;
		}
		else if (s.col != 0 && s.row != 0)
		{
			ft_navigator(s.obs_value, tab, s.row, s.col);
			s.i++;
		}
		else
			tab[s.row][s.col] = 0;
	}
}

int		ft_possible(int row, int col, int size, int **val_tab)
{
	int abcd;
	int a;
	int ac;
	int ab;

	abcd = val_tab[row + size][col + size];
	a = val_tab[row - 1][col - 1];
	ac = val_tab[row + size][col - 1];
	ab = val_tab[row - 1][col + size];
	if (abcd - ac - ab + a > 0)
		return (0);
	return (1);
}

int		*ft_bsq_data(void)
{
	int *bsq;

	bsq = malloc(12);
	if (bsq == 0)
		ft_exit(-1);
	bsq[0] = -1;
	bsq[1] = -1;
	bsq[2] = 0;
	return (bsq);
}
