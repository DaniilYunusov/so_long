/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:08:12 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/12 21:17:11 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

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

typedef struct s_img {
	void	*addr;
	int		width;
	int		height;
}					t_img;

typedef struct s_data {
	char	curs;
	void	*mlx;
	void	*win;
	int		rows;
	int		columns;
	int		player_x;
	int		player_y;
	int		count_collect;
	int		count_players;
	int		count_exits;
	int		count_steps;
	char	**map;
	t_img	empty;
	t_img	player_right;
	t_img	player_left;
	t_img	wall;
	t_img	enemy;
	t_img	collect[6];
	t_img	exit_open;
	t_img	exit_close;
}				t_data;

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
int		key_press_react(int key, t_data *game);

#endif
