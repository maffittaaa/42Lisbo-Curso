# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 17:39:40 by mpeixeir          #+#    #+#              #
#    Updated: 2022/03/09 15:42:41 by mpeixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS = ft_isalpha.c		ft_toupper.c 		\
			ft_isdigit.c		ft_tolower.c 		\
			ft_isalnum.c		ft_strchr.c 		\
			ft_isascii.c		ft_strrchr.c 		\
			ft_isprint.c		ft_strncmp.c 		\
			ft_strlen.c			ft_memchr.c 		\
			ft_memset.c			ft_memcmp.c 		\
			ft_bzero.c			ft_strnstr.c		\
			ft_memcpy.c			ft_atoi.c			\
			ft_memmove.c		ft_calloc.c 		\
			ft_strlcpy.c		ft_strdup.c 		\
			ft_strlcat.c		ft_strjoin.c		\
			ft_substr.c			ft_putstr_fd.c		\
			ft_putchar_fd.c		ft_putendl_fd.c		\
			ft_putnbr_fd.c		ft_strtrim.c		\
			ft_strmapi.c		ft_striteri.c		\
			ft_itoa.c			ft_split.c			

BONUS =  	ft_lstnew.c         ft_lstadd_front.c   \
		 	ft_lstsize.c        ft_lstlast.c        \
		 	ft_lstadd_back.c    ft_lstdelone.c      \
		 	ft_lstclear.c       ft_lstiter.c        \
		 	ft_lstmap.c

CC = 		cc

CFLAGS = 	-Wall -Werror -Wextra

RM = 		rm -f

CTOO = 		${FUNCTIONS:.c=.o}

BONUSTOO = 	${BONUS:.c=.o}

NAME = 		libft.a

AR =		ar rc

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${CTOO}
			${AR} ${NAME} ${CTOO}

all: 		${NAME}


clean:	
			${RM} ${CTOO} ${BONUSTOO}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${BONUSTOO} ${CTOO}
			${AR} ${NAME} ${BONUSTOO} ${CTOO}

.PHONY:		
			all clean fclean re

