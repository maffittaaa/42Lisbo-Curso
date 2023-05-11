FUNCTIONS:		server.c		client.c

CC:				cc

CFLAGS = 		-Wall -Werror -Wextra -g -fsanitize=address

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			minitalk

AR =			ar rc

PRTF =			ft_printf/libftprintf.a

LFT =			libft/libft.a

.c.o:
				${CC} ${CFLAGS}  -I. -L. -I ./libft -L ./libft -lft -c $< -o ${<:.c=.o}

$(NAME):		${CTOO} ${LFT}
				${CC} $(CFLAGS) ${CTOO} -I. -L. -I ./libft -L ./libft -lft -o ${NAME}

${LFT}:
				make -C libft
	
all:			${NAME}

clean:
				${RM} ${CTOO}
				make -C libft clean

fclean:			clean
				${RM} ${NAME}
				make -C libft fclean

re:				fclean all