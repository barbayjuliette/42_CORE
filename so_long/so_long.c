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
#include <stdio.h>
#include <X11/keysym.h>


int exit_program(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	int	row;
	int	col;
	t_img *player = malloc(sizeof(t_img));

	row = data->position[0];
	col = data->position[1];
	if (keysym == XK_Escape)
		exit_program(data);
	if (keysym == UP)
	{
		// Check if row-1, col is not a wall
		if (data->map[row-1][col] == '1')
			return (1);
		printf("Total collectibles: %d\n", data->collectibles);
		// If row-1, col is a collectible, collectible--;
		if (data->map[row-1][col] == 'C')
			data->collectibles--;
		printf("Total collectibles: %d\n", data->collectibles);
		
		// // Remove player image
		// I have to clear the whole window and rebuild everything again. Clear all images first.
		// mlx_destroy_image(data->mlx_ptr, ((t_img *)data->player)->img_ptr);
		// free(data->player);
		// // Add player to row-1, col
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, ((t_img *)data->player)->img_ptr, col * IMAGE_SIZE, (row - 1) * IMAGE_SIZE);
		// player->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/player.xpm", &(player->width), &(player->height));
		// // Add to moves
		// data->moves++;
		// // If exit and collectibles == 0, end of game
		// // Update position in data
		// data->position[0] = row - 1;
		// printf("Number of moves: %d\n", data->moves);
	}
	// data->moves++;
	// printf("Key pressed: %d\n", keysym);
	return (0);
}

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

	wall->addr = mlx_get_data_addr(wall->img_ptr,&(wall->bpp), &(wall->line_len), &(wall->endian));
	exit->addr = mlx_get_data_addr(exit->img_ptr,&(exit->bpp), &(exit->line_len), &(exit->endian));
	food->addr = mlx_get_data_addr(food->img_ptr,&(food->bpp), &(food->line_len), &(food->endian));
	player->addr = mlx_get_data_addr(player->img_ptr,&(player->bpp), &(player->line_len), &(player->endian));

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
	program.mlx_ptr = mlx_init();
	if (!program.mlx_ptr)
		return (MALLOC_ERROR);
	
	get_window_size(&program);

	program.win_ptr = mlx_new_window(program.mlx_ptr, program.win_width, program.win_height, "So_long");
	if (!program.win_ptr)
	{
		mlx_destroy_display(program.mlx_ptr);
		free(program.mlx_ptr);
		return (MALLOC_ERROR);
	}
	// Create map
	create_images(&program);
	build_map_screen(&program);
	printf("Collectibles: %d\n", program.collectibles);
	printf("Position player row: %d\n", program.position[0]);
	printf("Position player col: %d\n", program.position[1]);
	// Exit with X and ESC + Key hook
	mlx_hook(program.win_ptr, 17, 0, exit_program, &program);
	mlx_key_hook(program.win_ptr, handle_input, &program);

	mlx_loop(program.mlx_ptr);
	return 0;
}

