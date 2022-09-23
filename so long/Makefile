# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 18:05:08 by mpeixeir          #+#    #+#              #
#    Updated: 2022/09/22 18:08:35 by mpeixeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #








%.o:	%.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -03 -c $< -o $@

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
