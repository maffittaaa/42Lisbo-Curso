#PF_SRCS	=	ft_printf/ft_putbase10_plus.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	\
#			ft_printf/ft_putchar_fd.c		ft_printf/ft_putstr_fd.c	ft_printf/ft_printf.c	\
#			ft_printf/ft_printmemory.c

#PF_OBJS	=	${PF_SRCS:.c=.o}

SRCS	=	put_image.c

OBJS	=	${SRCS:.c=.o}

#PF_NAME	=	ft_printf/libftprintf.a

NAME	=	so_long

CC		=	cc

RM		=	rm -f

AR		=	ar rc

MLX		 = mlx_linux/libmlx_Linux.a

CFLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address

INC		=	-I/usr/include -O3 -I . -Imlx_linux

%.o: %.c
	@echo "\033[32mCompiling $< in fancy colors"
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS) $(MLX) #$(PF_NAME)
			#@make -C libft
			#@make -C mlx_linux
			$(CC) $(CFLAGS) $(OBJS) -I . -I ./libft -L ./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
		make -C mlx_linux
#$(PF_NAME):	${PF_OBJS}
#			${AR} $(PF_NAME) $(PF_OBJS)

all:		${NAME}

clean:

			@echo "Cleaning files in fancy colors"
			@${RM} ${OBJS} #${PF_OBJS}

fclean:		clean
			@${RM} ${NAME} #${PF_NAME}

re:			fclean	all
