# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorsaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 23:13:36 by scorsaro          #+#    #+#              #
#    Updated: 2019/10/23 23:16:43 by scorsaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= bsq_1.c bsq_2.c bsq_main.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
