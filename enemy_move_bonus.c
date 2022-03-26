/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:49:00 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/26 20:33:08 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	on_one_column(t_data *game, int y, int i)
{
	if (game->player_y + y >= game->enemy_y[i])
	{
		if (game->player_y + y != game->enemy_y[i])
			game->enemy_y[i]++;
	}
	else
	{
		if (game->player_y + y != game->enemy_y[i])
			game->enemy_y[i]--;
	}
}

void	on_the_same_line(t_data *game, int x, int i)
{
	if (game->player_x + x >= game->enemy_x[i])
	{
		game->e_curs[i] = 'r';
		game->enemy_x[i]++;
	}
	else
	{
		game->e_curs[i] = 'l';
		game->enemy_x[i]--;
	}
}

void	player_pos_relative_to_enemy(t_data *game, int x, int y, int i)
{
	if (game->map[game->player_y + y][game->player_x + x] != '1')
	{
		if (game->player_x + x == game->enemy_x[i])
			on_one_column(game, y, i);
		else if (game->player_y + y == game->enemy_y[i])
			on_the_same_line(game, x, i);
		else if (game->player_x + x >= game->enemy_x[i]
			&& game->player_y + y >= game->enemy_y[i])
			fourth_coordinate_quarter(game, i);
		else if (game->player_x + x < game->enemy_x[i]
			&& game->player_y + y < game->enemy_y[i])
			second_coordinate_quarter(game, i);
		else if (game->player_x + x >= game->enemy_x[i]
			&& game->player_y + y < game->enemy_y[i])
			first_coordinate_quarter(game, i);
		else if (game->player_x + x < game->enemy_x[i]
			&& game->player_y + y >= game->enemy_y[i])
			third_coordinate_quarter(game, i);
	}
}

void	enemy_move(t_data *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->count_enemy)
	{
		if (!enemy_sees_the_player(game, i) && game->death_see_player[i] == 0)
		{
			i++;
			continue ;
		}
		game->death_see_player[i] = 1;
		player_pos_relative_to_enemy(game, x, y, i);
		i++;
	}
}
