

FUNCTIONS =		error_checker.c				instructions_a.c \
				instructions_b.c			instructions_both.c \
				lstnew.c					push_swap.c \
				stack_instructions.c		utils.c \
				utils_2.c

CC = 			cc

CFLAGS = 		-Wall -Werror -Wextra -I libft -L ./libft -lft

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			push_swap

AR =			ar rc

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${CTOO} libft/libft.a
				${CC} $(CFLAGS) -o ${NAME} ${CTOO}

libft/libft.a:
			make -C libft
	
all:			${NAME}

clean:
				${RM} ${CTOO}

fclean:			clean
				${RM} ${NAME}

re:				fclean all