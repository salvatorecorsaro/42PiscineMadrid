/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:46:53 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/23 23:22:36 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "masterlib.h"

char	*ft_parsemap(char *map_file, int cont, int aux, char c)
{
	int		file;
	char	*str;

	file = open(map_file, O_RDONLY);
	if (file < 0)
	{
		write(1, "file error\n", 11);
		exit(EXIT_FAILURE);
	}
	while (aux > 0 && (++cont || 1))
		aux = read(file, &c, 1);
	str = malloc(cont);
	close(file);
	if (str == 0)
		ft_exit(-3);
	file = open(map_file, O_RDONLY);
	if (file < 0)
	{
		write(1, "file error\n", 11);
		exit(EXIT_FAILURE);
	}
	read(file, str, cont);
	close(file);
	return (str);
}

int		ft_write_file(char *file_name)
{
	char	c;
	int		file;

	file = open(file_name, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	if (file == 0)
		return (-1);
	while ((read(0, &c, 1) && c != 0))
		write(file, &c, 1);
	close(file);
	return (0);
}

void	ft_printmap(int *bsq, char *str_map, int num_of_rows)
{
	int		i;
	int		line;
	int		column;
	char	sqr_char;

	bsq[1]--;
	line = -1;
	i = -1;
	while (str_map[i] != '\n')
		i++;
	sqr_char = str_map[i - 1];
	while (line < num_of_rows)
	{
		if (str_map[i] == '\n')
			write(1, str_map + i, 1);
		else if (line >= bsq[1] && line < bsq[1] + bsq[2]
				&& column >= bsq[0] && column < bsq[0] + bsq[2])
			write(1, &sqr_char, 1);
		else
			write(1, str_map + i, 1);
		line = str_map[i] == '\n' ? line + 1 : line;
		column = str_map[i] == '\n' ? 0 : column;
		column++;
		i++;
	}
}

void	ft_alpha(char *filename)
{
	t_alpha s;

	s.str_map = ft_parsemap(filename, 0, 1, 1);
	s.num_of_rows = ft_check_first_line(s.str_map, 0, 1, 0);
	s.num_of_columns = ft_validate_lines(s.num_of_rows, s.str_map, 0, 0);
	if (s.num_of_rows == -1 || s.num_of_columns == -1 ||
			ft_validate_characters(s.num_of_rows, s.str_map))
		ft_exit(-2);
	s.aux = -1;
	s.tab = malloc((s.num_of_rows + 1) * 8);
	s.aux = s.tab == 0 ? ft_exit(-1) : s.aux;
	while (++s.aux <= s.num_of_rows)
	{
		s.tab[s.aux] = malloc((s.num_of_columns + 1) * 4);
		s.aux = s.tab[s.aux] == 0 ? ft_exit(-1) : s.aux;
	}
	ft_intmap(s.tab, s.num_of_columns + 1, s.num_of_rows + 1, s.str_map);
	s.bsq = ft_squarefinder(s.tab, s.num_of_columns + 1, s.num_of_rows + 1, 0);
	ft_printmap(s.bsq, s.str_map, s.num_of_rows);
	free(s.bsq);
	while (--s.num_of_rows >= 0)
		free(s.tab[s.num_of_rows]);
	free(s.tab);
	free(s.str_map);
}

int		main(int argc, char **argv)
{
	g_i = 0;
	if (argc > 1)
	{
		g_argv = malloc(8 * argc - 1);
		g_argc = argc;
		while (++g_i < argc)
			g_argv[g_i] = argv[g_i];
		g_i = 0;
		while (++g_i < g_argc)
			ft_alpha(g_argv[g_i]);
	}
	else
	{
		ft_write_file("kk.txt");
		ft_alpha("kk.txt");
	}
}
