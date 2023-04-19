
FUNCTIONS =		error_checker.c				instructions_a.c \
				instructions_b.c			instructions_both.c \
				lstnew.c					lstsize.c \
				lstiter.c					push_swap.c \
				stack_instructions.c		utils.c \
				utils_2.c					insertion_sort.c	\
				ten_or_more.c				costs_to_top.c

CC = 			cc

CFLAGS = 		-Wall -Werror -Wextra -g -fsanitize=address

RM = 			rm -f

CTOO = 			${FUNCTIONS:.c=.o}

NAME =			push_swap

AR =			ar rc

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