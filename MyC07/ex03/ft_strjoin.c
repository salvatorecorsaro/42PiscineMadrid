/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:28:02 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/24 15:55:22 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcat(char *dest, char *src)
{
	int			i;
	int			a;

	a = 0;
	i = 0;
	while (dest[a] != '\0')
		a++;
	while (src[i] != '\0')
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = '\0';
	return (dest);
}

int			big_len_count(int size, char **strs, char *sep)
{
	int			big_counter;
	int			sep_counter;
	int			i;

	i = 0;
	big_counter = 0;
	sep_counter = ft_strlen(sep);
	while (i < size)
	{
		big_counter += ft_strlen(strs[i++]);
		if (i < size)
			big_counter += sep_counter;
	}
	return (big_counter);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int			big_counter;
	char		*dest_str;
	int			i;

	i = 0;
	big_counter = big_len_count(size, strs, sep);
	if (!(dest_str = malloc(big_counter + 1)))
		return (0);
	while (i < size)
	{
		ft_strcat(dest_str, strs[i++]);
		if (i < size)
			ft_strcat(dest_str, sep);
	}
	return (dest_str);
}
