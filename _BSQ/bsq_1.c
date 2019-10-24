/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:16:31 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/23 23:12:25 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "masterlib.h"

int		*ft_squarefinder(int **tab, int columns, int rows, int i)
{
	int j;
	int *bsq;

	bsq = ft_bsq_data();
	while (++i < rows - bsq[2])
	{
		j = 0;
		while (++j < columns - bsq[2])
		{
			while (1)
			{
				if ((i < rows - bsq[2] && j < columns - bsq[2]) &&
						(ft_possible(i, j, bsq[2], tab)))
				{
					bsq[2]++;
					bsq[0] = j;
					bsq[1] = i;
				}
				else
					break ;
			}
		}
	}
	return (bsq);
}

int		ft_validate_characters(int num_lines, char *str)
{
	int		i;
	int		line;
	char	items[3];
	int		c;

	c = 0;
	i = -1;
	line = 0;
	while (str[i] != '\n')
		i++;
	items[0] = str[i - 3];
	items[1] = str[i - 2];
	items[2] = str[i - 1];
	while (line < num_lines && str[++i])
	{
		if (str[i] == '\n')
			line++;
		else if (str[i] != items[0] && str[i] != items[1] && str[i] != items[2])
			return (-1);
		c = str[i] == items[0] ? 1 : c;
	}
	if (c == 0)
		ft_exit(-2);
	return (0);
}

int		ft_validate_lines(int num_lines, char *str, int expected_col, int i)
{
	int columns;
	int row_count;

	row_count = 0;
	columns = 0;
	while (str[i] != '\n' && str[i])
		i++;
	while ((row_count < num_lines && str[i]) && str[i] && (i++ || 1))
	{
		if (str[i] == '\n')
		{
			expected_col = expected_col == 0 ? columns : expected_col;
			if (columns != expected_col)
				ft_exit(-2);
			row_count++;
			columns = -1;
		}
		columns++;
	}
	if (row_count == num_lines)
		return (expected_col);
	else
		ft_exit(-2);
	return (-1);
}

int		ft_check_first_line(char *str, int i, int mul, int rows)
{
	int j;

	while (str[i] != '\n' && str[i])
		i++;
	if (i < 4)
		ft_exit(-2);
	if (((str[i - 1] == str[i - 2] && str[i - 1] == str[i - 3] &&
		str[i - 2] == str[i - 3]) && (str[i] >= 0 && str[i] <= 31)) ||
			str[i] == 127)
		ft_exit(-2);
	j = i - 3;
	while (--j >= 0)
	{
		if (str[j] >= '0' && str[j] <= '9')
			rows = rows + (str[j] - 48) * mul;
		else
			ft_exit(-2);
		mul *= 10;
	}
	if (rows == 0)
		ft_exit(-2);
	return (rows);
}

int		ft_exit(int code_err)
{
	if (code_err == -1)
		write(2, "memory error\n", 14);
	else if (code_err == -2)
	{
		write(2, "\nmap error\n\n", 11);
		while (++g_i < g_argc)
			ft_alpha(g_argv[g_i]);
	}
	else if (code_err == -3)
		write(2, "file error\n", 11);
	exit(EXIT_FAILURE);
	return (0);
}
