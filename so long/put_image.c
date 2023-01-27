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

#include "so_long.h"

int render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_list->mlx_img, data->img_list->x, data->img_list->y);
	if(data->img_list->x == 0)
    	return (0);
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}
	if (keysym == 65363 && data->img_list->x < WINDOW_WIDTH - data->img_list->width)
		data->img_list->x += 25;
	if (keysym == 65361 && data->img_list->x > 0)
		data->img_list->x -= 25;
	if (keysym == 65364 && data->img_list->y < WINDOW_HEIGHT - data->img_list->height)
		data->img_list->y += 25;
	if (keysym == 65362 && data->img_list->y > 0)
		data->img_list->y -= 25;
	printf("Keypress: %d\n", keysym);return (0);
	return (0);
}

int main(void)
{
	t_data data;

	data.relative_path = ft_strdup("images/SHREKdireita.xpm");
	data.relative_path2 = ft_strdup("images/SHREKesquerdo.xpm");
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT, "SHREK!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.img_list=(malloc(2) * (sizeof(t_img)));
	data.img_list[2] = NULL;
	data.i = 0;
	while(data.i < 2)
	{
		data.img_list[data.i].width = 200;
		data.i++;
	}
	data.img_list->height = 200;
	data.img_list->x = 0;
	data.img_list->y = 0;
	data.img_list->mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.relative_path, &(data.img_list->width), &(data.img_list->height));
	data.img_list->addr= mlx_get_data_addr(&(data.img_list), &data.img_list->bpp, &data.img_list->line_len, &data.img_list->endian);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
