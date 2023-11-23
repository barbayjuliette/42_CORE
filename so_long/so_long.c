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
void	get_window_size(t_mlx_data *data)
{
	data->win_height = IMAGE_SIZE * data->map_height;
	data->win_width = IMAGE_SIZE * data->map_width;
	data->moves = 0;
}

void	create_images(t_mlx_data *data)
{
	t_img *wall = malloc(sizeof(t_img));
	t_img *exit = malloc(sizeof(t_img));
	t_img *food = malloc(sizeof(t_img));
	t_img *player = malloc(sizeof(t_img));

	wall->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm", &(wall->width), &(wall->height));
	exit->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/exit.xpm", &(exit->width), &(exit->height));
	food->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/food.xpm", &(food->width), &(food->height));
	player->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/player.xpm", &(player->width), &(player->height));

	wall->addr = mlx_get_data_addr(wall->img_ptr, &(wall->bpp), &(wall->line_len), &(wall->endian));
	exit->addr = mlx_get_data_addr(exit->img_ptr, &(exit->bpp), &(exit->line_len), &(exit->endian));
	food->addr = mlx_get_data_addr(food->img_ptr, &(food->bpp), &(food->line_len), &(food->endian));
	player->addr = mlx_get_data_addr(player->img_ptr, &(player->bpp), &(player->line_len), &(player->endian));

	data->wall = wall;
	data->exit = exit;
	data->food = food;
	data->player = player;
}

void	build_map_screen(t_mlx_data *data)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			if (data->map[row][col] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, ((t_img *)data->wall)->img_ptr, col * IMAGE_SIZE, row * IMAGE_SIZE);
			if (data->map[row][col] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, ((t_img *)data->exit)->img_ptr, col * IMAGE_SIZE, row * IMAGE_SIZE);
			if (data->map[row][col] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, ((t_img *)data->food)->img_ptr, col * IMAGE_SIZE, row * IMAGE_SIZE);
			if (data->map[row][col] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, ((t_img *)data->player)->img_ptr, col * IMAGE_SIZE, row * IMAGE_SIZE);
			col++;
		}
		row++;
	}
	return ;
}

int main(int argc, char *argv[])
{
	t_mlx_data	program;

	if (get_map_and_validate(argc, argv, &program))
		return (0);
	ft_printf("HERE\n");
	program.mlx_ptr = mlx_init();
	if (!program.mlx_ptr)
		return (MALLOC_ERROR);
	ft_printf("HEREWWW\n");
	get_window_size(&program);
	program.win_ptr = mlx_new_window(program.mlx_ptr, program.win_width, program.win_height, "So_long");
	if (!program.win_ptr)
	{
		mlx_destroy_display(program.mlx_ptr);
		free(program.mlx_ptr);
		return (MALLOC_ERROR);
	}
	ft_printf("HEREXX\n");
	create_images(&program);
	ft_printf("HEREVV\n");
	build_map_screen(&program);
	ft_printf("HELLO\n");
	mlx_hook(program.win_ptr, 17, 0, exit_program, &program);
	ft_printf("AGAIN\n");
	mlx_key_hook(program.win_ptr, handle_input, &program);
	ft_printf("AGAIN2\n");
	mlx_loop(program.mlx_ptr);
	return 0;
}

