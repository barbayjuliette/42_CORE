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

int exit_program(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	game_win(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);
	printf("Well done, you finished the game in %d moves.\n", data->moves);
	exit_program(data);
}

void	game_lost(t_mlx_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);
	printf("Game over\nYou forgot to get all collectibles.\n");
	exit_program(data);
}
