/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:22:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/28 17:07:22 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_hook(t_data *data)
{
	ft_error(data, "Exiting from input", 0);
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		ft_error(data, "Exiting from input", 0);
	if (keycode == KEY_W)
		data->up_pressed = true;
	if (keycode == KEY_A)
		data->left_pressed = true;
	if (keycode == KEY_S)
		data->down_pressed = true;
	if (keycode == KEY_D)
		data->right_pressed = true;
	if (keycode == ARROW_LEFT)
		data->left_rotate_pressed = true;
	if (keycode == ARROW_RIGHT)
		data->right_rotate_pressed = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->up_pressed = false;
	if (keycode == KEY_A)
		data->left_pressed = false;
	if (keycode == KEY_S)
		data->down_pressed = false;
	if (keycode == KEY_D)
		data->right_pressed = false;
	if (keycode == ARROW_LEFT)
		data->left_rotate_pressed = false;
	if (keycode == ARROW_RIGHT)
		data->right_rotate_pressed = false;
	return (0);
}

void	load_textures_images(t_data *data)
{
	int	tex_height;
	int	tex_width ;
	int	i;

	i = 0;
	tex_height = SCREEN_HEIGHT;
	tex_width = SCREEN_WIDTH;
	while (i < 4)
	{
		printf("allocing ptr[%d]\n", i);
		data->textures_ptr[i] = mlx_xpm_file_to_image(data->mlx, \
			data->textures_path[i], &tex_width, &tex_height);
		if (!data->textures_ptr[i])
		{
			printf("failled to alloc  %d\n", i);
			ft_error(data, "Failed to load texture image", 1);
		}
		i++;
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	load_textures_images(data);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->mlx || !data->win)
		ft_error(data, "Failed to initialise MLX", 1);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
}
