/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:03:50 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 17:10:11 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_BONUS_H
# define SO_LONG_HEADER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"
# define TRUE 1
# define FALSE 0
# define SPRITE_SIZE 64
# define NAME "./so_long"

typedef struct s_maps {
	char	*map_ber[5];
	char	*args[3];
	int		pid;
	int		status;
	int		i;
}				t_map_ber;

typedef struct s_img {
	void	*addr;
	int		width;
	int		height;
}				t_img;

typedef struct s_can_see {
	float	y_pix1;
	float	x_pix1;
	float	y_pix2;
	float	x_pix2;
	int		x_size;
	int		y_size;
	int		max;
	float	x_step;
	float	y_step;
}				t_can_see;

typedef struct s_data {
	char	*file_name;
	char	curs;
	char	*e_curs;
	void	*mlx;
	void	*win;
	int		rows;
	int		columns;
	int		player_x;
	int		player_y;
	int		*enemy_x;
	int		*enemy_y;
	int		count_collect;
	int		count_players;
	int		count_enemy;
	int		count_exits;
	int		count_steps;
	int		*death_see_player;
	char	**map;
	t_img	empty;
	t_img	player_right[8];
	t_img	player_left[8];
	t_img	enemy_right[8];
	t_img	enemy_left[8];
	t_img	wall;
	t_img	enemy;
	t_img	collect[6];
	t_img	exit_open;
	t_img	exit_close;
}						t_data;

int		ft_check_extension(char *map_file);
void	ft_errors_processing(int argc, char **argv);
void	ft_invalid_fd(int fd);
void	ft_check_for_squareness(char **mass_of_strings);
int		ft_num_of_lines_in_file(char **argv);
char	*ft_create_string_in_map_array(char *string);
void	ft_check_for_valid_map(int strings_count);
int		ft_check_str_for_only_line_break(char *string);
char	**ft_create_map_array(char **argv);
void	ft_check_for_closed_map(char **map, char **argv, t_data *game);
void	ft_error_presence_elem_in_map(void);
void	ft_zeroing_fields(t_data *game);
void	ft_check_presence_of_elem_in_map(char **map, t_data *game);
void	ft_check_incorrect_symbols(char **map);
void	set_pos_player(t_data *game);
char	**ft_map_parsing(char **argv, t_data *game);
void	entering_files(t_data *game, t_img *img, char *path);
void	get_sprites(t_data *game);
void	show_collects(t_data *game, char symb, int x, int y);
int		show_sprite(t_data *game, char symb, int x, int y);
int		show_map(t_data *game);
void	set_collect_symbols(char **map);
int		close_window(void);
void	player_move(int x, int y, t_data *game);
void	player_move1(int x, int y, t_data *game);
void	player_move2(int x, int y, t_data *game);
int		key_press_react(int key, t_data *game);
void	display_player_enemy(t_data *game);
int		beginning_game(int argc, char **argv);
void	get_sprites_not_incoming(t_data *game);
void	show_steps_level_counter(t_data *game);
void	show_level_counter(t_data *game);
int		death_win(t_data *game, int x, int y);
void	enemy_move(t_data *game, int x, int y);
void	first_coordinate_quarter(t_data *game, int i);
void	second_coordinate_quarter(t_data *game, int i);
void	third_coordinate_quarter(t_data *game, int i);
void	fourth_coordinate_quarter(t_data *game, int i);
int		enemy_sees_the_player(t_data *game, int i);
void	on_one_column(t_data *game, int y, int i);
void	on_the_same_line(t_data *game, int x, int i);
void	player_pos_relative_to_enemy(t_data *game, int x, int y, int i);
void	allocate_enemy(t_data *game);
int		is_wall(float x_pix, float y_pix, t_data *game);
float	max_size(int x_size, int y_size);

#endif
