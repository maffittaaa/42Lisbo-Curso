/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <mpeixeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:19:34 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/10/28 12:19:41 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define	WINDOW_HEIGHT 300
# define	WINDOW_WIDTH 600
# define	MLX_ERROR 1
# define	right	65363
# define	left	65361
# define	up		65362
# define	down	65364

typedef struct s_coords
{
	int			x;
	int 		y;
}t_coords;

typedef struct s_img
{
	void    	*mlx_img;
	char    	*addr;
	int     	bpp; // bits per pixel
	int     	line_len;
	int 		width;
	int 		height;
	int     	endian;
	t_coords	position;
}   t_img;

typedef struct s_data
{
	void    	*mlx_ptr;
	void    	*win_ptr;
	int 		cur_img;
	char		*img1;
	t_img		*img_list;
}   t_data;

#endif
