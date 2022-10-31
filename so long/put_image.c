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
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, data->img.x, data->img.y);
	//if (data->img.x
		//mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
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
	if (keysym == 65363 && data->img.x < WINDOW_WIDTH - data->img.width)
		data->img.x += 25;
	if (keysym == 65361 && data->img.x > 0)
		data->img.x -= 25;
	if (keysym == 65364 && data->img.y < WINDOW_HEIGHT - data->img.height)
		data->img.y += 25;
	if (keysym == 65362 && data->img.y > 0)
		data->img.y -= 25;
	printf("Keypress: %d\n", keysym);return (0);
	return (0);
}

int main(void)
{
	t_data data;

	data.relative_path = ft_strdup("images/teapot.xpm");
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
	data.img.width = 200;
	data.img.height = 200;
	data.img.x = 0;
	data.img.y = 0;
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.relative_path, &(data.img.width), &(data.img.height));

	data.img.addr= mlx_get_data_addr(&(data.img), &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
