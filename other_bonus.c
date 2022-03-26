/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjosua <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:57:21 by hjosua            #+#    #+#             */
/*   Updated: 2022/03/17 16:57:41 by hjosua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header_bonus.h"

int	close_window(void)
{
	exit(0);
}

void	ft_zeroing_fields(t_data *game)
{
	game->rows = 0;
	game->columns = 0;
	game->count_collect = 0;
	game->count_exits = 0;
	game->count_players = 0;
	game->count_steps = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->enemy_x = 0;
	game->enemy_y = 0;
	game->count_enemy = 0;
	game->curs = 'r';
}
