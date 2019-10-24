/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:53:52 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/11 08:12:24 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int a;

	a = 0;
	i = 0;
	while (src[a] != '\0')
		a++;
	if (size == 0)
		return (a);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size - 1)
	{
		dest[i] = '\0';
		i++;
	}
	dest[size - 1] = '\0';
	return (a);
}
