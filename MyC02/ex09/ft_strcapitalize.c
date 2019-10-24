/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:53:04 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/11 09:16:09 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	tolowcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (*(str));
}

char	*ft_strcapitalize(char *str)
{
	int i;

	tolowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[i] = str[i] - 32;
			i++;
		}
		if ((str[i - 1] >= ' ' && str[i - 1] <= '/') ||
				(str[i - 1] >= ':' && str[i - 1] <= '@') ||
				(str[i - 1] >= '[' && str[i - 1] <= '`') ||
				(str[i - 1] >= '{' && str[i - 1] <= '~'))
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
