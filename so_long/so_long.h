/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:40:21 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/16 12:40:24 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE  1
#define HEIGHT 400
#define WIDTH 400
#define MALLOC_ERROR 1

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

typedef struct s_img
{
	t_mlx_data	window;
	void		*img_ptr;
	char		*addr;
	int			height;
	int			width;
	int			bpp;
	int			endian;
	int			line_len;
}	t_img;

typedef struct s_square {
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int					color;
}		t_square;

int get_map_and_validate(int argc, char *argv[]);
int	map_validation(char *map);
int	check_characters(char *map);
int	count_char_map(int *exit, int *start, int *collectible, char *map);
int	get_width(char *map);
int	is_rectangle(char *map, int width);
int	get_height(char *map);
int	ft_strlen(const char *string);
void	ft_strjoin(char **map, char *buffer, int i, int j);
void	ft_putstr(char *s);
char	**populate_input_matrix(int height, int width, char *buff, int j);
char	**create_matrix(int height);
void print_matrix(char **matrix, int rows, int cols);
int	check_walls(char **matrix, int height, int width);
