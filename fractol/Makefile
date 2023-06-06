/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:18:46 by mpeixeir          #+#    #+#             */
/*   Updated: 2023/05/03 18:18:48 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

FUNCTIONS =		fractol.c			utils.c		\


CC = 			cc

CFLAGS = 		-Wall -Werror -Wextra -g -fsanitize=address

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			fractol

AR =			ar rc

PRTF =			ft_printf/libftprintf.a

LFT =			libft/libft.a

.c.o:
				${CC} ${CFLAGS} -I/usr/include -Imlx_linux -03 -c $< -o ${<:.c=.o}

$(NAME):		${PRTF} ${LFT} ${CTOO} 
				${CC} $(CFLAGS) ${CTOO} -I libft -L libft -lft -Lft_printf -I . -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

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
