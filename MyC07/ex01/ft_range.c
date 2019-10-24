/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:52:17 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/20 18:26:54 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_nullrangecheck(int min, int max)
{
	int *null;

	null = 0;
	if (min >= max)
	{
		return (null);
	}
	return (0);
}

int	*ft_malloc_range(int min, int max)
{
	int			c_min;
	int			c_max;
	int			i;
	int			*range;

	c_min = min;
	c_max = max;
	i = 0;
	while (c_min < c_max)
	{
		i++;
		c_min++;
	}
	range = (int *)malloc(i * (sizeof(int)));
	return (range);
}

int	*ft_range(int min, int max)
{
	int			*range;
	int			w;

	w = 0;
	if (min >= max)
		return (ft_nullrangecheck(min, max));
	range = ft_malloc_range(min, max);
	while (min < max)
	{
		range[w] = min;
		min++;
		w++;
	}
	return (range);
}
