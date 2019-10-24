/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:28:47 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/24 15:35:03 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_malloc_range(int *i, int min, int max)
{
	int			c_min;
	int			c_max;
	int			*range;

	c_min = min;
	c_max = max;
	*i = 0;
	while (c_min < c_max)
	{
		*i = *i + 1;
		c_min++;
	}
	range = (int *)malloc(*i * (sizeof(int)));
	return (range);
}

int			ft_ultimate_range(int **range, int min, int max)
{
	int			w;
	int			i;
	int			*ran_val;

	ran_val = &i;
	w = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = ft_malloc_range(ran_val, min, max);
	while (min < max)
	{
		range[0][w] = min;
		min++;
		w++;
	}
	return (i);
}
