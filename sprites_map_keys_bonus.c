/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_map_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:10:28 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 17:16:52 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	entering_files(t_data *game, t_img *img, char *path)
{
	img->addr = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (img->addr == NULL)
	{
		write(1, "Failed to upload sprite!\n", 25);
		exit(0);
	}
}

void	display_player_enemy(t_data *game)
{
	static int	frame = 0;
	int			i;

	i = 0;
	if (game->curs == 'r')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_right[frame++ / 8 % 8].addr,
			game->player_x * SPRITE_SIZE, game->player_y * SPRITE_SIZE);
	else
		mlx_put_image_to_window(game->mlx,
			game->win, game->player_left[frame++ / 8 % 8].addr,
			game->player_x * SPRITE_SIZE, game->player_y * SPRITE_SIZE);
	show_steps_level_counter(game);
	while (i < game->count_enemy)
	{
		if (game->e_curs[i] == 'r')
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_right[frame / 8 % 8].addr,
				game->enemy_x[i] * SPRITE_SIZE, game->enemy_y[i] * SPRITE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy_left[frame / 8 % 8].addr,
				game->enemy_x[i] * SPRITE_SIZE, game->enemy_y[i] * SPRITE_SIZE);
		i++;
	}
}

int	show_map(t_data *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->empty.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
			show_sprite(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	display_player_enemy(game);
	return (1);
}

int	key_press_react(int key, t_data *game)
{
	if (key == 53)
		close_window();
	if (key == 0)
	{
		player_move(-1, 0, game);
		game->curs = 'l';
	}
	if (key == 2)
	{
		player_move(1, 0, game);
		game->curs = 'r';
	}
	if (key == 1)
		player_move(0, 1, game);
	if (key == 13)
		player_move(0, -1, game);
	return (1);
}
