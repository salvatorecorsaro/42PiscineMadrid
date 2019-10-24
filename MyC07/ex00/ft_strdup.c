/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:43:02 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/20 18:23:50 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int			s;
	int			i;
	char		*stored;

	s = 0;
	i = 0;
	while (src[s] != '\0')
		s++;
	stored = (char *)malloc((s + 1) * (sizeof(char)));
	while (src[i] != '\0')
	{
		stored[i] = src[i];
		i++;
	}
	stored[i] = '\0';
	return (stored);
}
