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


int exit_program(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	handle_input(int keycode, t_mlx_data *data)
{
	if (keycode == 65307)
		exit_program(data);
	printf("Key %d has been pressed\n", keycode);
	return (0);
}

int main(void)
{
	// void	*mlx_connection;
	// void	*window;
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MALLOC_ERROR);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "First window");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (MALLOC_ERROR);
	}

	// Exit when I click on X from window.
	mlx_hook(data.win_ptr, 17, 0, exit_program, &data);

	mlx_key_hook(data.win_ptr, handle_input, &data);
	// When a key is released the handle_input function will be called
	// mlx_key_hook function is an alias of mlx_hook on key up event (3)
	// 3 = ON_KEYUP. This is the prototype pf the function we have to use: int (*f)(int keycode, void *param)

	mlx_loop(data.mlx_ptr);

	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
	return 0;
}

