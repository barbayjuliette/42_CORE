/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:09:28 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/22 13:09:31 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_program(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, ((t_img *)data->exit)->img_ptr);
	mlx_destroy_image(data->mlx_ptr, ((t_img *)data->food)->img_ptr);
	mlx_destroy_image(data->mlx_ptr, ((t_img *)data->player)->img_ptr);
	mlx_destroy_image(data->mlx_ptr, ((t_img *)data->wall)->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	free_matrix(data->map);
	free(data->exit);
	free(data->food);
	free(data->player);
	free(data->wall);
	exit(0);
}

void	free_matrix(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		free(map[row]);
		row++;
	}
	free(map);
}

void	game_win(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data, 0, 0);
	ft_printf("Well done, you finished the game in %d moves.\n", data->moves);
	exit_program(data);
}

void	game_lost(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data, 0, 0);
	ft_printf("Game over\nYou forgot to get all collectibles.\n");
	exit_program(data);
}

void	update_map(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data, 0, 0);
	data->moves++;
	ft_printf("Number of moves: %d\n", data->moves);
}
