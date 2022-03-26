/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_sees_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:45:15 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 16:48:47 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	allocate_enemy(t_data *game)
{
	int	i;

	i = 0;
	game->enemy_x = (int *)malloc(sizeof(int) * game->count_enemy);
	game->enemy_y = (int *)malloc(sizeof(int) * game->count_enemy);
	game->e_curs = (char *)malloc(sizeof(char ) * game->count_enemy);
	game->death_see_player = (int *)malloc(sizeof(int ) * game->count_enemy);
	while (i < game->count_enemy)
	{
		game->death_see_player[i] = 0;
		game->e_curs[i] = 'r';
		i++;
	}
}

float	max_size(int x_size, int y_size)
{
	x_size = x_size * ((x_size > 0) * 2 - 1);
	y_size = y_size * ((y_size > 0) * 2 - 1);
	if (x_size > y_size)
		return (x_size);
	else
		return (y_size);
}

int	is_wall(float x_pix, float y_pix, t_data *game)
{
	int	x;
	int	y;

	x_pix = (int)x_pix;
	y_pix = (int)y_pix;
	x = x_pix / SPRITE_SIZE;
	y = y_pix / SPRITE_SIZE;
	if (game->map[y + 1][x + 1] == '1')
		return (1);
	return (0);
}

int	enemy_sees_the_player(t_data *game, int i)
{
	int			j;
	t_can_see	see;

	see.y_pix1 = (game->player_y - 1) * SPRITE_SIZE + SPRITE_SIZE / 2;
	see.x_pix1 = (game->player_x - 1) * SPRITE_SIZE + SPRITE_SIZE / 2;
	see.y_pix2 = (game->enemy_y[i] - 1) * SPRITE_SIZE + SPRITE_SIZE / 2;
	see.x_pix2 = (game->enemy_x[i] - 1) * SPRITE_SIZE + SPRITE_SIZE / 2;
	see.x_size = see.x_pix2 - see.x_pix1;
	see.y_size = see.y_pix2 - see.y_pix1;
	see.max = max_size(see.x_size, see.y_size);
	see.x_step = (float)see.x_size / (float)see.max;
	see.y_step = (float)see.y_size / (float)see.max;
	j = 0;
	while (j < see.max)
	{
		see.x_pix1 += see.x_step;
		see.y_pix1 += see.y_step;
		if (is_wall(see.x_pix1, see.y_pix1, game))
			return (0);
		j++;
	}
	return (1);
}

int	death_win(t_data *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->count_enemy)
	{
		if (game->player_y + y == game->enemy_y[i]
			&& game->player_x + x == game->enemy_x[i])
			return (1);
		i++;
	}
	return (0);
}
