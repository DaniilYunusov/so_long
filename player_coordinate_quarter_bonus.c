/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coordinate_quarter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:58:04 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 16:58:22 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

void	first_coordinate_quarter(t_data *game, int i)
{
	if (game->player_x - game->enemy_x[i] >= game->player_y - game->enemy_y[i])
		game->enemy_x[i]++;
	else
		game->enemy_y[i]--;
	game->e_curs[i] = 'r';
}

void	second_coordinate_quarter(t_data *game, int i)
{
	if (game->player_x - game->enemy_x[i] >= game->player_y - game->enemy_y[i])
		game->enemy_x[i]--;
	else
		game->enemy_y[i]--;
	game->e_curs[i] = 'l';
}

void	third_coordinate_quarter(t_data *game, int i)
{
	if (game->player_x - game->enemy_x[i] >= game->player_y - game->enemy_y[i])
		game->enemy_x[i]--;
	else
		game->enemy_y[i]++;
	game->e_curs[i] = 'l';
}

void	fourth_coordinate_quarter(t_data *game, int i)
{
	if (game->player_x - game->enemy_x[i] >= game->player_y - game->enemy_y[i])
		game->enemy_x[i]++;
	else
		game->enemy_y[i]++;
	game->e_curs[i] = 'r';
}
