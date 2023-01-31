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
	t_img img;

	img.position.x = 0;
	img.position.y = 0;

    if (data->win_ptr == NULL)
        return (1);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_list->mlx_img, img.position.x, img.position.y);
	if(img.position.x == 0)
		return (0);
	return(0);
}

int handle_keypress(int keysym, t_data *data)
{
	t_img img;

	img.position.x = 0;
	img.position.y = 0;

	if (keysym == XK_Escape)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}

	if (keysym == right && img.position.x < WINDOW_WIDTH - data->img_list->width)
		img.position.x += 25;
	if (keysym == left && img.position.x > 0)
		img.position.x -= 25;
	if (keysym == down && img.position.y < WINDOW_HEIGHT - data->img_list->height)
		img.position.y += 25;
	if (keysym == up && img.position.y > 0)
		img.position.y -= 25;
	printf("Keypress: %d\n", keysym);
	return (0);
}



int main(void)
{
	t_data	data;
	t_img	img;
	int		i;

	data.img1 = ft_strdup("images/wall1.xpm");
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

	data.img_list = malloc((5) * sizeof(t_img));
	i = 0;
	while(i < 5)
	{
		img.position.x = 0;
		img.position.y = 0;
		data.img_list[i].mlx_img = mlx_new_image(data.mlx_ptr, data.img_list->width, data.img_list->height);
		data.img_list[i].addr = mlx_get_data_addr(&(data.img_list), &data.img_list->bpp, &data.img_list->line_len, &data.img_list->endian);
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_list->mlx_img, img.position.x, img.position.y);
		mlx_destroy_image(data.mlx_ptr, data.img_list);
		mlx_loop(data.mlx_ptr);
		i++;
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
