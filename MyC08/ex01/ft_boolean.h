/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:01:30 by scorsaro          #+#    #+#             */
/*   Updated: 2019/10/19 19:16:50 by scorsaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define EVEN(x)	x % 2 == 0
# define TRUE	1
# define FALSE	0
# define SUCCESS 0
# define EVEN_MSG	"I have an even number of arguments."
# define ODD_MSG	"I have an odd number of arguments."

typedef	int	t_bool;
#endif
