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
	if (keysym == XK_Escape)
		exit_program(data);
	printf("Key %d has been pressed\n", keysym);
	return (0);
}

t_img	new_image(int width, int height, t_mlx_data window)
{
	t_img	image;

	image.window = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr,&(image.bpp), &(image.line_len), &(image.endian));
	image.width = width;
	image.height = height;

	// printf("Let's Find out what's inside our structure :D\n");
	// printf("img_ptr		: [%p]\n", image.img_ptr);
	// printf("bpp		: [%d]\n", image.bpp);
	// printf("line_len	: [%d]\n", image.line_len);
	// printf("endian		: [%d]\n", image.endian);
	// printf("addr		: [%p]\n", image.addr);

	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_square square, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < square.size && i + square.y < img.height)
	{
		j = 0;
		while (j < square.size && j + square.x < img.width)
		{
			put_pixel_img(img, j + square.x, i + square.y, square.color);
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	// void	*mlx_connection;
	// void	*window;
	t_mlx_data	program;
	t_img	first_image;

	if (get_map_and_validate(argc, argv))
		return (0);
	program.mlx_ptr = mlx_init();
	if (!program.mlx_ptr)
		return (MALLOC_ERROR);
	
	program.win_ptr = mlx_new_window(program.mlx_ptr, HEIGHT, WIDTH, "First window");
	if (!program.win_ptr)
	{
		mlx_destroy_display(program.mlx_ptr);
		free(program.mlx_ptr);
		return (MALLOC_ERROR);
	}

	// Exit when I click on X from window.
	mlx_hook(program.win_ptr, 17, 0, exit_program, &program);

	mlx_key_hook(program.win_ptr, handle_input, &program);
	// When a key is released the handle_input function will be called
	// mlx_key_hook function is an alias of mlx_hook on key up event (3)
	// 3 = ON_KEYUP. This is the prototype pf the function we have to use: int (*f)(int keycode, void *param)

	// Create image
	// first_image = new_image(300, 300, program);
	// put_pixel_img(first_image, 150, 150,  0x00FFFFFF);
	// mlx_put_image_to_window(first_image.window.mlx_ptr, first_image.window.win_ptr, first_image.img_ptr, 0, 0);


	// Draw square
	// t_square square = { 0, 0, 300, 0x00FF00};
	// draw_square(square, first_image);
	// mlx_put_image_to_window(first_image.window.mlx_ptr, first_image.window.win_ptr, first_image.img_ptr, 0, 0);
	first_image.img_ptr = mlx_xpm_file_to_image(program.mlx_ptr, "./assets/wall.xpm", &(first_image.width), &(first_image.height));
	mlx_put_image_to_window(program.mlx_ptr, program.win_ptr, first_image.img_ptr, 0, 0);

	mlx_loop(program.mlx_ptr);

	// mlx_destroy_display(program.mlx_ptr);
	// free(program.mlx_ptr);
	return 0;
}

