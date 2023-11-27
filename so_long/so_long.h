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
#include <X11/keysym.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

#define BUFFER_SIZE 1
#define IMAGE_SIZE 32
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
	int		pos_exit[2];
}	t_mlx_data;

typedef struct s_img
{
	t_mlx_data	window;
	void		*img_ptr;
	int			height;
	int			width;
}	t_img;

void	create_mlx_data(t_mlx_data *data, char *map);
void	create_images(t_mlx_data *data);
void	display_image(t_mlx_data *data, int row, int col);
void	build_map_screen(t_mlx_data *data, int row, int col);
int		handle_input(int keysym, t_mlx_data *data);
int		move_up(t_mlx_data *data, int row, int col);
int		move_down(t_mlx_data *data, int row, int col);
int		move_right(t_mlx_data *data, int row, int col);
int		move_left(t_mlx_data *data, int row, int col);
int		exit_program(t_mlx_data *data);
void	free_matrix(char **map);
void	game_lost(t_mlx_data *data);
void	game_win(t_mlx_data *data);
void	update_map(t_mlx_data *data);
int		get_map_and_validate(int argc, char *argv[], t_mlx_data *data);
void	read_file(char **map, char *filename);
void	call_check_walls(t_mlx_data *data);
void	error_file(char *buffer, char *map, char *message);
void	get_position_player(t_mlx_data *data);
int		ft_strjoin_2(char **map, char *buffer, int i, int j);
void	ft_putstr(char *s);
int		get_width(char *map);
int		get_height(char *map);
int		is_rectangle(char *map, int width);
int		check_characters(char *map, t_mlx_data *data);
int		count_char_map(int *exit, int *start, int *collectible, char *map);
int		map_validation_1(char *map, t_mlx_data *data, char *filename);
void	flood_fill(char **map, int row, int col);
int		valid_path(char **flood, t_mlx_data *data);
int		check_walls(char **matrix, int height, int width);
void	call_valid_path(char *map, t_mlx_data *data);
int		check_ber_file(char *filename);
int		check_walls(char **matrix, int height, int width);
