/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeixeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:12:35 by mpeixeir          #+#    #+#             */
/*   Updated: 2022/10/27 16:12:37 by mpeixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

# define MLX_ERROR 1

# define BLACK_PIXEL 0x000000

typedef struct s_img
{
	void    *mlx_img;
	char    *addr;
	int     bpp; // bits per pixel
	int     line_len;
	int     endian;
}   t_img;

typedef struct s_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_img   img;
	int 	cur_img;
}   t_data;

void    render_background(t_data *data, int color)
{
	int i;
	int j;

	if (data->win_ptr == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, color);
		i++;

	}
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}

	printf("Keypress: %d\n", keysym);
	return (0);
}

int main(void)
{
	t_data data;
	char 	*relative_path = "./SHREKfrente.xpm";
	int 	img_width;
	int 	img_height;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "SHREK!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height)
	data.img.addr = mlx_get_data_addr(data.relative_path, &data.img.bpp, &data.img.line_len, &data.img.endian);

	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
