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
#define	IMAGE_SIZE 32
#define MALLOC_ERROR 1
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		map_height;
	int		map_width;
	int		win_height;
	int		win_width;
	void	*exit;
	void	*food;
	void	*player;
	void	*wall;
	int		moves;
	int		collectibles;
	int		position[2];
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

int 	get_map_and_validate(int argc, char *argv[], t_mlx_data *data);
int	map_validation(char *map, t_mlx_data *data);
int	check_characters(char *map, t_mlx_data *data);
int		count_char_map(int *exit, int *start, int *collectible, char *map);
int		get_width(char *map);
int		is_rectangle(char *map, int width);
int		get_height(char *map);
int		ft_strlen(const char *string);
void	ft_strjoin(char **map, char *buffer, int i, int j);
void	ft_putstr(char *s);
char	**populate_input_matrix(t_mlx_data *data, char *buff, int j);
char	**create_matrix(int height);
void 	print_matrix(char **matrix, int rows, int cols);
int		check_walls(char **matrix, int height, int width);
void	build_map_screen(t_mlx_data *data);