/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:39:42 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/16 12:39:46 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to create data struct
void	create_mlx_data(t_mlx_data *data, char *map)
{
	data->map_width = get_width(map);
	data->map_height = get_height(map);
	data->map = ft_split(map, '\n');
	get_position_player(data);
	data->win_height = IMAGE_SIZE * data->map_height;
	data->win_width = IMAGE_SIZE * data->map_width;
	data->moves = 0;
}

void	create_images(t_mlx_data *data)
{
	t_img	*wall;
	t_img	*exit;
	t_img	*food;
	t_img	*player;

	wall = malloc(sizeof(t_img));
	exit = malloc(sizeof(t_img));
	food = malloc(sizeof(t_img));
	player = malloc(sizeof(t_img));
	wall->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm",
			&(wall->width), &(wall->height));
	exit->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/exit.xpm",
			&(exit->width), &(exit->height));
	food->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/food.xpm",
			&(food->width), &(food->height));
	player->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, 
			"./assets/player.xpm", &(player->width), &(player->height));
	data->wall = wall;
	data->exit = exit;
	data->food = food;
	data->player = player;
}

void	display_image(t_mlx_data *data, int row, int col)
{
	int	x;
	int	y;

	x = col * IMAGE_SIZE;
	y = row * IMAGE_SIZE;
	if (data->map[row][col] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			((t_img *)data->wall)->img_ptr, x, y);
	if (data->map[row][col] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			((t_img *)data->exit)->img_ptr, x, y);
	if (data->map[row][col] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			((t_img *)data->food)->img_ptr, x, y);
	if (data->map[row][col] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
			((t_img *)data->player)->img_ptr, x, y);
}

void	build_map_screen(t_mlx_data *data, int row, int col)
{
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			display_image(data, row, col);
			col++;
		}
		row++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_mlx_data	data;

	if (get_map_and_validate(argc, argv, &data))
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, 
			data.win_height, "So_long");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MALLOC_ERROR);
	}
	create_images(&data);
	build_map_screen(&data, 0, 0);
	mlx_hook(data.win_ptr, 17, 0, exit_program, &data);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
