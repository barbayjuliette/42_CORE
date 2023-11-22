/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:09:16 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/22 13:09:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	int	row;
	int	col;

	row = data->position[0];
	col = data->position[1];
	if (keysym == XK_Escape)
	{
		printf("Giving up so fast?");
		exit_program(data);
	}
	if (keysym == UP)
		move_up(data, row, col);
	else if (keysym == DOWN)
		move_down(data, row, col);
	if (keysym == RIGHT)
		move_right(data, row, col);
	if (keysym == LEFT)
		move_left(data, row, col);
	return (0);
}

int	move_up(t_mlx_data	*data, int row, int col)
{
	if (data->map[row - 1][col] == '1')
		return (0);

	if (data->map[row - 1][col] == 'C')
		data->collectibles--;
	
	data->map[row][col] = '0';
	if (data->map[row - 1][col] == 'E' && data->collectibles == 0)
	{
		data->map[row - 1][col] = 'P';
		game_win(data);
	}
	if (data->map[row - 1][col] == 'E' && data->collectibles == 0)
	{
		data->map[row - 1][col] = 'P';
		game_lost(data);
	}
	data->map[row - 1][col] = 'P';
	data->position[0] = row - 1;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);
	data->moves++;
	printf("Number of moves: %d\n", data->moves);
	return (1);
}

int	move_down(t_mlx_data *data, int row, int col)
{
	if (data->map[row + 1][col] == '1')
		return (0);

	if (data->map[row + 1][col] == 'C')
		data->collectibles--;

	data->map[row][col] = '0';
	if (data->map[row + 1][col] == 'E' && data->collectibles == 0)
	{
		data->map[row + 1][col] = 'P';
		game_win(data);
	}
	if (data->map[row + 1][col] == 'E' && data->collectibles != 0)
	{
		data->map[row + 1][col] = 'P';
		game_lost(data);
	}

	data->map[row + 1][col] = 'P';
	data->position[0] = row + 1;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);

	data->moves++;

	printf("Number of moves: %d\n", data->moves);
	return (1);
}

int	move_right(t_mlx_data *data, int row, int col)
{
	if (data->map[row][col + 1] == '1')
		return (0);

	if (data->map[row][col + 1] == 'C')
		data->collectibles--;

	data->map[row][col] = '0';
	if (data->map[row][col + 1] == 'E' && data->collectibles == 0)
	{
		data->map[row][col + 1] = 'P';
		game_win(data);
	}
	if (data->map[row][col + 1] == 'E' && data->collectibles == 0)
	{
		data->map[row][col + 1] = 'P';
		game_lost(data);
	}
	data->map[row][col + 1] = 'P';
	data->position[1] = col + 1;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);

	data->moves++;

	printf("Number of moves: %d\n", data->moves);
	return (1);
}

int	move_left(t_mlx_data *data, int row, int col)
{
	if (data->map[row][col - 1] == '1')
		return (0);

	if (data->map[row][col - 1] == 'C')
		data->collectibles--;

	data->map[row][col] = '0';
	if (data->map[row][col - 1] == 'E' && data->collectibles == 0)
	{
		data->map[row][col - 1] = 'P';
		game_win(data);
	}
	if (data->map[row][col - 1] == 'E' && data->collectibles != 0)
	{
		data->map[row][col - 1] = 'P';
		game_lost(data);
	}
	data->map[row][col - 1] = 'P';
	data->position[1] = col - 1;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	build_map_screen(data);

	data->moves++;
	printf("Number of moves: %d\n", data->moves);
	return (1);
}
