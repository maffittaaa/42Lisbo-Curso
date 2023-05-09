# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 15:31:57 by mpeixeir          #+#    #+#              #
#    Updated: 2022/03/15 19:26:46 by mpeixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS =		ft_printf.c			ft_printf_functions.c \
				ft_printf_functionspt2.c

CTOO = 			${FUNCTIONS:.c=.o}

CC =			cc

CFLAGS =		-Wall -Werror -Wextra

RM =			rm -f

NAME =			libftprintf.a

AR =			ar rc

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${CTOO}
				${AR} ${NAME} ${CTOO}
	
all:			${NAME}

clean:
				${RM} ${CTOO}

fclean:			clean
				${RM} ${NAME}

re:				fclean all


