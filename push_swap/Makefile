# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:50:22 by mpeixeir          #+#    #+#              #
#    Updated: 2023/05/09 16:50:25 by mpeixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FUNCTIONS =		error_checker.c				instructions_a.c \
				instructions_b.c			instructions_both.c \
				lstnew.c					lstsize.c \
				lstiter.c					push_swap.c \
				stack_instructions.c		utils.c \
				utils_2.c					costs_to_top.c \
				ten_or_more.c				three_numbers.c	\
				five_to_nine.c				is_sorted.c

CC = 			cc

CFLAGS = 		-Wall -Werror -Wextra -g -fsanitize=address

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			push_swap

AR =			ar rc

PRTF =			ft_printf/libftprintf.a

LFT =			libft/libft.a

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${PRTF} ${LFT} ${CTOO} 
				${CC} $(CFLAGS) ${CTOO} -I libft -L libft -lft -Lft_printf -I . -lftprintf  -o ${NAME}

${LFT}:
				make -C libft
${PRTF}:
				make -C ft_printf
	
all:			${NAME}

clean:
				${RM} ${CTOO}
				make -C libft clean
				make -C ft_printf clean

fclean:			clean
				${RM} ${NAME}
				make -C libft fclean
				make -C ft_printf fclean

re:				fclean all
