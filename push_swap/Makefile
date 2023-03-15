

FUNCTIONS =		error_checker.c				instructions_a.c \
				instructions_b.c			instructions_both.c \
				lstnew.c					lstsize.c \
				lstiter.c					push_swap.c \
				stack_instructions.c		utils.c \
				utils_2.c					


CC = 			gcc

CFLAGS = 		-Wall -Werror -Wextra 

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			push_swap

AR =			ar rc

.c.o:
				${CC} ${CFLAGS}  -I. -L. -I ./libft -L ./libft -lft -c $< -o ${<:.c=.o}

$(NAME):		${CTOO} libft/libft.a
				${CC} $(CFLAGS) ${CTOO} -I. -L. -I ./libft -L ./libft -lft -o ${NAME}

libft/libft.a:
				make -C libft
	
all:			${NAME}

clean:
				${RM} ${CTOO}

fclean:			clean
				${RM} ${NAME}

re:				fclean all