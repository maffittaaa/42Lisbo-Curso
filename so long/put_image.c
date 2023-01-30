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

void	img_put(t_img *img, int x, int y)
{
	t_data data;

	data.img1 = img->addr + (y * img->line_len + x * (img->bpp / 8));
	data.img2 = img->addr + (y * img->line_len + x * (img->bpp / 8));
}

int render_img(t_img *img, t_cords cords)
{
	int i;
	int j;

	i = cords.y;
	while (i < cords.y + cords.height)
	{
		j = cords.x;
		while (i < cords.x + cords.width)
			img_put(img, ++j, i);
		i++;
	}
	return (0);
}

int render(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
	render_img(&data->img1, (t_cords){.......})
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_list->mlx_img, data->img_list->x, data->img_list->y);
	if(data->img_list->x == 0)
		return (0);
	return(0);
}

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window (data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(0);
	}

	if (keysym == right && data->img_list->x < WINDOW_WIDTH - data->img_list->width)
		data->img_list->x += 25;
	if (keysym == left && data->img_list->x > 0)
		data->img_list->x -= 25;
	if (keysym == down && data->img_list->y < WINDOW_HEIGHT - data->img_list->height)
		data->img_list->y += 25;
	if (keysym == up && data->img_list->y > 0)
		data->img_list->y -= 25;
	printf("Keypress: %d\n", keysym);return (0);
	return (0);
}

int main(void)
{
	t_data	data;
	int		i;

	data.img1 = ft_strdup("images/SHREKdireita.xpm");
	data.img2 = ft_strdup("images/SHREKesquerdo.xpm");
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

	data.img_list=malloc(2 * sizeof(t_img));
	//data.img_list[2] = 0;
	i = 0;
	while(i < 2)
	{
		data.img_list[i].width = 200;
		data.img_list[i].height = 200;
		data.img_list[i].x = 0;
		data.img_list[i].y = 0;
		data.img_list[i].mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img1, &(data.img_list->width), &(data.img_list->height));
		data.img_list->addr= mlx_get_data_addr(&(data.img_list), &data.img_list->bpp, &data.img_list->line_len, &data.img_list->endian);
		i++;
	}

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
