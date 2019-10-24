/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   masterlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:58:15 by eherrero          #+#    #+#             */
/*   Updated: 2019/10/23 22:57:31 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTERLIB_H
# define MASTERLIB_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	**g_argv;
int		g_argc;
int		g_i;

typedef struct		s_intmap
{
	int		i;
	int		row;
	int		col;
	int		obs_value[4];
	char	items[3];
}					t_intmap;

typedef	struct		s_alpha
{
	char	*str_map;
	int		**tab;
	int		*bsq;
	int		aux;
	int		num_of_rows;
	int		num_of_columns;
}					t_alpha;

void				ft_init(char *items, char *str, int i);
void				ft_navigator(int *obs_value, int **tab, int row, int col);
void				ft_intmap(int **tab, int max_col, int max_row, char *str);
void				ft_print_map(int *bsq, char *str_map, int num_of_rows);
void				ft_alpha(char *filename);

int					ft_exit(int i);
int					ft_possible(int row, int col, int size, int **val_tab);
int					ft_validate_characters(int num_lines, char *str);
int					ft_validate_lines(int n_lines, char *str, int e_col, int i);
int					ft_check_first_line(char *str, int i, int mul, int rows);
int					ft_write_file(char *filename);

int					*ft_bsq_data(void);
int					*ft_squarefinder(int **tab, int columns, int rows, int i);

char				*ft_parse_map(char *map_file, int cont, int aux, char c);

#endif
